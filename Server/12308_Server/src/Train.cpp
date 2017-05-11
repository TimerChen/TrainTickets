#ifndef TTD_TRAIN_HPP
#define TTD_TRAIN_HPP

#include "include/train.h"
#include "include/map.hpp"

#include <QDateTime>

Ticket::Ticket(){}

Ticket::Ticket (const QString &un, const QString &ls, const QString &us, const QString &tID, const QDateTime &lt, const QDateTime &ut, int pr, const QString &st) {
	ticketID = ticketNumber;
	ticketNumber++;
	userName = un;
	loadStation = ls;
	unLoadStation = us;
	trainID = tID;
	loadTime = lt;
	unLoadTime = ut;
	price = pr;
	seatType = st;
}

Ticket::~Ticket () {}

bool operator < (const Ticket &t1) const {
	if (userName < t1.userName) return true;
	if (userName > t1.userName) return false;
	if (trainID < t1.trainID) return true;
	if (trainID > t1.trainID) return false;
	if (loadStation < t1.loadStation) return true;
	if (loadStation > t1.loadStation) return false;
	if (unLoadStation < t1.unLoadStation) return true;
	if (unLoadStation > t1.unLoadStation) return false;
	if (seatType < t1.seatType) return true;
	if (seatType > t1.seatType) return false;
}

bool operator == (const Ticket &t1) const {
	if (userName == t1.userName && trainID == t1.trainID && loadStation == t1.loadStation && unLoadStation == t1.unLoadStation && seatType == t1.seatType) return true;
	else return false;
}






Train::Train (const QString &tID, int setnr, int stanr, const ttd::vector <QString> &stan, const ttd::vector <int> &ma, const ttd::vector <QTime> &rt, const ttd::vector <QTime> &lt, const ttd::vector <QString> &set, const ttd::vector <int> &senr, const ttd::vector < ttd::vector <int> > &ptb) {
	tooLateToReconstructe = false;
	trainID = tID;
	seatTypeNumber = setnr;
	stationNumber = stanr;
	stationName = stan;
	mileAge = ma;
	reachTime = rt;
	leaveTime = lt;
	seatType = set;
	seatNumber = senr;
	priceTable = ptb;
}

Train::~Train () {}

bool Train::isItTooLateToReconstructe () {
	return tooLateToReconstructe;
}

bool Train::reconstructe (int setnr, int stanr, const ttd::vector <QString> &stan, const ttd::vector <int> &ma, const ttd::vector <QTime> &rt, const ttd::vector <QTime> &lt, const ttd::vector <QString> &set, const ttd::vector <int> &senr, const ttd::vector <ttd::vector <int> > &ptb) {
	if (tooLateToReconstructe) return false;

	salingDate.clear ();

	seatTypeNumber = setnr;
	stationNumber = stanr;
	stationName = stan;
	mileAge = ma;
	reachTime = rt;
	leaveTime = lt;
	seatType = set;
	seatNumber = senr;
	priceTable = ptb;

	return true;
}

void Train::openOneDay (QDate dato) {
	if (salingDate.find (dato)) {
		salingDate[dato].ableToBuy = true;
		return;
	}
	salingDate[dato].ableToBuy = true;
	for (int i = 0; i < seatTypeNumber; i++) {
		salingDate[dato].restTickets.push_back (ttd::vector <int>);
		for (int j = 0; j < stationNumber - 1; j++) salingDate[dato].restTickets[i].push_back (seatNumber[i]);
	}
}

bool Train::closeOneDay (QDate datc) {
	if (!salingDate.find (datc)) {
		return false;
	}
	salingDate[datc].ableToBuy = false;
	return true;
}


Train::TrainPoint getPoint (QString lsta, QString ulsta, QString set) {
	TrainPoint tp;
	tp.seatTypePoint = -1;
	tp.loadStationPoint = -1;
	tp.unLoadStationPoint = -1;
	bool fi = false;
	int x, y1, y2;
	for (x = 0; x < seatTypeNumber; x++) {
		if (seatType[x] == set) {
			fi = true;
			break;
		}
	}
	if (!fi) return tp;
	fi = false;
	for (y1 = 0; y1 < stationNumber; y1++) {
		if (stationName[y1] == lsta) {
			fi = true;
			break;
		}
	}
	if (!fi) return tp;
	fi = false;
	for (y2 = y1 + 1; y2 < stationNumber; y2++) {
		if (stationName[y2] == ulsta) {
			fi = true;
			break;
		}
	}
	if (!fi) return tp;
	tp.seatTypePoint = x;
	tp.loadStationPoint = y1;
	tp.unLoadStationPoint = y2;
}


RestTicketsInformation Train::howRestTickets (QDate dat, QString lsta, QString ulsta, QString set) {
	RestTicketsInformation rti;
	rti.restTicketsNumber = -1;
	rti.restTicketsPrice = -1;
	rti.restTicketsPoint = getPoint (lsta, ulsta, set);
	if (rti.restTicketsPoint.seatTypePoint == -1) return rti;
	int x = rti.restTicketsPoint.seatTypePoint;
	int y1 = rti.restTicketsPoint.loadStationPoint;
	int y2 = rti.restTicketsPoint.unLoadStationPoint;
	rti.restTicketsPrice = priceTable[x][y2] - priceTable[x][y1];
	if (!salingDate.find (dat)) return rti;
	if (!salingDate[dat].ableToBuy) return rti;
	for (int i = y1; i < y2; i++) {
		if (rti.restTicketsNumber == -1 || rti.restTicketsNumber > salingDate[dat].restTickets[x][i]) rti.restTicketsNumber = salingDate[dat].restTickets[x][i];
	}
	return rti;
}

int Train::buyTickets (QDate dat, QString lsta, QString ulsta, QString set, int num) {
	RestTicketsInformation rti = showRestTickets (dat, lsta, ulsta, set);
	if (restTicketsPrice == -1 || restTicketsNumber <= num) return 0;
	for (int i = rti.restTicketsPoint.loadStationPoint; i < rti.restTicketsPoint.unLoadStationPoint; i++) {
		salingDate[dat].restTickets[rti.restTicketsPoint.seatTypePoint][i] -= num;
	}
	return rti.restTicketsPrice * num;
}

int Train::cancelTickets (QDate dat, QString lsta, QString ulsta, QString set, int num) {
	RestTicketsInformation rti = showRestTickets (dat, lsta, ulsta, set);
	for (int i = rti.restTicketsPoint.loadStationPoint; i < rti.restTicketsPoint.unLoadStationPoint; i++) {
		salingDate[dat].restTickets[rti.restTicketsPoint.seatTypePoint][i] += num;
	}
	return rti.restTicketsPrice * num;
}

bool Train::openDate (QDate dat) {
	if (!salingDate.find (dat)) return false;
	else return salingDate[dat].ableToBuy;
}

QTrain Train::ask (QDate dat, QString lsta, QString ulsta) {
	QTrain qt;
	TrainPoint tp = getPoint (lsta, ulsta, seatType[0]);
	if (!salingDate.find (dat)) qt.ableToBuy = false;
	else qt.ableToBuy = salingDate[dat].ableToBuy;
	qt.trainID = trainID;
	qt.seatTypeNumber = seatTypeNumber;
	qt.seatType = seatType;
	qt.loadStation = lsta;
	qt.unLoadStation = ulsta;
	for (int i = 0; i < seatTypeNumber; i++) {
		RestTicketsInformation rti = showRestTickets (dat, lsta, ulsta, seatType[i]);
		qt.price.push_back (rti.restTicketsPrice);
		qt.number.push_back (rti.restTicketsNumber);
	}
	qt.loadStationLeaveTime = leaveTime[tp.loadStationPoint];
	qt.unLoadStationReachTime = reachTime[tp.unLoadStationPoint];
	return qt;
}

TrainRoute Train::ask () {
	TrainRoute tr;

	tr.trainID = trainID;
	tr.seatTypeNumber = seatTypeNumber;
	tr.stationNumber = stationNumber;
	tr.stationName = stationName;
	tr.mileAge = mileAge;
	tr.reachTime = reachTime;
	tr.leaveTime = leaveTime;
	tr.seatType = seatType;

	return tr;
}


#endif
