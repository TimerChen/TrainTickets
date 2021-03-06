#include "DataBase_User.h"
DataBase_User::DataBase_User(const QString &Name)
{
	nowTempId = 0;
	dataBase_name = Name;
	userData.clear();
	nowAccData = NULL;
}


DataBase_User::~DataBase_User()
{
	nowAccData = NULL;
}

ttd::pair<int,QString> DataBase_User::login( const QString &ID, const QString &password )
{
	if (nowAccData == NULL)	return ttd::pair<int,QString>(0,"NoAccountData");	// no account data
	int Temp = nowAccData->getIdNumber(ID);//accountid
	if (Temp == -1)	return ttd::pair<int,QString>(0,"NoSuchAccount");			// no such id in data
	if (nowAccData->getPasswordHash(password)
	 != nowAccData->accData[Temp].passwordHash)	return ttd::pair<int,QString>(0,"WrongPassword");	//wrong password
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

void DataBase_User::add_acc(shared_ptr<DataBase_Account> whichAcc)
{
	nowAccData = whichAcc;
}

bool DataBase_User::is_admin(int UserId)
{
	return nowAccData->accData[userData[UserId]].isAdmin;
	// when you use some admin_function, please use this first
	// for example  if(a.isAdmin(UserId))	a.query_account(ID)
}
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
