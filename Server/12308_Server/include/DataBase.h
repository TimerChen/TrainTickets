/*
	Writed by Jingxiao Chen.
*/

#ifndef DATABASE_H
#define DATABASE_H
/*
	We need Map/HashMap , Vector and ID Manager.
*/

/*
	Base class of Data bases.
*/

//A class for translate time more conveniently.
//That is
#include <QString>
#include "include/vector.hpp"
#include "include/smartpoint.hpp"

namespace ttd {
	template <class T>
	class vector;
}
class Train;
class QTrain;
class Ticket;
class Account;
class DataBase_Account;
class DataBase_Log;
class DataBase_User;
class DataBase_Train;


class Time
{
public:
	Time( const int &t=0 );
	short year,month,day;
	short hou,min,sec;
	int to_int();
	Time &set( const int &t=0 );
	QString to_string();
};

class DataBase_Base
{
public:
	QString dataBase_name;
	DataBase_Base( const QString &Name = "Default" );
	~DataBase_Base();
protected:
	virtual void loadData();
	virtual void saveData();
};


//A class for save the user who connect with server.
//So it will never save data.
class DataBase_User : public DataBase_Base             //前后端分离进行身份验证,
{
	friend class DataBase_Main;
public:
	DataBase_User( const QString &Name = "Default" );
	~DataBase_User();

	// Login with your account id and password.
	// return 0: failed
	// return else : template id
	int login( const QString &ID, const QString &password );

	//-1:not exist.
	int query_identifyType( int UserId );
private:
	bool logout( const int id );

};
//A class to save Account's information.
class DataBase_Account : public DataBase_Base
{
	friend class DataBase_Main;
	friend class DataBase_User;

	//Real information of one person.
	struct IdentifyInformation
	{
		QString name;
		int identificationCardNumber;
		//0-normal 1-student
		short 	identifyType,
				age;
	};
	// some values have default value.
	struct Account
	{
		//Account(){}
		Account( const QString &Id, const short IdentifyType );

		//Id for saving and finding quickly.
		int id_number;

		//Your id for register.
		QString	id,

		//We only save the hash code of password.
				passwordHash;
		IdentifyInformation self;

		//You can buy tickets for your friends.
		ttd::vector<IdentifyInformation>friends;

		//If this is a admin account.
		bool isAdmin;
	};
	//Get the hash code of a password.
	QString getPasswordHash( const QString &Password );
public:
	DataBase_Account( const QString &Name = "Default" );
	~DataBase_Account();

	//Register or lead-in a NEW account.
	//return 0:illegal 1:used-ID 2:succeed.
	bool signUp( const Account &NewAccout, const QString &Password = "000000" );

	//Get the in_number by your string Id ( in logn ).
	//return 0:not find
	int getIdNumber( const QString &Id );

private:


};
//The data base of Train and Stations.
class DataBase_Train : public DataBase_Base
{
	friend class DataBase_Main;
	//Left tickets info.
	struct Tickets
	{
		bool availiable;
		ttd::vector<ttd::vector<int> >number;
	};

	//A train schedule.
	struct Train
	{
		bool availiable;

		//Id for saving and finding quickly.
		int id_number;
		//
		QString trainNumber;

		//real ID of stations.
		ttd::vector<int>stations;

		//Numbers of different types of tickets.
		int nType;
		ttd::vector<QString>ticketType;

		//real price*100
		//The price of tickets. price[i]-price[j]
		//price[i]==-1 means you can't buy a ticket which reaches station i.
		ttd::vector<ttd::vector<int> >price;

		//I really don't know how many kinds of times will be used here???
		ttd::vector<int>reachTime;
		ttd::vector<int>stopTime;
		ttd::vector<int>startTime;
	};
	struct QTrain
	{
		bool availiable;

		//Id for saving and finding quickly.
		int id_number;
		//
		QString trainNumber;

		//Numbers of different types of tickets.
		int nType,
		//real ID of stations.
			fromStation,toStation;
		ttd::vector<QString>ticketType;

		//real price*100
		ttd::vector<int>price;
		//Left tickets' number.
		ttd::vector<Ticket>tickets;
		//I really don't know how many kinds of times will be used here???
		int reachTime;
		int stopTime;
		int startTime;
	};
public:
	DataBase_Train( const QString &Name = "Default" );
	~DataBase_Train();
	void addNewTrain( const Train &t );


};
class DataBase_Log : public DataBase_Base
{
	friend class DataBase_Main;
	struct Log
	{
		//Who make this.
		int editor,
		//Type of this operation
			operat,
		//When this log be created ( For Search. )
			time;
		ttd::vector<int>detail;
	};
public:
	DataBase_Log( const QString &Name = "Default" );
	~DataBase_Log();
	void addNewLog( const Log &NewLog );
	//Get logs of string.
	ttd::vector<QString> getLogs( int StartTime, int EndTime );

	//Get logs of Log.
	ttd::vector<Log> getLogs_raw( int StartTime, int EndTime );
};





#endif
