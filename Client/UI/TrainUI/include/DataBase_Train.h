#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <cstdio>
#include <iostream>
#include "map.hpp"
#include "include/database.h"
#include <QString>
#include <QDateTime>

class DataBase_Train:public DataBase_Base
{
public:
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
		ttd::vector<int> seatNumber;
		ttd::vector<ttd::vector<int> > priceTable;
	};

	class Train
	{
	public:

		QString trainID;
		bool started;
		int seatTypeNumber, stationNumber;
		ttd::vector<QString>stationName;
		ttd::vector<int> mileAge;
		ttd::vector<QDateTime> reachTime;
		ttd::vector<QDateTime> leaveTime;
		ttd::vector<QString> seatType;
		ttd::vector<int> seatNumber;
		ttd::vector<ttd::vector<int> > priceTable;

		struct TicketsPerDay
		{
			bool ableToBuy;
			ttd::vector<ttd::vector<int> > restTickets;
		};

		ttd::map<QDate, TicketsPerDay> salingDate;
		Train();
		Train (const QString &tID, int setnr, int stanr,
			const ttd::vector<QString> &stan, const ttd::vector<int> &ma,
			const ttd::vector<QDateTime> &rt, const ttd::vector<QDateTime> &lt,
			const ttd::vector<QString> &set, const ttd::vector<int> &senr,
			const ttd::vector<ttd::vector<int> > &ptb);
		Train operator=(const Train &a);
		~Train ();

		void openOneDay (QDate dato);
		bool closeOneDay (QDate datc);
		int buyTickets (QDate dat, QString lsta, QString ulsta, QString set, int num);
		int cancelTickets (QDate dat, QString lsta, QString ulsta, QString set, int num);
		bool openDate (QDate dat);
		TrainRoute query_train();
		QTrain query_stationToStation(QDate dat, QString lsta, QString ulsta);
	};
private:
	ttd::map<QString,Train>traData;
	ttd::map<QString,ttd::vector<QString> > staData;
public:
	DataBase_Train( const QString&Name = "Default" );

	void loadData();
	void loadData_raw(const QString &FileName);
	void saveData();

	bool trainExist(QString traId);
	bool createTrain(QString traId, int setnr, int stanr,
	 const ttd::vector<QString> &stan, const ttd::vector<int> &ma,
	 const ttd::vector<QDateTime> &rt, const ttd::vector<QDateTime> &lt,
	 const ttd::vector<QString> &set, const ttd::vector<int> &senr,
	 const ttd::vector<ttd::vector<int> > &ptb);

	bool delTrain(QString traId);
	QDateTime getLeaveTime(QString train, QString station);
	QDateTime getReachTime(QString train, QString station);
	bool modifyTrain(QString traId, int setnr, int stanr,
	 const ttd::vector<QString> &stan, const ttd::vector<int> &ma,
	 const ttd::vector<QDateTime> &rt, const ttd::vector<QDateTime> &lt,
	 const ttd::vector<QString> &set, const ttd::vector<int> &senr,
	 const ttd::vector<ttd::vector<int> > &ptb);

	void openOneDay(QString traId, QDate dato);
	bool closeOneDay (QString traId, QDate datc);

	int buyTickets (QString traId, QDate dat, QString lsta, QString ulsta, QString set, int num);

	int cancelTickets (QString traId, QDate dat, QString lsta, QString ulsta, QString set, int num);

	bool openDate (QString traId, QDate dat);
	QTrain query_stationToStation (QDate dat, QString lsta, QString ulsta);

	TrainRoute query_train(QString tra);
	bool insert(const QString&sta, const QString& add_ref);
	bool remove(const QString&sta, const QString& mod_ref);
	ttd::vector<TrainRoute> queryOne(const QString &sta);
	ttd::vector<QTrain> queryTwo(const QDate &dat, const QString &sta, const QString &stb);
	ttd::vector<QString> bothPass(const QString &sta, const QString &stb);
};

QDataStream &operator <<(QDataStream &out, const DataBase_Train::QTrain &data);
QDataStream &operator >>(QDataStream &in, DataBase_Train::QTrain &data);

QDataStream &operator <<(QDataStream &out, const DataBase_Train::TrainRoute &data);
QDataStream &operator >>(QDataStream &in, DataBase_Train::TrainRoute &data);

QDataStream &operator <<(QDataStream &out, const DataBase_Train::Train &data);
QDataStream &operator >>(QDataStream &in, DataBase_Train::Train &data);

#endif
