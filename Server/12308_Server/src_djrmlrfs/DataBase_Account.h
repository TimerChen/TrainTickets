#ifndef DATABASE_ACCOUNT_H
#define DATABASE_ACCOUNT_H
#include <cstdio>
#include <string>
#include "DataBase.h"
//A class to save Account's information.
class DataBase_Account : public DataBase_Base
{
 
	friend class DataBase_User;
	//Real information of one person.
	struct IdentifyInformation
	{
		std::string name;
		// i do think its now a number since there would be X in the number
		// they say we do not need it
		std::string identificationCardNumber;
		//0-normal 1-student
		short	identifyType,
				age;
		IdentifyInformation operator=(const IdentifyInformation &he);
	};
	// some values have default value.
	struct Account
	{
		//Account(){}
		Account( const std::string &Id="Default", const short identifyType=0 );
		Account operator=(const Account &acc);
		//Id for saving and finding quickly.
		int id_number;
		//Your id for register.
		std::string	id,
		//We only save the hash code of password.
				passwordHash;
		IdentifyInformation self;
		//You can buy tickets for your friends.
		ttd::vector<int>friends;
		//If this is a admin account.
		bool isAdmin;
	};
	//MD5 copied from internet
	//Get the hash code of a password.
private:
	static char str16[];
	static unsigned int k[];
	static unsigned int s[];
	std::string Hex(int a);
public:
	std::string getPasswordHash( const std::string &Password );
public:
	DataBase_Account( const std::string &Name = "Default" );
	~DataBase_Account();

	//Register or lead-in a NEW account.
	//return	0:illegal	1:used-ID used	2: succeed.
	int Register( const Account &NewAccout, const std::string &Password = "000000" );
	//Get the id_number by your string Id ( in logn ).
	int getIdNumber( const std::string &Id );
	
	// must valid and admin
	Account query_account(std::string ID);
	//please check weather valid, i means, logged and admin or change self
	// and remember to check weather check password when modify password
	void modify_account(int Id, const Account &AccountInfo );
	
private:
	int accNums;
	ttd::map<std::string,int> Numbers;
	ttd::vector<Account> accData;
};

#endif
