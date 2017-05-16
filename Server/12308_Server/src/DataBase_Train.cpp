#include "include/DataBase_Train.h"

#include <QFile>
#include <QTest>
#include <QDataStream>
#include <QTextStream>

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
DataBase_Train::Train::Train()
{
	
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
DataBase_Train::Train::~Train (){ }
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
		for (int j = 0; j < stationNumber; j++) a.push_back(seatNumber[i]);
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
		--k, dat = dat.addDays(-k);
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
		for(int _=j; _ >= i; _--)
			salingDate[dat].restTickets[sid][_] -= num;
		started = 1;
		return (priceTable[sid][j]-priceTable[sid][i]);
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
		--k, dat = dat.addDays(-k);
		//int mn = seatNumber[sid];
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
	ans.seatNumber = seatNumber;
	ans.priceTable = priceTable;
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
		--k, dat = dat.addDays(-k);
		ans.ableToBuy = openDate(dat);
		if (!ans.ableToBuy)	return ans;
		ans.trainID = trainID;
		ans.seatTypeNumber = seatTypeNumber;
		ans.loadStation = lsta, ans.unLoadStation = ulsta;
		ans.seatType = seatType;
		ans.loadStationLeaveTime = QDateTime(dat.addDays(leaveTime[i].date().day()),leaveTime[i].time());
		ans.unLoadStationReachTime = QDateTime(dat.addDays(reachTime[j].date().day()),reachTime[j].time());
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
		return ans;
	}
	throw(0);
}


DataBase_Train::DataBase_Train(const QString &Name)
	:DataBase_Base(Name)
{
	traData.clear();
	staData.clear();
}
DataBase_Train::~DataBase_Train()
{ saveData(); }
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
 	if (trainExist(traId))	return 0;	//fail, train existed or have sold tickets
	ttd::map<QString, Train>::iterator ti
			= traData.insert( ttd::make_pair(traId, Train(traId,setnr,stanr,stan,ma,rt,lt,set,senr,ptb)) ).first;
	ttd::vector<QString>::iterator it = ti->second.stationName.begin();
	for (ttd::vector<QString>::iterator ed = ti->second.stationName.end(); it != ed; ++it)
		insert(*it,traId);
	return 1;
}
	
bool DataBase_Train::delTrain(QString traId)
{
	if (!trainExist(traId) || traData[traId].started)	return 0;	//failed, no such train or have sold tickets
	ttd::vector<QString>::iterator it = traData[traId].stationName.begin();
	for (ttd::vector<QString>::iterator ed = traData[traId].stationName.end(); it != ed; ++it)
		remove(*it,traId);
	traData.erase(traData.find(traId));
	return 1;
}
QDateTime DataBase_Train::getLeaveTime(QString train, QString station)
{
	int i = 0;
	for (ttd::vector<QString>::iterator it = traData[train].stationName.begin(), ra = traData[train].stationName.end();
		it != ra; i++, it++)	if (*it == station)	return traData[train].leaveTime[i];
	throw(0);
}
QDateTime DataBase_Train::getReachTime(QString train, QString station)
{
	int i = 0;
	for (ttd::vector<QString>::iterator it = traData[train].stationName.begin(), ra = traData[train].stationName.end();
		it != ra; i++, it++)	if (*it == station)	return traData[train].reachTime[i];
	throw(0);
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
	
int DataBase_Train::buyTickets
	(QString traId, QDate dat,
	 QString lsta, QString ulsta,
	 QString set, int num)
{
	if (num < 0 )	return -4;//num<0
	return traData[traId].buyTickets(dat,lsta,ulsta,set,num);
}
	
int DataBase_Train::cancelTickets
	(QString traId, QDate dat,
	 QString lsta, QString ulsta,
	 QString set, int num)
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
	staData[sta];
	ttd::map<QString,ttd::vector<QString> >::iterator it = staData.find(sta);
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
	ttd::vector<QTrain> tmp;
	ttd::vector<QString> a(bothPass(sta,stb));
	for (ttd::vector<QString>::iterator it(a.begin()), ra(a.end()); it != ra; ++it)
	{
		//qDebug() << *it ;
		tmp.push_back(traData[*it].query_stationToStation(dat,sta,stb));
		if(!tmp[tmp.size()-1].ableToBuy)	tmp.pop_back();
	}
	return tmp;
}
ttd::vector<QString> DataBase_Train::bothPass(const QString &sta, const QString &stb)
{
	ttd::vector<QString> ans = staData[sta];
	const ttd::vector<QString> &tmp = staData[stb];
	for(int i = ans.size()-1; i >=0; i--)
	{
		bool ok = 0;
		for (int j = tmp.size()-1; j >= 0 ;j--)
			if (ans[i] == tmp[j])
			{
				for (int k = traData[ans[i]].stationNumber-1; k >= 0 ; k--)
					if (traData[ans[i]].stationName[k] == sta)	break;
					else if (traData[ans[i]].stationName[k] == stb)	{ok = 1;break;}
				break;
			}
		if (!ok)	ans.erase(i);
	}
	return ans;
}



QDataStream& operator << (QDataStream& out, const DataBase_Train::QTrain &data)
{
	out << data.ableToBuy << data.trainID
		<< data.seatTypeNumber
		<< data.loadStation << data.unLoadStation
		<< data.seatType << data.price << data.seatNumber
		<< data.loadStationLeaveTime << data.unLoadStationReachTime;

	return out;
}
QDataStream& operator >> (QDataStream& in, DataBase_Train::QTrain &data)
{
	in >> data.ableToBuy >> data.trainID
			>> data.seatTypeNumber
			>> data.loadStation >> data.unLoadStation
			>> data.seatType >> data.price >> data.seatNumber
			>> data.loadStationLeaveTime >> data.unLoadStationReachTime;
	return in;
}
QDataStream& operator << (QDataStream& out, const DataBase_Train::TrainRoute &data)
{
	out << data.trainID
		<< data.seatTypeNumber << data.stationNumber
		<< data.stationName << data.mileAge
		<< data.reachTime << data.leaveTime
		<< data.seatType << data.seatNumber
		<< data.priceTable;
	return out;
}
QDataStream& operator >> (QDataStream& in, DataBase_Train::TrainRoute &data)
{
	in >> data.trainID
			>> data.seatTypeNumber >> data.stationNumber
			>> data.stationName >> data.mileAge
			>> data.reachTime >> data.leaveTime
			>> data.seatType >> data.seatNumber
			>> data.priceTable;
	return in;
	return in;
}
QDataStream& operator << (QDataStream& out, const DataBase_Train::Train &data)
{
	out << data.trainID << data.started
		<< data.seatTypeNumber << data.stationNumber
		<< data.stationName << data.mileAge
		<< data.reachTime << data.leaveTime
		<< data.seatType << data.seatNumber
		<< data.priceTable << data.salingDate;
	return out;
}

QDataStream& operator >> (QDataStream& in, DataBase_Train::Train &data)
{
	in >> data.trainID >> data.started
			>> data.seatTypeNumber >> data.stationNumber
			>> data.stationName >> data.mileAge
			>> data.reachTime >> data.leaveTime
			>> data.seatType >> data.seatNumber
			>> data.priceTable >> data.salingDate;
	return in;
}

QDataStream& operator << (QDataStream& out, const DataBase_Train::Train::TicketsPerDay &data)
{
	out << data.ableToBuy << data.restTickets;
	return out;
}

QDataStream& operator >> (QDataStream& in, DataBase_Train::Train::TicketsPerDay &data)
{
	in >> data.ableToBuy >> data.restTickets;
	return in;
}

void DataBase_Train::loadData()
{
	QFile file( dataBase_name + "_Train" + ".dat" );
	if(!file.open(QIODevice::ReadOnly))
		return;
	QDataStream in(&file);
	in.setVersion(QDataStream::Qt_5_0);
	in >> traData;
	in >> staData;
	file.close();
}
void DataBase_Train::saveData()
{
	QFile file( dataBase_name + "_Train" + ".dat" );
	file.open(QIODevice::WriteOnly);
	QDataStream out(&file);
	out.setVersion(QDataStream::Qt_5_0);
	out << traData << staData;
	file.close();
}

void DataBase_Train::loadData_raw(const QString &FileName)
{
	int total = 0;
	QFile file(FileName);	//file
	if (!file.open(QFile::ReadOnly|QFile::Text))	throw(0);//open failed
	QTextStream in(&file);
	in.setCodec("UTF-8");
	QString traId;
	int setnr, stanr;
	ttd::vector<QString> stan,//station name
						set;//stetypename;
	ttd::vector<int> ma,//miles
					sen;//seat number of all kinds of tickets, initally 2000
	ttd::vector<QDateTime> rt, lt;//reach and leave time

	ttd::vector<ttd::vector<int> > ptb;//price table

	QStringList qslist;
	bool ok;
	QString line, now;
	while (!in.atEnd())
	{

		ok = 0;
		stanr = setnr = 0;
		set.clear(), ptb.clear();
		stan.clear(), lt.clear();
		ma.clear();sen.clear();rt.clear();

		traId = in.readLine();
		qslist = in.readLine().split(',');
		setnr = qslist.size()-5;
		for(int i=5;i<qslist.size();++i)
		{
			set.push_back(qslist[i]);
			ptb.push_back(ttd::vector<int>() );
			sen.push_back(2000);
		}
		while (!in.atEnd() && !ok)
		{
			qslist = in.readLine().split(',');

			stanr++;

			stan.push_back(qslist[0]);

			QDate day = QDate::fromString(qslist[1],"yyyy-MM-dd");
			day = day.addDays(-27);			//yy and mm is useless

			if(qslist[2] == "起点站")
				rt.push_back(QDateTime(day));
			else
				rt.push_back(QDateTime(day,QTime::fromString(qslist[2],"hh:mm") ));


			if(qslist[3] == "终到站")
				rt.push_back(QDateTime(day)),ok = 1;
			else
				lt.push_back(QDateTime(day,QTime::fromString(qslist[3],"hh:mm")));

			ma.push_back(
				( qslist[4].left(qslist[4].size()-2) ).toInt()
				);

			for( int i = 0; i < setnr; ++i )
			if(qslist[i+5].size()==1)
				ptb[i].push_back(-1);
			else
				ptb[i].push_back( int(qslist[i+5].mid(1).toDouble() * 100) );
		}
		if ( createTrain(traId,setnr,stanr,stan,ma,rt,lt,set,sen,ptb) )
		{
			total++;
			ttd::map<QString, Train>::iterator ti
					= traData.find(traId);
			QDate firstDay(2017,3,28);
			//30day?
			for(int i=0; i<30;++i)
			{
				ti->second.openOneDay(firstDay);
				firstDay = firstDay.addDays(1);
			}
		}
	}
	file.close();
	/*
		8398 IN TOTAL
		10 repeated
		D295/D298	G2331/G2334		G7575/G7578		C1031		C1034
		Z1			Z9				Z54				Z62			Z63

		all train have 2 or 3 seat types
						at most 40 stations
						2:775
						3:794
						4:989
						5:997
						6:970
						7:670
						8:555
						9:483
						10:391
						11:287
						12:271
						13:198
						14:158
						15:126
						16:104
						17:80
						18:66
						19:72
						20:66
						21:59
						22:52
						23:36
						24:35
						25:33
						26:30
						27:17
						28:17
						29:16
						30:11
						31:3
						32:8
						33:6
						34:5
						35:0
						36:4
						37:1
						38:2
						39:0
						40:1

	*/
}
