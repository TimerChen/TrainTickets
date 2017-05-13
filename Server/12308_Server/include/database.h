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
#include "include/map.hpp"
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


class DataBase_Base
{
public:
	QString dataBase_name;
	DataBase_Base( const QString &Name = "Default" );
	~DataBase_Base();
protected:
	void loadData();
	void saveData();
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
