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

	DataBase_Main( const QString &Name = "Default" );
	~DataBase_Main();

	ttd::normal_ptr<ttd::vector<QString> > getLog();
	//Read information from external files.
	void loadData_raw_buy( const QString &FileName );
	void loadData_raw_train( const QString &FileName );

	//Network
	void newConnection( const QString &Ip );
	void disconnect( const int &UserId );

	//Database_User
	int regist( const QString &Id, const QString &pwd, const QString &name="Unknown" );
	ttd::pair<int,QString> login( const QString &ID, const QString &password, const short &type=0 );
	bool logout( int UserId );

	//Database_Account
	DataBase_Account::Account queryAccount( const int &UserId, QString ID);
	void modifyAccount( const int &UserId, const int &Id,
					   const QString &newPassword, const QString &newName);
	ttd::map<DataBase_Account::Ticket,int>
		ownedTicket( const int &UserId, const QString &Id );

	/*
	int buyTickets( const int &UserId, const int &Id,
					const QString &trainId, const QString &from, const QString &to,
					const QDateTime &fromTime, const QDateTime &toTime,
					const int &price, const QString &type, const int &num);
	int returnTicket(const int &UserId, const int &Id, const QString&trainId,
					 const QString&from, const QString&to,
					 const QDateTime &fromTime, const QDateTime &toTime,
					 const int &price, const QString&type, const int &num);
	*/

	//Database_Train
	void buyTickets (const int &UserId, const QString &accId,
					 const QString &traId, const QDate &dat,
					 const QString &lsta, const QString &ulsta,
					 const QString &set, const int &num);
	void returnTickets (const int &UserId, const QString &accId,
						const QString &traId, const QDate &dat,
						const QString &lsta, const QString &ulsta,
						const QString &set, const int &num);
	ttd::vector<DataBase_Train::TrainRoute>
		query_station(const int &UserId, QString Station);
	ttd::vector<DataBase_Train::QTrain>
		query_stationToStation (const int &UserId,
			QDate dat, QString lsta, QString ulsta);
	DataBase_Train::TrainRoute
		query_train(const int &UserId, QString tra);


	//Add Log
	void addLog( const QString &content );


	void change_pwd( const int &UserId, const QString &accId, const QString
					 );
	//void User
	//UserId is for identify your identification.

	void modify_train( int UserId, int TrainId, const Train &TrainInfo );

	//This will return a TrainId.
	int add_train( int UserId, const Train &TrainInfo );
	void delete_train( int UserId, int TrainId );

	void startSell( int UserId, int TrainId, int DayTime );
	void stopSell( int UserId, int TrainId, int DayTime );

	ttd::vector<QString> query_logs( int UserId, int FromTime, int ToTime );
};

#endif // DATABASE_MAIN_H
