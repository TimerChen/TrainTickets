#include "include/database.h"
#include "include/database_main.h"

#include "include/exceptions.hpp"

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
void DataBase_Main::loadData_raw( const QString &FileName )
{

}

void DataBase_Main::loadData()
{
	dAccount->loadData();
	dUser->loadData();
	dTrain->loadData();
	dLog->loadData();
}
void DataBase_Main::saveData()
{
	dAccount->saveData();
	dUser->saveData();
	dTrain->saveData();
	dLog->saveData();
}


//Database_User
int DataBase_Main::regist( QString name, QString pwd )
{
	dLog->newAccount( name, pwd );
	return dAccount->Register(
				DataBase_Account::Account(name),
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
	(const int &UserId, const int &Id)
{
	int id = Id;
	if(dUser->account_id(UserId) != id &&
			!dUser->is_admin(UserId))
		throw ttd::no_authority();
	ttd::map<DataBase_Account::Ticket,int> tmp
		= dAccount->ownedTicket(id);
	dLog->questTic( UserId, id );
	return tmp;
}
//Database_Train

int DataBase_Main::buyTickets
(const int &UserId, QString traId,
 QDate dat, QString lsta, QString ulsta,
 QString set, int num)
{
	if(UserId <=0)
		throw ttd::no_authority();
	int tmp
			= dTrain->buyTickets(traId,dat,lsta,ulsta,set,num);
	dLog->buyTicket(UserId, traId, dat, lsta, ulsta, set, num);
	return tmp;
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
