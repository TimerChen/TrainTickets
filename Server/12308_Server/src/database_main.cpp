#include "include/database.h"
#include "include/database_main.h"



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

void DataBase_Main::addLog( const QString &content)
{
	dLog->any( content );
}

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
