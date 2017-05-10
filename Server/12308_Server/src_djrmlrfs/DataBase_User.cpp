#include <cstdio>
#include <string>
#include "DataBase_User.h"
DataBase_User::DataBase_User(const std::string &Name)
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

int DataBase_User::login( const std::string &ID, const std::string &password )
{
	if (nowAccData == NULL)	return 0;	// no account data
	int Temp = nowAccData->getIdNumber(ID);//accountid
	if (Temp == -1)	return 0;			// no such id in data
	if (nowAccData->getPasswordHash(password)
	 != nowAccData->accData[Temp].passwordHash)	return 0;	//wrong password
	userData[++nowTempId] = Temp;	//log him
	return nowTempId;
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
//I dont know what it use to
int DataBase_User::query_identifyType( int UserId )
{
	if (nowAccData == NULL)	return -1;								// no account data
	if (userData.find(UserId) == userData.end())	return -1;		// no such person 
	return nowAccData->accData[userData[UserId]].self.identifyType; 
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
int main()
{
}
