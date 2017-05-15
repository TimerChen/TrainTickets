#ifndef DATABASE_MAIN_H
#define DATABASE_MAIN_H

/*
	The data base controll all types of databases.
	I/O and other main things.
*/

#include "DataBase_Train.h"
#include "DataBase_Account.h"
#include "DataBase_User.h"
#include "DataBase_Log.h"

#include "include/map.hpp"

class DataBase_Main : public DataBase_Base
{
private:

	ttd::shared_ptr<DataBase_Log>		dLog;
	ttd::shared_ptr<DataBase_Train>		dTrain;
	ttd::shared_ptr<DataBase_Account>	dAccount;
	ttd::shared_ptr<DataBase_User>		dUser;

	void loadData();
	//You can backup server data anytime.
	void saveData();
public:
	//DataBase_Account a;

	DataBase_Main( const QString &Name = "Default" );
	~DataBase_Main();

	ttd::normal_ptr<ttd::vector<QString> > getLog();
	//Read information from external files.
	void loadData_raw( const QString &FileName );

	//Network
	void newConnection( const QString &Ip );
	void disconnect( const int &UserId );

	//Database_User
	int regist( QString name, QString pwd );
	ttd::pair<int,QString> login( const QString &ID, const QString &password );
	bool logout( int UserId );

	//Database_Account
	int buyTickets( const int &UserId, const int &Id,
					const QString &trainId, const QString &from, const QString &to,
					const QDateTime &fromTime, const QDateTime &toTime,
					const int &price, const QString &type, const int &num);
	int returnTicket(const int &UserId, const int &Id, const QString&trainId, const QString&from, const QString&to,
					 const QDateTime &fromTime, const QDateTime &toTime, const int &price, const QString&type, const int &num);
	ttd::map<DataBase_Account::Ticket,int>
		ownedTicket( const int &UserId, const int &Id );
	//Add Log
	void addLog( const QString &content );


	//void User
	//UserId is for identify your identification.
	Train get_train( int UserId, QString Trainid );
	ttd::vector<QTrain> query_train( int UserId, QString TrainId, int DayTime );
	//Query one station.
	ttd::vector<QTrain> query_station( int UserId, QString Station, short StationType );
	//Query two stations.
	ttd::vector<QTrain> query_stations( int UserId,
		QString FromStation, QString ToStation,
		int DayTime );
	Account query_account( int UserId, QString ID );
	void modify_train( int UserId, int TrainId, const Train &TrainInfo );
	void modify_ticket( int UserId, int TrainId, int DayTime, const Ticket &TicketInfo );
	void modify_account( int UserId, int AccountId, const Account &AccountInfo );

	//This will return a TrainId.
	int add_train( int UserId, const Train &TrainInfo );
	void delete_train( int UserId, int TrainId );

	void startSell( int UserId, int TrainId, int DayTime );
	void stopSell( int UserId, int TrainId, int DayTime );

	ttd::vector<QString> query_logs( int UserId, int FromTime, int ToTime );
};

#endif // DATABASE_MAIN_H
