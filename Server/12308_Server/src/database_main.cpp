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
	/*
	dblog = new DataBase_Log(Name);
	dbaccount = new DataBase_Account(Name);
	dbuser = new DataBase_User(Name);
	dbtrain = new DataBase_Train(Name);*/
	loadData();
}

DataBase_Main::~DataBase_Main()
{

}
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


int DataBase_Main::regist( QString name, QString pwd )
{

}

ttd::pair<int,QString> DataBase_Main::login
( const QString &ID, const QString &password )
	{ return dUser->login( ID, password ); }

bool DataBase_Main::logout( int UserId )
	{ return dUser->logout(UserId); }

