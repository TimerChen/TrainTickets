#ifndef DATABASE_ACCOUNT_H
#define DATABASE_ACCOUNT_H
#include <cstdio>
#include <string>
#include "DataBase.h"
//A class to save Account's information.
class DataBase_Account : public DataBase_Base
{
 
	friend class DataBase_User;
public:
	struct ticLog{
		Qstring train, fromStation, toStation;
		// I do not know which head file to include , It's in Qt 
		QDate date;
		int num;
		ticLog(const Qstring&tra, const Qstring&fro, const Qstring&to, const QDate &day, const int &buynum)
		:train(tra), fromStation(fro), toStation(to), date(day), num(buynum){}
	};
	struct Account
	{
		//Your id for register.
		Qstring id;

		//Id for saving and finding quickly.
		int id_number;

		//Your name
		Qstring name;

		//We only save the hash code of password.
		Qstring passwordHash;

		//If this is a admin account.
		bool isAdmin;

		//the information in buying and refounding
		ttd::vector<ticLog> log;

		Account(const Qstring&Id = "Default", const Qstring&nam = "TimeMachine", const bool &adm = 0,
		 const Qstring&pwhash = "e1119c269cdb64f851aef6db68c49610", const int &num = -1):
		id_number(num), id(Id), name(nam), passwordHash(pwhash), isAdmin(adm){log.clear();}
		Account operator=(const Account &acc);
	};
	struct Ticket
	{
		int accId, price;
		Qstring buyer;
		Qstring loadStation, unLoadStation;
		Qstring trainID;
		QDate loadTime, unLoadTime;
		Qstring seatType;
		Ticket(const int &a){accId = a; price = -1;}
        Ticket(const int &acid, const Qstring&name, const Qstring&st, const Qstring&ed,
		 const Qstring&tra, const QDate &stt, const QDate &edt, const int &pri, const Qstring&stp)
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
	Qstring Hex(int a);
public:
	//Get the hash code of a password.
	Qstring getPasswordHash( const Qstring&Password );
	DataBase_Account( const Qstring&Name = "Default" );
	~DataBase_Account();

	//Register or lead-in a NEW account.
	//return	0:illegal	1:used-ID used	2: succeed.
	int Register( const Account &NewAccout, const Qstring&Password = "000000" );
	//Get the id_number by your string Id ( in logn ).
	int getIdNumber( const Qstring&Id );
	
	// must valid and admin
	Account query_account(Qstring ID);
	Account query_account(int ID);
	//please check weather valid, i means, logged and admin or change self
	// and remember to check weather check password when modify password
	void modify_account(const int &Id, const Account &AccountInfo );
	//return the total cost
	int buyTicket(const int &Id, const Qstring&trainId, const Qstring&from, const Qstring&to,
		const QDate &fromTime, const QDate &toTime, const int &price, const Qstring&type, const int &num);
	
	int returnTicket(const int &Id, const Qstring&trainId, const Qstring&from, const Qstring&to,
		const QDate &fromTime, const QDate &toTime, const int &price, const Qstring&type, const int &num);
	ttd::vector<ticLog> quiryLog(const int &Id);
	ttd::vector<ticLog> ownedTicket(const int &Id);
private:
	int accNums;
	ttd::map<Qstring,int> Numbers;
	ttd::vector<Account> accData;
	ttd::map<Ticket,int> ticData;
};

#endif
