#ifndef DATABASE_ACCOUNT_H
#define DATABASE_ACCOUNT_H
#include <cstdio>
#include <string>
#include "DataBase.h"
//A class to save Account's information.
class DataBase_Account : public DataBase_Base
{
 
	friend class DataBase_User;
	struct ticLog{
		std::string train, fromStation, toStation;
		// I do not know which head file to include , It's in Qt 
		QDateTime date;
		int num;
		ticLog(const std::string &tra, const std::string &fro, const std::string &to, const QDateTime &day, const int &buynum)
		:train(tra), fromStation(fro), toStation(to), date(day), num(buynum){}
	};
	struct Account
	{
		//Your id for register.
		std::string id;

		//Id for saving and finding quickly.
		int id_number;

		//Your name
		std::string name;

		//We only save the hash code of password.
		std::string passwordHash;

		//If this is a admin account.
		bool isAdmin;

		//the information in buying and refounding
		ttd::vector<ticLog> log;

		Account(const std::string &Id = "Default", const int &num = -1, const std::string &nam = "TimeMachine",
		 const std::string &pwhash = "e1119c269cdb64f851aef6db68c49610", const bool &adm = 0):
		id_number(num), id(Id), name(nam), passwordHash(pwhash), isAdmin(adm){log.clear();}
		Account operator=(const Account &acc);
	};
	struct Ticket
	{
		int accId, price;
		std::string buyer;
		std::string loadStation, unLoadStation;
		std::string trainID;
		QDateTime loadTime, unLoadTime;
		std::string seatType;
		Ticket(const int &a){accId = a; price = -1;}
        Ticket(const int &acid, const std::string &name, const std::string &st, const std::string &ed,
		 const std::string &tra, const QDateTime &stt, const QDateTime &edt, const int &pri, const std::string &stp)
	:accId(acid), buyer(name), loadStation(st), unLoadStation(ed), trainID(tra), loadTime(stt), unLoadTime(edt), price(pri), seatType(stp){}
		~Ticket(){}
		
		bool operator < (const Ticket &t1) const
		{
			if (accId < t1.accId)	return 1;
			if (accId > t1.accId)	return 0;
			if (price < t1.price)	return 1;
			if (price > t1.price)	return 0;
			if (buyer < t1.buyer)	return 1;
			if (buyer > t1.buyer)	return 0;
			if (loadStation < t1.loadStation)	return 1;
			if (loadStation > t1.loadStation)	return 0;
			if (unLoadStation < t1.unLoadStation)	return 1;
			if (unLoadStation > t1.unLoadStation)	return 0;
			if (seatType < t1.seatType)	return 1;
			if (seatType > t1.seatType)	return 0;
			if (loadTime < t1.loadTime)	return 1;
			if (loadTime > t1.loadTime)	return 0;
			if (unLoadTime < t1.unLoadTime)	return 1;
			if (unLoadTime > t1.unLoadTime)	return 0;
			return (seatType < t1.seatType);
		}
		
		bool operator == (const Ticket &t1) const{
			return (accId==t1.accId && trainID==t1.trainID && seatType==t1.seatType
			&& loadStation==t1.loadStation && unLoadStation==t1.unLoadStation && loadTime==t1.loadTime);
		}
		
	};
private:
	static char str16[];
	static unsigned int k[];
	static unsigned int s[];
	std::string Hex(int a);
public:
	//Get the hash code of a password.
	std::string getPasswordHash( const std::string &Password );
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
	void modify_account(const int &Id, const Account &AccountInfo );
	//return the total cost
	int buyTicket(const int &Id, const std::string &trainId, const std::string &from, const std::string &to,
		const QDateTime &fromTime, const QDateTime &toTime, const int &price, const std::string &type, const int &num);
	
	int returnTicket(const int &Id, const std::string &trainId, const std::string &from, const std::string &to,
		const QDateTime &fromTime, const QDateTime &toTime, const int &price, const std::string &type, const int &num);
	ttd::vector<ticLog> quiryLog(const int &Id);
	ttd::vector<ticLog> ownedTicket(const int &Id);
private:
	int accNums;
	ttd::map<std::string,int> Numbers;
	ttd::vector<Account> accData;
	ttd::map<Ticket,int> ticData;
};

#endif
