#ifndef DATABASE_ACCOUNT_H
#define DATABASE_ACCOUNT_H
#include <cstdio>
#include <QString>
#include <QDateTime>
#include "DataBase.h"
//A class to save Account's information.
class DataBase_Account : public DataBase_Base
{
 
	friend class DataBase_User;
public:
	struct ticLog{
		QString train, fromStation, toStation;
		// I do not know which head file to include , It's in Qt 
		QDateTime date;
		int num;
		ticLog(const QString&tra, const QString&fro, const QString&to, const QDateTime &day, const int &buynum)
		:train(tra), fromStation(fro), toStation(to), date(day), num(buynum){}
	};
	struct Ticket
	{
		int price;
		QString buyer;
		QString loadStation, unLoadStation;
		QString trainID;
		QDateTime loadTime, unLoadTime;
		QString seatType;
		Ticket(const QString&name, const QString&st, const QString&ed,
		 const QString&tra, const QDateTime &stt, const QDateTime &edt, const int &pri, const QString&stp)
	:buyer(name), loadStation(st), unLoadStation(ed), trainID(tra), loadTime(stt), unLoadTime(edt), price(pri), seatType(stp){}
		~Ticket(){}
		
		bool operator < (const Ticket &t1) const
		{
			if (price < t1.price)	return 1;
			if (price > t1.price)	return 0;
			if (buyer < t1.buyer)	return 1;
			if (buyer > t1.buyer)	return 0;
			if (trainID < t1.trainID)	return 1;
			if (trainID > t1.trainID)	return 0;
			if (loadTime < t1.loadTime)	return 1;
			if (loadTime > t1.loadTime)	return 0;
			return (unLoadTime < t1.unLoadTime);
		}
	};
	struct Account
	{
		//Your id for register.
		QString id;

		//Id for saving and finding quickly.
		int id_number;

		//Your name
		QString name;

		//We only save the hash code of password.
		QString passwordHash;

		//If this is a admin account.
		bool isAdmin;

		//the information in buying and refounding
		ttd::vector<ticLog> log;
		//and the Tickets bought
		ttd::map<Ticket,int> bought;
		Account(const QString&Id = "Default", const QString&nam = "TimeMachine", const bool &adm = 0,
		 const QString&pwhash = "e45fdbb7dfc90eaabbc46e25ddecfad0", const int &num = -1):
		id_number(num), id(Id), name(nam), passwordHash(pwhash), isAdmin(adm){log.clear();bought.clear();}
		Account operator=(const Account &acc);
	};
private:
	static char str16[];
	static unsigned int k[];
	static unsigned int s[];
	QString Hex(int a);
public:
	//Get the hash code of a password.
	QString getPasswordHash( const QString&Password );
	DataBase_Account( const QString&Name = "Default" );
	~DataBase_Account();

	//Register or lead-in a NEW account.
	//return	0:illegal	1:used-ID used	2: succeed.
	int Register( const Account &NewAccout, const QString&Password = "000000" );
	//Get the id_number by your string Id ( in logn ).
	int getIdNumber( const QString&Id );
	
	// must valid and admin
	Account queryAccount(QString ID);
	Account queryAccount(int ID);
	//please check weather valid, i means, logged and admin or change self
	// and remember to check weather check password when modify password
	void modifyAccount(const int &Id, const QString &newPassword, const QString &newName);
	//return the total cost
	int buyTicket(const int &Id, const QString &trainId, const QString &from, const QString &to,
		const QDateTime &fromTime, const QDateTime &toTime, const int &price, const QString &type, const int &num);
	
	int returnTicket(const int &Id, const QString&trainId, const QString&from, const QString&to,
		const QDateTime &fromTime, const QDateTime &toTime, const int &price, const QString&type, const int &num);
	ttd::vector<ticLog> quiryLog(const int &Id);
	ttd::map<Ticket,int> ownedTicket(const int &Id);
private:
	int accNums;
	ttd::map<QString,int> Numbers;
	ttd::vector<Account> accData;
};

#endif
