#ifndef DATABASE_MAIN_H
#define DATABASE_MAIN_H

/*
	The data base controll all types of databases.
	I/O and other main things.
*/
class DataBase_Main : public DataBase_Base             //对外接口
{
private:
/*
	shared_ptr<DataBase_Log>		dblog;
	shared_ptr<DataBase_Account>	dbaccount;
	shared_ptr<DataBase_User>		dbuser;
	shared_ptr<DataBase_Train>		dbtrain;
*/
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

#endif // DATABASE_MAIN_H
