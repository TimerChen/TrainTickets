#ifndef DATABASE_USER_H
#define DATABASE_USER_H
#include <cstdio>
#include <string>
#include <QDateTime>
#include "database.h"
#include "DataBase_Account.h"
//User
//Indeed I do want to write User,Account,Train,and Tickets class myself
class DataBase_User : public DataBase_Base
{

private:
	int nowTempId;
	ttd::map<int,ttd::pair<int,int> > userData;//userData[userid] = accountId
	ttd::shared_ptr<DataBase_Account> nowAccData;


public:
	DataBase_User(const QString &Name = "Default");
	~DataBase_User();
	void saveData();
	void loadData();
	//very important, or you can choose you write or let me rewrite in account
	void add_acc(ttd::shared_ptr<DataBase_Account> whichAcc);
	// Login with your account id and password.
	// return 0: failed
	ttd::pair<int,QString> login( const QString &ID, const QString &password );
	ttd::pair<int,QString> adminLogin( const QString &ID, const QString &password );
	bool logout( const int UserId );
	bool logged(int UserId);
	bool is_admin(int UserId);
	//int query_identifyType( int UserId );
	//you can use UserId to find Acccount Id, I allow more than one people to log same account
	int account_id(int UserId);
	//when operate tickets and train,please check weather it's admin

};
#endif
//
