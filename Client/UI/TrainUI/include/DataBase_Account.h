#ifndef DATABASE_ACCOUNT_H
#define DATABASE_ACCOUNT_H
#include <cstdio>
#include <QString>
#include <QDateTime>

#include "include/database.h"
#include "include/vector.hpp"
#include "include/map.hpp"

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
		ticLog();
		ticLog(const QString&tra,
			   const QString&fro, const QString&to,
			   const QDateTime &day, const int &buynum);

	};
	struct Ticket
	{

		QString buyer;
		QString loadStation, unLoadStation;
		QString trainID;
		QDateTime loadTime, unLoadTime;
		int price;
		QString seatType;
		Ticket();
		Ticket(const QString&name, const QString&st, const QString&ed,
			   const QString&tra, const QDateTime &stt, const QDateTime &edt,
			   const int &pri, const QString&stp);
		//~Ticket();
		

	};
	struct Account
	{
		//Your id for register.
		QString id;
		//Your name
		QString name;

		//If this is a admin account.
		bool isAdmin;
		//We only save the hash code of password.
		QString passwordHash;

		//Id for saving and finding quickly.
		int id_number;


		//the information in buying and refounding
		ttd::vector<ticLog> log;
		//and the Tickets bought
		ttd::map<Ticket,int> bought;


		Account(const QString&Id = "Default", const QString&nam = "TimeMachine", const bool &adm = 0,
		 const QString&pwhash = "e45fdbb7dfc90eaabbc46e25ddecfad0", const int &num = -1);
		Account& operator=(const Account &acc);
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

	void saveData();
	void loadData();

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

QDataStream& operator << (QDataStream& out, const DataBase_Account::Ticket &data);
QDataStream& operator >> (QDataStream& in, DataBase_Account::Ticket &data);
QDataStream& operator << (QDataStream& out, const DataBase_Account::Account &data);
QDataStream& operator >> (QDataStream& in, DataBase_Account::Account &data);
QDataStream& operator << (QDataStream& out, const DataBase_Account::ticLog &data);
QDataStream& operator >> (QDataStream& in, DataBase_Account::ticLog &data);



#endif
