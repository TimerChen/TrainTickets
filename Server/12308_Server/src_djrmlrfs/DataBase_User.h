#ifndef DATABASE_USER_H
#define DATABASE_USER_H
#include <cstdio>
#include <string>
#include <QDateTime>
#include "DataBase.h"
#include "DataBase_Account.h"
//User
//Indeed I do want to write User,Account,Train,and Tickets class myself
class DataBase_User : public DataBase_Base
{
public:
	DataBase_User(const Qstring &Name = "Default");
	~DataBase_User();
	//very important, or you can choose you write or let me rewrite in account
	void add_acc(shared_ptr<DataBase_Account> whichAcc);
	// Login with your account id and password.
	// return 0: failed
	int login( const Qstring &ID, const Qstring &password );
	bool logged(int UserId);
	bool is_admin(int UserId);
	int query_identifyType( int UserId );
	//you can use UserId to find Acccount Id, I allow more than one people to log same account
	int account_id(int UserId);
	//when operate tickets and train,please check weather it's admin
private:
	bool logout( const int UserId );
	int nowTempId;
	ttd::map<int,int> userData;//userData[userid] = accountId
	shared_ptr<DataBase_Account> nowAccData;
};
#endif
//
