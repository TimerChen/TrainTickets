#include "include/DataBase_User.h"

DataBase_User::DataBase_User(const QString &Name)
	:DataBase_Base(Name)
{
	nowTempId = 0;
	userData.clear();
	nowAccData = NULL;
}


DataBase_User::~DataBase_User()
{
	nowAccData = NULL;
}
void DataBase_User::saveData(){}
void DataBase_User::loadData(){}


ttd::pair<int,QString> DataBase_User::login( const QString &ID, const QString &password, const short &type )
{
	if (nowAccData == NULL)	return ttd::pair<int,QString>(0,"NoAccountData");	// no account data
	int Temp = nowAccData->getIdNumber(ID);//accountid
	if (Temp == -1)	return ttd::pair<int,QString>(0,"NoSuchAccount");			// no such id in data
	if (nowAccData->getPasswordHash(password)
	 != nowAccData->accData[Temp].passwordHash)	return ttd::pair<int,QString>(0,"WrongPassword");	//wrong password

	if (type && nowAccData->accData[Temp].isAdmin)
		return ttd::pair<int,QString>(0,"Admin cannot modify another admin's account.");

	userData[++nowTempId] = Temp;	//log him
	return ttd::pair<int,QString>(nowTempId,nowAccData->accData[Temp].name);
}
ttd::pair<int,QString> DataBase_User::adminLogin( const QString &ID, const QString &password )
{
	if (nowAccData == NULL)	return ttd::pair<int,QString>(0,"NoAccountData");	// no account data
	int Temp = nowAccData->getIdNumber(ID);//accountid
	if (Temp == -1)	return ttd::pair<int,QString>(0,"NoSuchAccount");			// no such id in data
	if (!nowAccData->accData[Temp].isAdmin)	return ttd::pair<int,QString>(0,"NotAdmin");	// not admin
	if (nowAccData->getPasswordHash(password)
	 != nowAccData->accData[Temp].passwordHash)	return ttd::pair<int,QString>(0,"WrongPassword");	//wrong password
	userData[++nowTempId] = Temp;	//log him
	return ttd::pair<int,QString>(nowTempId,nowAccData->accData[Temp].name);
}

bool DataBase_User::logged(int UserId)
{
	return (userData.find(UserId)!=userData.end());
	// this means UserId is logged and you can do things 
	// not only ask train information
}

void DataBase_User::add_acc(ttd::shared_ptr<DataBase_Account> whichAcc)
{
	nowAccData = whichAcc;
}

bool DataBase_User::is_admin(int UserId)
{
	if(UserId == -1) return false;
	if(UserId == 0) return true;
	return nowAccData->accData[userData[UserId]].isAdmin;
	// when you use some admin_function, please use this first
	// for example  if(a.isAdmin(UserId))	a.query_account(ID)
}
/*
//I dont know what it use to
int DataBase_User::query_identifyType( int UserId )
{
	if (nowAccData == NULL)	return -1;								// no account data
	if (userData.find(UserId) == userData.end())	return -1;		// no such person 
	return nowAccData->accData[userData[UserId]].self.identifyType;
}*/

//you can use UserId to find Acccount Id, I allow more than one people to log same account
int DataBase_User::account_id(int UserId)
{
	if (!logged(UserId))	return -1;
	if (nowAccData == NULL)	return -1;
	return userData[UserId];
}
//when operate tickets and train,please check weather it's admin
bool DataBase_User::logout( const int UserId )
{
	if (!logged(UserId))	return 0;
	userData.erase(userData.find(UserId));		return 1;
}
