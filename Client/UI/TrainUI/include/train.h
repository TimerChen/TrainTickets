/*
 *	Writed by Yanxi Lin.
 *	Modified by Jingxiao Chen.
 *
 */

#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <cstdio>
#include <iostream>
#include "include/map.hpp"
#include <QDateTime>

//Tickets which have bought.
struct Ticket
{
	static long long ticketNumber = 0LL;

	long long ticketID;
	QString userName;
	QString loadStation, unLoadStation;
	QString trainID;
	QDateTime loadTime, unLoadTime;
	int price;
	QString seatType;
	Ticket ();
    Ticket (const QString &un, const QString &ls,
			const QString &us, const QString &tID,
			const QDateTime &lt, const QDateTime &ut,
			int pr, const QString &st);

	~Ticket () ;

	bool operator <  (const Ticket &t1) const ;
	bool operator == (const Ticket &t1) const ;

};


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
	QTime loadStationLeaveTime, unLoadStationReachTime;
};

//Reply of train query.
struct TrainRoute
{
	QString trainID;
	int seatTypeNumber, stationNumber;
	ttd::vector<QString> stationName;
	ttd::vector<int> mileAge;
	ttd::vector<QTime> reachTime;
	ttd::vector<QTime> leaveTime;
	ttd::vector<QString> seatType;
};

class Train
{
private:

	QString trainID;
	bool tooLateToReconstructe;
	int seatTypeNumber, stationNumber;
	ttd::vector<QString>stationName;
	ttd::vector<int> mileAge;
	ttd::vector<QTime> reachTime;
	ttd::vector<QTime> leaveTime;
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
	Train (const QString &tID = "");
 	Train (const QString &tID, int setnr, int stanr,
		const ttd::vector<QString> &stan, const ttd::vector<int> &ma,
		const ttd::vector<QTime> &rt, const ttd::vector<QTime> &lt,
		const ttd::vector<QString> &set, const ttd::vector<int> &senr,
		const ttd::vector<ttd::vector<int> > &ptb);

	~Train () ;

	bool isItTooLateToReconstructe ();

	bool reconstructe (int setnr, int stanr,
				const ttd::vector<QString> &stan,
				const ttd::vector<int> &ma,
				const ttd::vector<QTime> &rt, const ttd::vector<QTime> &lt,
				const ttd::vector<QString> &set, const ttd::vector<int> &senr,
				const ttd::vector<ttd::vector<int> > &ptb);

	void openOneDay (QDate dato);

	bool closeOneDay (QDate datc);

	int buyTickets (QDate dat, QString lsta, QString ulsta,
					QString set, int num);

	int cancelTickets (QDate dat, QString lsta, QString ulsta,
					QString set, int num);

	bool openDate (QDate dat);

	QTrain query_stationToStation (QDate dat, QString lsta, QString ulsta);

	TrainRoute query_train ();

};

#endif
