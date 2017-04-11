/*
	We need Map/HashMap , Vector and ID Manager.
*/

/*
	Base class of Data bases.
*/

//A class for translate time more conveniently.
//That is
class Time
{
public:
	Time( const int &t=0 );
	short year,month,day;
	short hou,min,sec;
	int to_int();
	Time &set( const int &t=0 );
	string to_string();
};

class DataBase_Base                                     //流程控制,基类库
{
public:
	DataBase_Base( const string &Name = "Default" )
	{ initialize(); }
	~DataBase_Base()
	{ saveData(); }                         
private:
	virtual void loadData();
	virtual void saveData();
};

/*
	The data base controll all types of databases.
	I/O and other main things.
*/
class DataBase_Main : public DataBase_Base             //对外接口
{
private:
	loadData();
	//You can backup server data anytime.
	saveData();
public:
	DataBase_Account a;

	DataBase_Main( const string &Name = "Default" );
	~DataBase_Main();

	//Read information from external files.
	void loadData_raw( const string &FileName );
	void User
	//UserId is for identify your identification.
	Train get_train( int UserId, string Trainid );
	vecotr<QTrain> query_train( int UserId, string TrainId, int DayTime );
	//Query one station.
	vector<QTrain> query_station( int UserId, string Station, short StationType );
	//Query two stations.
	vector<QTrain> query_stations( int UserId,
		string FromStation, string ToStation,
		int DayTime );
	Account query_account( int UserId, string ID );
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
		string TrainId, int FromStation, int ToStation ,int Number);
	//1e4 times
	void returnTickets( int UserId, int DayTime,
		string TrainId, int FromStation, int ToStation ,int Number);
	vector<string> query_logs( int UserId, int FromTime, int ToTime );
};
//A class for save the user who connect with server.
//So it will never save data.
class DataBase_User : public DataBase_Base             //前后端分离进行身份验证,
{

public:
	DataBase_User( const string &Name = "Default" );
	~DataBase_User();

	// Login with your account id and password.
	// return 0: failed
	// return else : template id
	int login( const string &ID, const string &password );

	//-1:not exist.
	int query_identifyType( int UserId );
private:
	bool logout( const int id );

};
//A class to save Account's information.
class DataBase_Account : public DataBase_Base
{
	friend class DataBase_User;

	//Real information of one person.
	struct IdentifyInformation
	{
		string name;
		int identificationCardNumber;
		//0-normal 1-student
		short 	identifyType,
				age;
	}
	// some values have default value.
	struct Account
	{
		//Account(){}
		Account( const string &Id, const identifyType ){}

		//Id for saving and finding quickly.
		int id_number;

		//Your id for register.
		string	id,

		//We only save the hash code of password.
				passwordHash;
		IdentifyInformation self;

		//You can buy tickets for your friends.
		vector<IdentifyInformation>friends;

		//If this is a admin account.
		bool isAdmin;
	};
	//Get the hash code of a password.
	string getPasswordHash( const string &Password );
public:
	DataBase_Account( const string &Name = "Default" );
	~DataBase_Account();

	//Register or lead-in a NEW account.
	//return 0:illegal 1:used-ID 2:succeed.
	bool register( const Account &NewAccout, const string &Password = "000000" );

	//Get the in_number by your string Id ( in logn ).
	//return 0:not find
	int getIdNumber( const string &Id );

private:


};
//The data base of Train and Stations.
class DataBase_Train : public DataBase_Base
{
	//Left tickets info.
	struct Tickets
	{
		bool availiable;
		vector<vector<int> >number;
	};

	//A train schedule.
	struct Train
	{
		bool availiable;

		//Id for saving and finding quickly.
		int id_number;
		//
		string trainNumber;

		//real ID of stations.
		vector<int>stations;

		//Numbers of different types of tickets.
		int nType;
		vector<string>ticketType;

		//real price*100
		//The price of tickets. price[i]-price[j]
		//price[i]==-1 means you can't buy a ticket which reaches station i.
		vector<vector<int> >price;

		//I really don't know how many kinds of times will be used here???
		vector<int>reachTime;
		vector<int>stopTime;
		vector<int>startTime;
	};
	struct QTrain
	{
		bool availiable;

		//Id for saving and finding quickly.
		int id_number;
		//
		string trainNumber;

		//Numbers of different types of tickets.
		int nType,
		//real ID of stations.
			fromStation,toStation;
		vector<string>ticketType;

		//real price*100
		vector<int>price;
		//Left tickets' number.
		vector<Ticket>tickets;
		//I really don't know how many kinds of times will be used here???
		int reachTime;
		int stopTime;
		int startTime;
	};
public:
	DataBase_Train( const string &Name = "Default" );
	~DataBase_Train();
	void addNewTrain( const Train &t );


}
class DataBase_Log : public DataBase_Base
{
	struct Log
	{
		//Who make this.
		int editor,
		//Type of this operation
			operat,
		//When this log be created ( For Search. )
			time;
		vector<int>detail;
	};
public:
	DataBase_Log( const string &Name = "Default" );
	~DataBase_Log();
	void addNewLog( const Log &NewLog );
	//Get logs of string.
	vector<string> getLogs( int StartTime, int EndTime );

	//Get logs of Log.
	vector<Log> getLogs_raw( int StartTime, int EndTime );
}
