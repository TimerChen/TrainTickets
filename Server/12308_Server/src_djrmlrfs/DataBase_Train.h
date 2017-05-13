#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <cstdio>
#include <iostream>
#include "include/map.hpp"
#include "DataBase.h"
#include <QDateTime>
class DataBase_Train:public DataBase_Base
{
	//Reply of station-to-station  query.
	struct QTrain
	{
		bool ableToBuy;
		QString trainID;
		int seatTypeNumber;
		QString loadStation, unLoadStation;
		ttd::vector<QString> seatType;
		ttd::vector<int> price;
		ttd::vector<int> seatNumber;
		QDateTime loadStationLeaveTime, unLoadStationReachTime;
	};

	//Reply of train query.
	struct TrainRoute
	{
		QString trainID;
		int seatTypeNumber, stationNumber;
		ttd::vector<QString> stationName;
		ttd::vector<int> mileAge;
		ttd::vector<QDateTime> reachTime;
		ttd::vector<QDateTime> leaveTime;
		ttd::vector<QString> seatType;
	};

	class Train
	{
	private:
	
		QString trainID;
		bool started;
		int seatTypeNumber, stationNumber;
		ttd::vector<QString>stationName;
		ttd::vector<int> mileAge;
		ttd::vector<QDateTime> reachTime;
		ttd::vector<QDateTime> leaveTime;
		ttd::vector<QString> seatType;
		vector<int> seatNumber;
		vector<vector<int> > priceTable;
	
		struct TicketsPerDay
		{
			bool ableToBuy;
			vector<vector<int> > restTickets;
		};
		ttd::map<QDate, TicketsPerDay> salingDate;
	
	
		struct TrainPoint
		{
			int seatTypePoint;
			int loadStationPoint;
			int unLoadStationPoint;
		};
	
		TrainPoint getPoint (QString lsta, QString ulsta, QString set);
	
		struct RestTicketsInformation
		{
			int restTicketsNumber;
			int restTicketsPrice;
			TrainPoint restTicketsPoint;
		};
	
		RestTicketsInformation showRestTickets (QDate dat, QString lsta,
												QString ulsta, QString set);
	
	
	public:
	 	Train (const QString &tID, int setnr, int stanr,
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
		Train operator=(const Train &a)
		{
			trainID = a.trainD;
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
		~Train ()
		{
			
		}
	
		bool canModify ()
		{
			return (!started);
		}
	
		void openOneDay (QDate dato)
		{
			if (salingDate.count(dato))
			{
				salingDate[dato].ableToBuy = true;
				return;
			}
			salingDate[dato].ableToBuy = true;
			for (int i = 0; i < seatTypeNumber; i++)
			{
				salingDate[dato].restTickets.push_back(ttd::vector <int>);
				for (int j = 0; j < stationNumber - 1; j++) salingDate[dato].restTickets[i].push_back(seatNumber[i]);
			}
		}
	
		bool closeOneDay (QDate datc)
		{
			if (!salingDate.count(datc))	return 0;
			salingDate[datc].ableToBuy = 0;
			return 1;
		}
	
		int buyTickets (QDate dat, QString lsta, QString ulsta, QString set, int num)
		{				//dat is the exact day , maybe 3.29 or 3.30
			int sid;
			for (sid = 0; sid < seatType.size(); sid++)	if (seatType[sid] == set)	break;
			if (sid == seatType.size())	return -2;	// no such kind of seat
			for (int i = 0; i < stationName.size(); i++)	if (stationName[i] == lsta)
			{
				int k = leaveTime[i].date().day();
				dat = dat.addDays(-k);
				if (!salingData[dat].ableToBuy)	return -1;	//unable to buy that day;
				int mn = seatNumber[sid];
				int j = i;
				for(; j < stationName.size(); j++)
				{
					mn = min(mn,salingDate[dat].restTickets[sid][j]);
					if (mn < num)	return -4;	//no enough tickets
					if (stationName[j] == ulsta)	break;
				}				
				if (j == stationName.size())	return -3;	// no such station
				for(; j >= i; j--)
					salingDate[dat].restTickets[sid][j] -= num;
				started = 1;
				return num*(priceTable[sid][j]-priceTable[sid][i]);
			}
			return -3;	// no such station;
		}
		int cancelTickets (QDate dat, QString lsta, QString ulsta, QString set, int num)
		{
			// in account class, you can check weather can be cancel;
			int sid;
			for (sid = 0; sid < seatType.size(); sid++)	if (seatType[sid] == set)	break;
			for (int i = 0; i < stationName.size(); i++)	if (stationName[i] == lsta)
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
		bool openDate (QDate dat)
		{
			if (!salingDate.count(dat))	return 0;
			return salingData[dat].ableToBuy;
		}
		TrainRoute query_train();
		QTrain query_stationToStation(QDate dat, QString lsta, QString ulsta)
		{
			QTrain ans;
			for (int i = 0; i < stationName.size(); i++)	if (stationName[i] == lsta)
			{
				int j = i;
				for(; stationName[j] != ulsta; j++);

				int k = leaveTime[i].date().day();
				dat = dat.addDays(-k);
				ans.ableToBuy = openDat(dat);

				ans.trainID = trainID;
				ans.seatTypeNumber = seatTypeNumber;
				ans.loadStation = sta, ans.unLoadStation = stb;
				ans.seatType = seatType;

				ans.loadStationLeaveTime = leaveTime[i],;
				ans.unLoadStationReachTime = reachTime[j];
				for (int _ = 0; _ < seatType; _++)
				{
					ans.price.push_back(priceTable[_][j]-priceTable[_][i]);
					int mn = 2e9;
					for (k = i; k <= j; k++)
					{
						int tt = salineData[dat].restTickets[_][k];
						if (mn > tt)	mn = tt;
					}
					ans.seatNumber.push_back(mn);
				}
			}
			return ans;
		}
	};

			}
		}
	};
private:
	ttd::map<QString,Train>traData;
	ttd::map<QString,ttd::vector<QString> > staData;
	shared_ptr<DataBase_Account> accUse;
public:
	DataBase_Train()
	{
		traData.clear();
		staData.clear();
	}
	Station::~Station()
	{
	}
	void setAccuse(	shared_ptr<DataBase_Account> acc)
	{
		accUse = acc;
	}
	bool trainExist(QString traId)
	{
		return traData.count(traId);
	}
	
	bool createTrain(QString traId, int setnr, int stanr,
	 const ttd::vector<QString> &stan, const ttd::vector<int> &ma,
	 const ttd::vector<QDateTime> &rt, const ttd::vector<QDateTime> &lt,
	 const ttd::vector<QString> &set, const ttd::vector<int> &senr,
	 const ttd::vector<ttd::vector<int> > &ptb)
	{
	 	if (trainExist(traID) || !traData[traId].canModify))	return 0;	//fail, train existed or have sold tickets
	 	traData[traID] = Train(traId,setnr,stanr,stan,ma,rt,lt,set,senr,ptb);
	 	ttd::vector<QString>::iterator it = traData[traId].stationName.begin();
		for (ttd::vector<QString>::iterator ed = traData[traId].stationName.end(); it != ed; ++it)
			insert(*it,traId);
		return 1;
	}
	
	bool delTrain(QString traId)
	{
		if (!trainExist(traID) || !traData[traId].canModify))	return 0;	//failed, no such train or have sold tickets
		ttd::vector<QString>::iterator it = traData[traId].stationName.begin();
		for (ttd::vector<QString>::iterator ed = traData[traId].stationName.end(); it != ed; ++it)
			remove(*it,traId);
		return 1;
	}
	QDateTime getLeaveTime(QString train, Qstring station)
	{
		int i = 0;
		for (ttd::vector<QString>::iterator it = traData[train].stationName.begin(), ra = traData[train].stationName.end();
			it != ra; i++, it++)	if (*it == station)	return traData[train].leaveTime[i];
	}
	QDateTime getReachTime(QString train, Qstring station)
	{
		int i = 0;
		for (ttd::vector<QString>::iterator it = traData[train].stationName.begin(), ra = traData[train].stationName.end();
			it != ra; i++, it++)	if (*it == station)	return traData[train].reachTime[i];
	}
	bool modifyTrain(QString traId, int setnr, int stanr,
	 const ttd::vector<QString> &stan, const ttd::vector<int> &ma,
	 const ttd::vector<QDateTime> &rt, const ttd::vector<QDateTime> &lt,
	 const ttd::vector<QString> &set, const ttd::vector<int> &senr,
	 const ttd::vector<ttd::vector<int> > &ptb)
	{
		if (!trainExist(traID) || !traData[traId].canModify))	return 0;	//failed, no such train or have sold tickets
		delTrain(traId), createTrain(traId,setnr,stanr,stan,ma,rt,lt,set,senr,ptb);
	 	return 1;
	}
	
	void openOneDay(QString traId, QDate dato)
	{
		traData[trId].openOneDay(dato);
	}
	bool closeOneDay (QString traId, QDate datc)
	{
		// if never opened, return 0
		return traData[traId].closeOneDay(datc);
	}
	
	int buyTickets (QString traId, QDate dat, QString lsta, QString ulsta, QString set, int num)
	{
		if (num < 0 )	return -4;//num<0
		return traData[traId].buyTickets(dat,lsta,ulsta,set,num);
	}
	
	int cancelTickets (QString traId, QDate dat, QString lsta, QString ulsta, QString set, int num)
	{
		return traData[traId].cancelTickets(dat,lsta,ulsta,set,num);
	}
	
	bool openDate (QString traId, QDate dat)
	{
		return traData[trId].openDate(dat);
	}
	QTrain query_stationToStation (QDate dat, QString lsta, QString ulsta);
	
	TrainRoute query_train(QString tra)
	{
		return traData[tra].query_train();
	}
	bool insert(const QString&sta, const QString& add_ref)
	{
		ttd::map<QString,ttd::vector<QString> >::iterator it = staData.find(sta);
		if (it == staData.end())	return 0;	//	no such station
		for (ttd::vector<QString>::iterator rator = it->second.begin(); rator != it->second.end(); rator++)
			if (*rator == mod_ref)	return 0;	//	have exist
		staData[sta].push_back(add_ref);
		return 1;
	}
	bool remove(const QString&sta, const QString& mod_ref)
	{
		ttd::map<QString,ttd::vector<QString> >::iterator it = staData.find(sta);
		if (it == staData.end())	return 0;	//no such station
		for (ttd::vector<QString>::iterator rator = it->second.begin(); rator != it->second.end(); rator++)
			if (*rator == mod_ref)	{it->second.erase(rator);	return 1;}	//exist and delete
		return 0;							//exist station, no train
		
	}
	ttd::vector<TrainRoute> queryOne(const QString &sta)
	{
		ttd::vector<TrainRoute> ans;
		for (ttd::vector<QString>::iterator it(staData[sta].begin()), ra(staData[sta].end());
		 it != ra, ++it)	ans.push_back(traData[*it].query_train());
		return ans;
	}
	ttd::vector<QTrain> queryTwo(const Date &dat, const QString &sta, const QString &stb)	
	{
		ttd::vector<QString> tmp(bothPass(sta,stb));
		for (ttd::vector<QString>::iterator it(staData[sta].begin()), ra(staData[sta].end());
		 it != ra, ++it)	ans.push_back(traData[*it].query_stationToStation(dat,sta,stb));
		return ans;
	}
	ttd::vector<QString> bothPass(const QString &sta, const QString &stb)
	{
		ttd::vector<QString> ans = staData[sta], tmp = staData[stb];
		for(int i = 0; i < ans.size(); i++)
		{
			bool ok = 0;
			for (int j = 0; j < tmp.size(); j++)
				if (ans[i] == tmp[j])
				{
					for (int k = 0; k < traData[ans[i]].size(); k++)
						if (traData[ans[i]].stationName[k] == sta)	{ok = 1;break;}
						else if (traData[ans[i]].stationName[k] == stb)	break;
					break;
				}
			if (!ok)	ans.erase(i--);
		}
	}
}
#endif
