class DataBase_Main : public DataBase_Base
{
private:

	shared_ptr<DataBase_Log>		dblog;
	shared_ptr<DataBase_Account>	dbaccount;
	shared_ptr<DataBase_User>		dbuser;
	shared_ptr<DataBase_Train>		dbtrain;
public:
	DataBase_Main()
	{
		dbuser->add_acc(dbaccount);
	}
	Account query_account( int UserId, std::string ID )
	{
		Account a;
		if (!dbuser.logged(UserId)) return a;	int Temp = dbaccount.getIdNumber(ID);
		if ((!dbuser.is_admin(UserId)) && (dbuser.account_id(UserId)!=Temp))	return a;
		return dbaccount->accData[temp];
	}
	void modify_account( int UserId, int AccountId, const Account &AccountInfo )
	{
		if (!dbuser.logged(UserId))		return;
		if ((!dbuser.is_admin(UserId)) && (dbuser.account_id(UserId)!=AccountId))	return;
		dbaccount.modify_account(AccountId,AccountInfo);
	}
	void buyTickets( int UserId, int DayTime, std::string TrainId, int FromStation, int ToStation ,int Number)
	{
		if (!dbuser.logged(UserId))	return;
		Ticket a(dbUser.account_id(UserId),DayTime,TrainId,FromStation,ToStation);
		dbaccount.buyTickets(a,Number);
	}
	//1e4 times
	void returnTickets( int UserId, int DayTime,std::string TrainId, int FromStation, int ToStation ,int Number)
	{
		if (!dbuser.logged(UserId))	return;
		Ticket a(dbUser.account_id(UserId),DayTime,TrainId,FromStation,ToStation);
		dbaccount.returnTickets(a,Number);	///please insure the number and tic
	}
	ttd::vector<std::string> query_logs( int UserId, int FromTime, int ToTime );
};


#endif
