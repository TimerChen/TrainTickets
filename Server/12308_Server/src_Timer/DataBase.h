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
#include <string>
#include "src_MW/vector.hpp"
#include "src_MW/smartpoint.hpp"

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
	std::string to_string();
};

class DataBase_Base                                     //流程控制,基类库
{
public:
	std::string dataBase_name;
	DataBase_Base( const std::string &Name = "Default" )
	:dataBase_name( Name )
	{  }
	virtual ~DataBase_Base()
	{  }
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
	DataBase_User( const std::string &Name = "Default" );
	~DataBase_User();

	// Login with your account id and password.
	// return 0: failed
	// return else : template id
	int login( const std::string &ID, const std::string &password );

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
		std::string name;
		int identificationCardNumber;
		//0-normal 1-student
		short 	identifyType,
				age;
	};
	// some values have default value.
	struct Account
	{
		//Account(){}
		Account( const std::string &Id, const short IdentifyType );

		//Id for saving and finding quickly.
		int id_number;

		//Your id for register.
		std::string	id,

		//We only save the hash code of password.
				passwordHash;
		IdentifyInformation self;

		//You can buy tickets for your friends.
		ttd::vector<IdentifyInformation>friends;

		//If this is a admin account.
		bool isAdmin;
	};
	//Get the hash code of a password.
	std::string getPasswordHash( const std::string &Password );
public:
	DataBase_Account( const std::string &Name = "Default" );
	~DataBase_Account();

	//Register or lead-in a NEW account.
	//return 0:illegal 1:used-ID 2:succeed.
	bool signUp( const Account &NewAccout, const std::string &Password = "000000" );

	//Get the in_number by your string Id ( in logn ).
	//return 0:not find
	int getIdNumber( const std::string &Id );

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
		std::string trainNumber;

		//real ID of stations.
		ttd::vector<int>stations;

		//Numbers of different types of tickets.
		int nType;
		ttd::vector<std::string>ticketType;

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
		std::string trainNumber;

		//Numbers of different types of tickets.
		int nType,
		//real ID of stations.
			fromStation,toStation;
		ttd::vector<std::string>ticketType;

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
	DataBase_Train( const std::string &Name = "Default" );
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
	DataBase_Log( const std::string &Name = "Default" );
	~DataBase_Log();
	void addNewLog( const Log &NewLog );
	//Get logs of string.
	ttd::vector<std::string> getLogs( int StartTime, int EndTime );

	//Get logs of Log.
	ttd::vector<Log> getLogs_raw( int StartTime, int EndTime );
};


/*
	The data base controll all types of databases.
	I/O and other main things.
*/
class DataBase_Main : public DataBase_Base             //对外接口
{
private:

	shared_ptr<DataBase_Log>		dblog;
	shared_ptr<DataBase_Account>	dbaccount;
	shared_ptr<DataBase_User>		dbuser;
	shared_ptr<DataBase_Train>		dbtrain;

	void loadData();
	//You can backup server data anytime.
	void saveData();
public:
	//DataBase_Account a;

	DataBase_Main( const std::string &Name = "Default" );
	~DataBase_Main();

	//Read information from external files.
	void loadData_raw( const std::string &FileName );
	//void User
	//UserId is for identify your identification.
	Train get_train( int UserId, std::string Trainid );
	ttd::vector<QTrain> query_train( int UserId, std::string TrainId, int DayTime );
	//Query one station.
	ttd::vector<QTrain> query_station( int UserId, std::string Station, short StationType );
	//Query two stations.
	ttd::vector<QTrain> query_stations( int UserId,
		std::string FromStation, std::string ToStation,
		int DayTime );
	Account query_account( int UserId, std::string ID );
	void modify_train( int UserId, int TrainId, const Train &TrainInfo );
	void modify_ticket( int UserId, int TrainId, int DayTime, const Ticket &TicketInfo );
	void modify_account( int UserId, int AccountId, const Account &AccountInfo );

	//This will return a TrainId.
	int add_train( int UserId, const Train &TrainInfo );
	void delete_train( int UserId, int TrainId );

	void startSell( int UserId, int TrainId, int DayTime );
	void stopSell( int UserId, int TrainId, int DayTime );
	//1e6 times
	void buyTickets( int UserId, int DayTime,
		std::string TrainId, int FromStation, int ToStation ,int Number);
	//1e4 times
	void returnTickets( int UserId, int DayTime,
		std::string TrainId, int FromStation, int ToStation ,int Number);
	ttd::vector<std::string> query_logs( int UserId, int FromTime, int ToTime );
};


#endif
