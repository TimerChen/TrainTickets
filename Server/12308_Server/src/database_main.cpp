#include "include/database.h"
#include "include/database_main.h"

#include "include/exceptions.hpp"

#include <QFile>
#include <QTextStream>

#include <QTest>

DataBase_Main::DataBase_Main( const QString &Name )
:DataBase_Base(Name)
{
	dAccount = new DataBase_Account(Name);
	dUser = new DataBase_User(Name);
	dUser->add_acc(dAccount);
	dTrain = new DataBase_Train(Name);
	dLog = new DataBase_Log(Name);
	loadData();
}

DataBase_Main::~DataBase_Main()
{

}

ttd::normal_ptr<ttd::vector<QString> > DataBase_Main::getLog()
{ return &(dLog->log); }

/*Unfinished*/
void DataBase_Main::loadData_raw_buy( const QString &FileName )
{
	dLog->any("Start load raw-buy-data.");
	QFile file(FileName);	//file
	if (!file.open(QFile::ReadOnly|QFile::Text))	throw(0);//open failed
	QTextStream in(&file);

	int total = 0;
	int num;
	QString name, id, traId;
	QString sta, stb, type;
	QString bor, tmp;	QDate day;
	while (!in.atEnd())
	{
		total++;
		in>>name>>id;
		if(name.isNull())break;

		in>>bor>>num;
		in>>type;
		in>>tmp>>tmp>>traId;
		in>>tmp>>sta;
		in>>tmp>>stb;
		in>>tmp>>tmp;
		//qDebug() << total << name << id << bor;
		if(total % 10000 == 0)
			qDebug() << total;
		day = QDate::fromString(tmp,"yyyy-M-d");
		regist(id,QString("000000"),name);
		if (bor == "bought")	buyTickets(0,id,traId,day,sta,stb,type,num);	//  of the two functions
		else	returnTickets(0,id,traId,day,sta,stb,type,num);
	}
	dLog->any("Finished load raw-buy-data.");
	//unrepeated user: 484468(means 484468 accounts)
}
void DataBase_Main::loadData_raw_train(const QString &FileName)
{
	dLog->any("Start load raw-train-data.");
	dTrain->loadData_raw(FileName);
	dLog->any("Finished load raw-buy-data.");
}

void DataBase_Main::loadData()
{
	//qDebug() << QTime::currentTime().toString( "h-m-s");
	dLog->loadData();
	//dLog->any("Datab");
	dLog->any("Database Account Loading...");
	dAccount->loadData();
	dLog->any("Database User Loading...");
	dUser->loadData();
	dLog->any("Database Train Loading...");
	dTrain->loadData();

}
void DataBase_Main::saveData()
{
	dAccount->saveData();
	dUser->saveData();
	dTrain->saveData();
	dLog->saveData();
}


//Database_User
int DataBase_Main::regist( const QString &Id, const QString &pwd, const QString &name )
{
	dLog->newAccount( Id, name );
	return dAccount->Register(
				DataBase_Account::Account(Id,name),
				pwd);

}

ttd::pair<int,QString> DataBase_Main::login
( const QString &ID, const QString &password )
{ return dLog->login
			( ID, password, dUser->login( ID, password ) ); }

bool DataBase_Main::logout( int UserId )
{
	return dLog->logout( UserId, dUser->logout(UserId) );
}

void DataBase_Main::newConnection( const QString &Ip )
{ dLog->newConnection(Ip); }

void DataBase_Main::disconnect(const int &Userid)
{ dLog->disconnect(Userid); }

//Database_Account
DataBase_Account::Account DataBase_Main::queryAccount
	(const int &UserId, QString ID)
{
	int id = dAccount->getIdNumber(ID);
	if(dUser->account_id(UserId) != id &&
			!dUser->is_admin(UserId))
		throw ttd::no_authority();

	DataBase_Account::Account acc = dAccount->queryAccount(id);
	dLog->questAcc( UserId, acc.name , acc.id );
	return acc;

}
void DataBase_Main::modifyAccount
	( const int &UserId, const int &Id,
	  const QString &newPassword, const QString &newName)
{
	int id = Id;
	if(dUser->account_id(UserId) != id &&
			!dUser->is_admin(UserId))
		throw ttd::no_authority();

	dAccount->modifyAccount(Id, newPassword, newName);
	dLog->modifyAccount( UserId, id );
	return;
}
ttd::map<DataBase_Account::Ticket,int> DataBase_Main::ownedTicket
	(const int &UserId, const QString &Id)
{
	int id = dAccount->getIdNumber(Id);
	if(dUser->account_id(UserId) != id &&
			!dUser->is_admin(UserId))
		throw ttd::no_authority();
	ttd::map<DataBase_Account::Ticket,int> tmp
		= dAccount->ownedTicket(id);
	dLog->questTic( UserId, id );
	return tmp;
}
//Database_Train

void DataBase_Main::buyTickets
	(const int &UserId, const QString &accId,
	const QString &traId, const QDate &dat,
	const QString &lsta, const QString &ulsta,
	const QString &set, const int &num)
{
	if(UserId <0)
		throw ttd::no_authority();

	int id = dAccount->getIdNumber(accId);

	if(dUser->account_id(UserId) != id &&
			!dUser->is_admin(UserId))
		throw ttd::no_authority();

	QDateTime st,et;
	st = dTrain->getLeaveTime(traId, lsta);
	et = dTrain->getReachTime(traId, ulsta);
	int price;
	price = dTrain->buyTickets(traId,dat,lsta,ulsta,set,num);
	int stt,ett;
	stt = st.date().day() - 1;
	ett = et.date().day() - 1;
	st.setDate(dat);
	et.setDate(dat);
	st.addDays(stt);
	et.addDays(ett);
	dAccount->buyTicket(id, traId, lsta, ulsta, st, et, price, set, num);

	dLog->buyTicket(UserId, accId, traId, dat, lsta, ulsta, set, num);
}

void DataBase_Main::returnTickets
	(const int &UserId, const QString &accId,
	const QString &traId, const QDate &dat,
	const QString &lsta, const QString &ulsta,
	const QString &set, const int &num)
{
	if(UserId <0)
		throw ttd::no_authority();

	int id = dAccount->getIdNumber(accId);

	if(dUser->account_id(UserId) != id &&
			!dUser->is_admin(UserId))
		throw ttd::no_authority();

	QDateTime st,et;
	st = dTrain->getLeaveTime(traId, lsta);
	et = dTrain->getReachTime(traId, ulsta);
	int price;
	price = dTrain->cancelTickets(traId,dat,lsta,ulsta,set,num);
	int stt,ett;
	stt = st.date().day() - 1;
	ett = et.date().day() - 1;
	st.setDate(dat);
	et.setDate(dat);
	st.addDays(stt);
	et.addDays(ett);
	dAccount->returnTicket(id, traId, lsta, ulsta, st, et, price, set, num);

	dLog->returnTicket(UserId, accId, traId, dat, lsta, ulsta, set, num);
}

ttd::vector<DataBase_Train::TrainRoute> DataBase_Main::query_station(const int &UserId, QString Station)
{
	ttd::vector<DataBase_Train::TrainRoute> tmp
		= dTrain->queryOne(Station);
	dLog->questOne(UserId,Station);
	return tmp;
}

ttd::vector<DataBase_Train::QTrain> DataBase_Main::query_stationToStation
( const int &UserId,
  QDate dat, QString lsta, QString ulsta)
{
	ttd::vector<DataBase_Train::QTrain> tmp
		= dTrain->queryTwo(dat,lsta,ulsta);
	dLog->questTwo(UserId, dat, lsta, ulsta);
	return tmp;
}

DataBase_Train::TrainRoute DataBase_Main::query_train
(const int &UserId, QString tra)
{
	DataBase_Train::TrainRoute tmp
		= dTrain->query_train(tra);
	dLog->questTrain(UserId, tra);
	return tmp;
}

//Database_Log
void DataBase_Main::addLog( const QString &content)
{
	dLog->any( content );
}
