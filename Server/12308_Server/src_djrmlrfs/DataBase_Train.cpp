#include "DataBase_Train.h"
DataBase_Train::Train::Train (const QString &tID, int setnr, int stanr,
	const ttd::vector<QString> &stan, const ttd::vector<int> &ma,
	const ttd::vector<QDateTime> &rt, const ttd::vector<QDateTime> &lt,
	const ttd::vector<QString> &set, const ttd::vector<int> &senr,
	const ttd::vector<ttd::vector<int> > &ptb)
{
	trainID = tID, started = 0;
	seatTypeNumber = setnr, stationNumber = stanr;
	stationName = stan, mileAge = ma, reachTime = rt;
	leaveTime = lt, seatType = set, seatNumber = senr, priceTable = ptb;
}
		
DataBase_Train::Train DataBase_Train::Train::operator=(const Train &a)
{
	trainID = a.trainID;
	started = a.started;
	seatTypeNumber = a.seatTypeNumber;
	stationNumber = a.stationNumber;
	stationName = a.stationName;
	mileAge = a.mileAge, reachTime = a.reachTime;
	leaveTime = a.leaveTime, seatType = a.seatType;
	seatNumber = a.seatNumber, priceTable = a.priceTable;
	salingDate = a.salingDate;
	return *this;
}
DataBase_Train::Train::~Train (){}
void DataBase_Train::Train::openOneDay (QDate dato)
{
	if (salingDate.count(dato))
	{
		salingDate[dato].ableToBuy = true;
		return;
	}
	salingDate[dato].ableToBuy = true;
	for (int i = 0; i < seatTypeNumber; i++)
	{
		ttd::vector<int> a;
		for (int j = 0; j < stationNumber - 1; j++) a.push_back(seatNumber[i]);
		salingDate[dato].restTickets.push_back(a);
	}
}
bool DataBase_Train::Train::closeOneDay (QDate datc)
{
	if (!salingDate.count(datc))	return 0;
	salingDate[datc].ableToBuy = 0;
	return 1;
}
int DataBase_Train::Train::buyTickets (QDate dat, QString lsta, QString ulsta, QString set, int num)
{				//dat is the exact day , maybe 3.29 or 3.30
	int sid;
	for (sid = 0; sid < seatTypeNumber; sid++)	if (seatType[sid] == set)	break;
	if (sid == seatTypeNumber)	return -2;	// no such kind of seat
	for (int i = 0; i < stationNumber; i++)	if (stationName[i] == lsta)
	{
		int k = leaveTime[i].date().day();
		dat = dat.addDays(-k);
		if (!salingDate[dat].ableToBuy)	return -1;	//unable to buy that day;
		int mn = seatNumber[sid];
		int j = i;
		for(; j < stationNumber; j++)
		{
			int __ = salingDate[dat].restTickets[sid][j];
			if (__ < mn)	mn = __;
			if (mn < num)	return -4;	//no enough tickets
			if (stationName[j] == ulsta)	break;
		}				
		if (j == stationNumber)	return -3;	// no such station
		for(; j >= i; j--)
			salingDate[dat].restTickets[sid][j] -= num;
		started = 1;
		return num*(priceTable[sid][j]-priceTable[sid][i]);
	}
	return -3;	// no such station;
}
int DataBase_Train::Train::cancelTickets (QDate dat, QString lsta, QString ulsta, QString set, int num)
{
	// in account class, you can check weather can be cancel;
	int sid;
	for (sid = 0; sid < seatTypeNumber; sid++)	if (seatType[sid] == set)	break;
	for (int i = 0; i < stationNumber; i++)	if (stationName[i] == lsta)
	{
		int k = leaveTime[i].date().day();
		dat = dat.addDays(-k);
		int mn = seatNumber[sid];
		int j = i;
		for(; stationName[j] != ulsta; j++)	salingDate[dat].restTickets[sid][j] += num;
		salingDate[dat].restTickets[sid][j] += num;
		return num*(priceTable[sid][j]-priceTable[sid][i]);
	}
	return -3;	// no such station;			
}
bool DataBase_Train::Train::openDate (QDate dat)
{
	if (!salingDate.count(dat))	return 0;
	return salingDate[dat].ableToBuy;
}
DataBase_Train::TrainRoute DataBase_Train::Train::query_train()
{
	TrainRoute ans;
	ans.trainID = trainID;
	ans.seatTypeNumber = seatTypeNumber;
	ans.stationNumber = stationNumber;
	ans.stationName = stationName;
	ans.mileAge = mileAge;
	ans.reachTime = reachTime;
	ans.leaveTime = leaveTime;
	ans.seatType = seatType;
	return ans;
}
DataBase_Train::QTrain DataBase_Train::Train::query_stationToStation(QDate dat, QString lsta, QString ulsta)
{
	QTrain ans;
	for (int i = 0; i < stationNumber; i++)	if (stationName[i] == lsta)
	{
		int j = i;
		for(; stationName[j] != ulsta; j++);

		int k = leaveTime[i].date().day();
		dat = dat.addDays(-k);
		ans.ableToBuy = openDate(dat);

		ans.trainID = trainID;
		ans.seatTypeNumber = seatTypeNumber;
		ans.loadStation = lsta, ans.unLoadStation = ulsta;
		ans.seatType = seatType;

		ans.loadStationLeaveTime = leaveTime[i];
		ans.unLoadStationReachTime = reachTime[j];
		for (int _ = 0; _ < seatTypeNumber; _++)
		{
			ans.price.push_back(priceTable[_][j]-priceTable[_][i]);
			int mn = 2e9;
			for (k = i; k <= j; k++)
			{
				int tt = salingDate[dat].restTickets[_][k];
				if (mn > tt)	mn = tt;
			}
			ans.seatNumber.push_back(mn);
		}
	}
	return ans;
}

DataBase_Train::DataBase_Train()
{
	traData.clear();
	staData.clear();
}
	
bool DataBase_Train::trainExist(QString traId)
{
	return traData.count(traId);
}
bool DataBase_Train::createTrain(QString traId, int setnr, int stanr,
	 const ttd::vector<QString> &stan, const ttd::vector<int> &ma,
	 const ttd::vector<QDateTime> &rt, const ttd::vector<QDateTime> &lt,
	 const ttd::vector<QString> &set, const ttd::vector<int> &senr,
	 const ttd::vector<ttd::vector<int> > &ptb)
{
 	if (trainExist(traId) || traData[traId].strated)	return 0;	//fail, train existed or have sold tickets
 	traData[traId] = Train(traId,setnr,stanr,stan,ma,rt,lt,set,senr,ptb);
 	ttd::vector<QString>::iterator it = traData[traId].stationName.begin();
	for (ttd::vector<QString>::iterator ed = traData[traId].stationName.end(); it != ed; ++it)
		insert(*it,traId);
	return 1;
}
	
bool DataBase_Train::delTrain(QString traId)
{
	if (!trainExist(traId) || traData[traId].started)	return 0;	//failed, no such train or have sold tickets
	ttd::vector<QString>::iterator it = traData[traId].stationName.begin();
	for (ttd::vector<QString>::iterator ed = traData[traId].stationName.end(); it != ed; ++it)
		remove(*it,traId);
	return 1;
}
QDateTime DataBase_Train::getLeaveTime(QString train, QString station)
{
	int i = 0;
	for (ttd::vector<QString>::iterator it = traData[train].stationName.begin(), ra = traData[train].stationName.end();
		it != ra; i++, it++)	if (*it == station)	return traData[train].leaveTime[i];
}
QDateTime DataBase_Train::getReachTime(QString train, QString station)
{
	int i = 0;
	for (ttd::vector<QString>::iterator it = traData[train].stationName.begin(), ra = traData[train].stationName.end();
		it != ra; i++, it++)	if (*it == station)	return traData[train].reachTime[i];
}
bool DataBase_Train::modifyTrain(QString traId, int setnr, int stanr,
	 const ttd::vector<QString> &stan, const ttd::vector<int> &ma,
	 const ttd::vector<QDateTime> &rt, const ttd::vector<QDateTime> &lt,
	 const ttd::vector<QString> &set, const ttd::vector<int> &senr,
	 const ttd::vector<ttd::vector<int> > &ptb)
{
	if (!trainExist(traId) || traData[traId].started)	return 0;	//failed, no such train or have sold tickets
	delTrain(traId), createTrain(traId,setnr,stanr,stan,ma,rt,lt,set,senr,ptb);
 	return 1;
}
	
void DataBase_Train::openOneDay(QString traId, QDate dato)
{
	traData[traId].openOneDay(dato);
}
	
bool DataBase_Train::closeOneDay (QString traId, QDate datc)
{
	// if never opened, return 0
	return traData[traId].closeOneDay(datc);
}
	
int DataBase_Train::buyTickets (QString traId, QDate dat, QString lsta, QString ulsta, QString set, int num)
{
	if (num < 0 )	return -4;//num<0
	return traData[traId].buyTickets(dat,lsta,ulsta,set,num);
}
	
int DataBase_Train::cancelTickets (QString traId, QDate dat, QString lsta, QString ulsta, QString set, int num)
{
	return traData[traId].cancelTickets(dat,lsta,ulsta,set,num);
}
	
bool DataBase_Train::openDate (QString traId, QDate dat)
{
	return traData[traId].openDate(dat);
}
DataBase_Train::TrainRoute DataBase_Train::query_train(QString tra)
{
	return traData[tra].query_train();
}
bool DataBase_Train::insert(const QString&sta, const QString& add_ref)
{
	ttd::map<QString,ttd::vector<QString> >::iterator it = staData.find(sta);
	if (it == staData.end())	return 0;	//	no such station
	for (ttd::vector<QString>::iterator rator = it->second.begin(); rator != it->second.end(); rator++)
		if (*rator == add_ref)	return 0;	//	have exist
	staData[sta].push_back(add_ref);
	return 1;
}
bool DataBase_Train::remove(const QString&sta, const QString& mod_ref)
{
	ttd::map<QString,ttd::vector<QString> >::iterator it = staData.find(sta);
	if (it == staData.end())	return 0;	//no such station
	for (ttd::vector<QString>::iterator rator = it->second.begin(); rator != it->second.end(); rator++)
		if (*rator == mod_ref)	{it->second.erase(rator);	return 1;}	//exist and delete
	return 0;							//exist station, no train
	
}
ttd::vector<DataBase_Train::TrainRoute> DataBase_Train::queryOne(const QString &sta)
{
	ttd::vector<TrainRoute> ans;
	for (ttd::vector<QString>::iterator it(staData[sta].begin()), ra(staData[sta].end());
	 it != ra; ++it)	ans.push_back(traData[*it].query_train());
	return ans;
}
	
ttd::vector<DataBase_Train::QTrain> DataBase_Train::queryTwo(const QDate &dat, const QString &sta, const QString &stb)	
{
	ttd::vector<QTrain> tmp(bothPass(sta,stb));
	for (ttd::vector<QString>::iterator it(staData[sta].begin()), ra(staData[sta].end());
	 it != ra; ++it)	tmp.push_back(traData[*it].query_stationToStation(dat,sta,stb));
	return tmp;
}
ttd::vector<QString> DataBase_Train::bothPass(const QString &sta, const QString &stb)
{
	ttd::vector<QString> ans = staData[sta], tmp = staData[stb];
	for(int i = ans.size()-1; i >=0; i--)
	{
		bool ok = 0;
		for (int j = tmp.size()-1; j >= 0 ;j--)
			if (ans[i] == tmp[j])
			{
				for (int k = traData[ans[i]].stationNumber-1; k >= 0 ; k++)
					if (traData[ans[i]].stationName[k] == sta)	break;
					else if (traData[ans[i]].stationName[k] == stb)	{ok = 1;break;}
				break;
			}
		if (!ok)	ans.erase(i--);
	}
}
