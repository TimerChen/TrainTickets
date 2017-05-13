#include "include/database.h"
#include "include/database_main.h"
//#include "DataBase_Train.h"
//#include "DataBase_Accout.h"
//#include "DataBase_User.h"
//#include "src_Vegewong/DataBase_Log.h"

DataBase_Main::DataBase_Main( const QString &Name )
:DataBase_Base(Name)
{
	//dataBase_name = Name;
	/*
	dblog = new DataBase_Log(Name);
	dbaccount = new DataBase_Account(Name);
	dbuser = new DataBase_User(Name);
	dbtrain = new DataBase_Train(Name);*/
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
	/*
	dblog->loadData();
	dbaccount->loadData();
	dbuser->loadData();
	dbtrain->loadData();
	*/
}
void DataBase_Main::saveData()
{
	/*
	dblog->saveData();
	dbaccount->saveData();
	dbuser->saveData();
	dbtrain->saveData();
	*/
}
