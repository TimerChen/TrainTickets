/*
 *	Writed by Yanxi Lin.
 *	Modified by Jingxiao Chen.
 *
 */

#include "include/train.h"
#include "include/map.hpp"

#include <QDateTime>

long long Ticket::ticketNumber = 0LL;

Ticket::Ticket(){}

Ticket::Ticket (const QString &un, const QString &ls,
				const QString &us, const QString &tID,
				const QDateTime &lt, const QDateTime &ut,
				int pr, const QString &st)
{
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

bool operator < (const Ticket &t1, const Ticket &t2)
{
	if (t1.userName < t2.userName) return true;
	if (t1.userName > t2.userName) return false;
	if (t1.trainID < t2.trainID) return true;
	if (t1.trainID > t2.trainID) return false;
	if (t1.loadStation < t2.loadStation) return true;
	if (t1.loadStation > t2.loadStation) return false;
	if (t1.unLoadStation < t2.unLoadStation) return true;
	if (t1.unLoadStation > t2.unLoadStation) return false;
	if (t1.seatType < t2.seatType) return true;
	if (t1.seatType > t2.seatType) return false;
	return 1 < 1;
}

bool operator == (const Ticket &t1, const Ticket &t2)
{
	if (t1.userName == t2.userName &&
		t1.trainID == t2.trainID &&
		t1.loadStation == t2.loadStation &&
		t1.unLoadStation == t2.unLoadStation &&
		t1.seatType == t2.seatType) return true;
	else return false;
}





Train::Train (const QString &tID)
:trainID(tID)
{
	tooLateToReconstructe = false;
	seatTypeNumber = stationNumber = 0;
}

Train::Train (const QString &tID, int setnr, int stanr,
			  const ttd::vector <QString> &stan, const ttd::vector <int> &ma,
			  const ttd::vector <QDateTime> &rt, const ttd::vector <QDateTime> &lt,
			  const ttd::vector <QString> &set, const ttd::vector <int> &senr,
			  const ttd::vector < ttd::vector <int> > &ptb)
{
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

bool Train::reconstructe
(int setnr, int stanr, const ttd::vector <QString> &stan, const ttd::vector <int> &ma, const ttd::vector <QDateTime> &rt, const ttd::vector <QDateTime> &lt, const ttd::vector <QString> &set, const ttd::vector <int> &senr, const ttd::vector <ttd::vector <int> > &ptb)
{
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
	if ( salingDate.find (dato) != salingDate.end() ) {
		salingDate[dato].ableToBuy = true;
		return;
	}
	salingDate[dato].ableToBuy = true;
	salingDate[dato].restTickets = ttd::vector<ttd::vector<int> >(seatTypeNumber);
	for (int i = 0; i < seatTypeNumber; i++) {
		salingDate[dato].restTickets[i] =  (ttd::vector <int>(stationNumber-1));
		for (int j = 0; j < stationNumber - 1; j++)
			salingDate[dato].restTickets[i][j] = seatNumber[i];
	}
}

bool Train::closeOneDay (QDate datc)
{
	if (salingDate.find (datc) == salingDate.end())
		return false;

	salingDate[datc].ableToBuy = false;
	return true;
}


Train::TrainPoint Train::getPoint
	(const QString &lsta, const QString &ulsta, const QString &set)
{
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
	return tp;
}


Train::RestTicketsInformation Train::showRestTickets
	(const QDate &dat, const QString &lsta, const QString &ulsta, const QString &set)
{
	RestTicketsInformation rti;
	rti.restTicketsNumber = -1;
	rti.restTicketsPrice = -1;
	rti.restTicketsPoint = getPoint (lsta, ulsta, set);
	if (rti.restTicketsPoint.seatTypePoint == -1) return rti;
	int x = rti.restTicketsPoint.seatTypePoint;
	int y1 = rti.restTicketsPoint.loadStationPoint;
	int y2 = rti.restTicketsPoint.unLoadStationPoint;
	rti.restTicketsPrice = priceTable[x][y2] - priceTable[x][y1];
	if ( salingDate.find (dat) == salingDate.end() ) return rti;
	if (!salingDate[dat].ableToBuy) return rti;
	for (int i = y1; i < y2; i++) {
		if (rti.restTicketsNumber == -1 ||
			rti.restTicketsNumber > salingDate[dat].restTickets[x][i])
			rti.restTicketsNumber = salingDate[dat].restTickets[x][i];
	}
	return rti;
}
/*
int Train::buyTickets (QDate dat, QString lsta, QString ulsta, QString set, int num) {
	RestTicketsInformation rti = showRestTickets (dat, lsta, ulsta, set);
	if (rti.restTicketsPrice == -1 || rti.restTicketsNumber <= num) return 0;
	for (int i = rti.restTicketsPoint.loadStationPoint;
		 i < rti.restTicketsPoint.unLoadStationPoint; i++)
	{
		salingDate[dat].restTickets[rti.restTicketsPoint.seatTypePoint][i] -= num;
	}
	return rti.restTicketsPrice * num;
}

int Train::cancelTickets (QDate dat, QString lsta, QString ulsta, QString set, int num) {
	RestTicketsInformation rti = showRestTickets (dat, lsta, ulsta, set);
	for (int i = rti.restTicketsPoint.loadStationPoint;
		 i < rti.restTicketsPoint.unLoadStationPoint; i++) {
		salingDate[dat].restTickets[rti.restTicketsPoint.seatTypePoint][i] += num;
	}
	return rti.restTicketsPrice * num;
}*/

bool Train::openDate (QDate dat) {
	if (salingDate.find (dat) == salingDate.end() ) return false;
	else return salingDate[dat].ableToBuy;
}

//Have problems.
/*
QTrain Train::query_stationToStation (QDate dat, QString lsta, QString ulsta) {
	QTrain qt;
	TrainPoint tp = getPoint (lsta, ulsta, seatType[0]);
	if (salingDate.find (dat) == salingDate.end()) qt.ableToBuy = false;
	else qt.ableToBuy = salingDate[dat].ableToBuy;
	qt.trainID = trainID;
	qt.seatTypeNumber = seatTypeNumber;
	qt.seatType = seatType;
	qt.loadStation = lsta;
	qt.unLoadStation = ulsta;
	for (int i = 0; i < seatTypeNumber; i++) {
		RestTicketsInformation rti = showRestTickets (dat, lsta, ulsta, seatType[i]);
		qt.price.push_back (rti.restTicketsPrice);
		qt.seatNumber.push_back (rti.restTicketsNumber);
	}
	qt.loadStationLeaveTime = leaveTime[tp.loadStationPoint];
	qt.unLoadStationReachTime = reachTime[tp.unLoadStationPoint];
	return qt;
}
*/
TrainRoute Train::query_train () {
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

