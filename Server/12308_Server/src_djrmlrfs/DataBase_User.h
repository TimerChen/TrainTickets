#ifndef DATABASE_USER_H
#define DATABASE_USER_H
#include <cstdio>
#include <string>
#include "map.hpp"
#include "vector.hpp"
#include "DataBase.h"
#include "DataBase_Account.h"
//User
//Indeed I do want to write User,Account,Train,and Tickets class myself
class DataBase_User : public DataBase_Base
{
public:
	DataBase_User(const std::string &Name = "Default")
	{
		nowTempId = 0;
		dataBase_name = Name;
		userData.clear();
		nowAccData = NULL;
	}
	~DataBase_User()
	{
		userData.clear();
		nowAccData = NULL;
	}
	//very important, or you can choose you write or let me rewrite in account
	void add_acc(shared_ptr<DataBase_Account> whichAcc)
	{
		nowAccData = whichAcc;
	}
	// Login with your account id and password.
	// return 0: failed
	// we only allow one person lo
	int login( const std::string &ID, const std::string &password )
	{
		if (nowAccData == NULL)	return 0;	// no account data
		int Temp = nowAccData->getIdNumber(ID);//accountid
		if (Temp == -1)	return 0;			// no such id in data
		if (nowAccData->getPasswordHash(password)
		 != nowAccData->accData[Temp].passwordHash)	return 0;	//wrong password
		userData[++nowTempId] = Temp;	//log him
		return nowTempId;
	}
	bool logged(int UserId)
	{
		return (userData.find(UserId)!=userData.end());
		// this means UserId is logged and you can do thins 
		// not only ask train information
	}
	bool is_admin(int UserId)
	{
		return nowAccData->accData[userData[UserId]].isAdmin;
		// when you use some admin_function, please use this first
		// for example  if(a.isAdmin(UserId))	a.query_account(ID)
	}
	//I dont know what it use to
	int query_identifyType( int UserId )
	{
		if (nowAccData == NULL)	return -1;								// no account data
		if (userData.find(UserId) == userData.end())	return -1;		// no such person 
		return nowAccData->accData[userData[UserId]].self.identifyType; 
	}
	//you can use UserId to find Acccount Id, I allow more than one people to log same account
	int account_id(int UserId)
	{
		if (!logged(UserId))	return -1;
		if (nowAccData == NULL)	return -1;
		return userData[UserId];
	}
	//when operate tickets and train,please check weather it's admin
private:
	bool logout( const int UserId )
	{
		if (userData.find(UserId) == userData.end))	return 0;
		userData.erase(UserId);		return 1;
	}
	int nowTempId;
	ttd::map<int,int> userData;//userData[userid] = accountId
	shared_ptr<DataBase_Account> nowAccData;
};
#endif
