#ifndef TTD_TRAIN_HPP
#define TTD_TRAIN_HPP

#include <cstdio>
#include <iostream>
#include "map.hpp"
#include <QDateTime>

namespace ttd {

	
	struct Ticket {
		static long long ticketNumber = 0LL;
		
		long long ticketID;
		std::string userName;
		std::string loadStation, unLoadStation;
		std::string trainID;
		QDateTime loadTime, unLoadTime;
		int price;
		std::string seatType;
		
        Ticket (const std::string &un, const std::string &ls, const std::string &us, const std::string &tID, const QDateTime &lt, const QDateTime &ut, int pr, const std::string &st) {
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
		
		~Ticket () {
			loadTime.~QDateTime ();
			unLoadTime.~QDateTime ();
		}
		
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
		
	};
	
	
	
	struct QTrain {
		bool ableToBuy;
		std::string trainID;
		int seatTypeNumber;
		std::string loadStation, unLoadStation;
		std::string* seatType;
		int* price;
		int* number;
		QTime loadStationLeaveTime, unLoadStationReachTime;
    };
	
	struct TrainRoute {
		std::string trainID;
		int seatTypeNumber, stationNumber;
		std::string* stationName;
		int* mileAge;
		QTime* reachTime;
		QTime* leaveTime;
		std::string* seatType;
    };
	
	class Train {
	private:
		
		std::string trainID;
		bool tooLateToReconstructe;
		int seatTypeNumber, stationNumber;
		std::string* stationName;
		int* mileAge;
		QTime* reachTime;
		QTime* leaveTime;
		std::string* seatType;
		int* seatNumber;
		int** priceTable;

		/*
		struct SegmentTree {
			struct Node {
				int minn, lazy;
				Node* ls, * rs;
			}
			Node* root;
			int maxLength, maxTickets;
			
			Node* build (int l, int r, int m) {
				Node* now = new Node;
				now -> minn = m;
				now -> lazy = 0;
				if (l == r) {
					now -> ls = NULL;
					now -> rs = NULL;
					return now;
				}
				int mid = l + r >> 1;
				now -> ls = build (l, mid, m);
				now -> rs = build (mid + 1, r, m);
				return now;
			}
			void pushdown (Node* now, int l, int r) {
				if (l == r) return;
				if (now -> lazy == 0) return;
				now -> ls -> minn += now -> lazy;
				now -> rs -> minn += now -> lazy;
				now -> ls -> lazy += now -> lazy;
				now -> rs -> lazy += now -> lazy;
				now -> lazy = 0;
				return;
			}
			void update (Node* now, int l, int r) {
				if (l == r) return;
				int lm = now -> ls -> minn;
				int rm = now -> rs -> minn;
				if (lm < rm) now -> minn = lm;
				else now -> minn = rm;
				return;
			}
			void occupy (Node* now, int l, int r, int ll, int rr, int num) {
				pushdown (now, l, r);
				if (l == ll && r == rr) {
					now -> minn += num;
					now -> lazy += num;
					return;
				}
				int mid = l + r >> 1;
				if (rr <= mid) occupy (now -> ls, l, mid, ll, rr, num);
				else if (ll > mid) occupy (now -> rs, mid + 1, r, ll, rr, num);
					else occupy (now -> ls, l, mid, ll, mid, num), occupy (now -> rs, mid + 1, r, mid + 1, rr, num);
				update (now, l, r);
				return;
			}
			void check (Node* now, int l, int r, int ll, int rr) {
				pushdown (now, l, r);
				if (l == ll && r == rr) {
					return now -> minn;
				}
				int mid = l + r >> 1;
				if (rr <= mid) return check (now -> ls, l, mid, ll, rr);
				else if (ll > mid) return check (now -> rs, mid + 1, r, mid + 1, rr);
					else {
						int lm = check (now -> ls, l, mid, ll, mid);
						int rm = check (now -> rs, mid + 1, r, mid + 1, rr);
						if (lm < rm) return lm;
						else return rm;
					}
			}
			
			
			SegmentTree (int n, int m) {
				maxLength = n;
				maxTickets = m;
				root = build (1, n);
			}
			
			void recon (Node* now) {
				if (now -> ls == NULL) return;
				recon (now -> ls);
				recon (now -> rs);
				delete now -> ls;
				delete now -> rs;
				return;
			}
			~SegmentTree () {
				if (root != NULL) recon (root);
				delete root;
				delete maxLength;
				delete maxTickets;
			}
		}
		*/

		struct TicketsPerDay {
			bool ableToBuy;
			int** restTickets;
		};
		ttd::map <QDate, TicketsPerDay> salingDate;
		
		
		
	public:
		
        Train (const std::string &tID, int setnr, int stanr, std::string* stan, int* ma, QTime* rt, QTime* lt, std::string* set, int* senr, int** ptb) {
			tooLateToReconstructe = false;
			trainID = tID;
			seatTypeNumber = setnr;
            stationNumber = stanr;
			
			stationName = new std::string [stationNumber];
			for (int i = 0; i < stationNumber; i++) stationName[i] = stan[i];
			
			mileAge = new int [stationNumber];
			for (int i = 0; i < stationNumber; i++) mileAge[i] = ma[i];
			
			reachTime = new QTime [stationNumber];
			for (int i = 0; i < stationNumber; i++) reachTime[i] = rt[i];
			
			leaveTime = new QTime [stationNumber];
			for (int i = 0; i < stationNumber; i++) leaveTime[i] = lt[i];
			
			seatType = new std::string [seatTypeNumber];
			for (int i = 0; i < seatTypeNumber; i++) seatType[i] = set[i];
			
			seatNumber = new int [seatTypeNumber];
			for (int i = 0; i < seatTypeNumber; i++) seatNumber[i] = senr[i];
			
			priceTable = new int* [seatTypeNumber];
			for (int i = 0; i < seatTypeNumber; i++) {
				priceTable[i] = new int [stationNumber];
				for (int j = 0; j < stationNumber; j++) {
					priceTable[i][j] = ptb[i][j];
				}
			}
		}
		
		~Train () {
			delete [] stationName;
			delete [] mileAge;
			delete [] reachTime;
			delete [] leaveTime;
			delete [] seatType;
			delete [] seatNumber;
			for (int i = 0; i < seatTypeNumber; i++) {
				delete [] priceTable[i];
			}
			delete [] priceTable;
            salingDate.~map ();
		}
		
		bool isItTooLateToReconstructe () {
			return tooLateToReconstructe;
		}
		
		bool reconstructe (int setnr, int stanr, std::string* stan, int* ma, QTime* rt, QTime* lt, std::string* set, int* senr, int** ptb) {
			if (tooLateToReconstructe) return false;
			
			delete [] stationName;
			delete [] mileAge;
			delete [] reachTime;
			delete [] leaveTime;
			delete [] seatType;
			delete [] seatNumber;
			for (int i = 0; i < seatTypeNumber; i++) {
				delete [] priceTable[i];
			}
			delete [] priceTable;
            salingDate.~map ();
			
			seatTypeNumber = setnr;
            stationNumber = stanr;
			
			stationName = new std::string [stationNumber];
			for (int i = 0; i < stationNumber; i++) stationName[i] = stan[i];
			
			mileAge = new int [stationNumber];
			for (int i = 0; i < stationNumber; i++) mileAge[i] = ma[i];
			
			reachTime = new QTime [stationNumber];
			for (int i = 0; i < stationNumber; i++) reachTime[i] = rt[i];
			
			leaveTime = new QTime [stationNumber];
			for (int i = 0; i < stationNumber; i++) leaveTime[i] = lt[i];
			
			seatType = new std::string [seatTypeNumber];
			for (int i = 0; i < seatTypeNumber; i++) seatType[i] = set[i];
			
			seatNumber = new int [seatTypeNumber];
			for (int i = 0; i < seatTypeNumber; i++) seatNumber[i] = senr[i];
			
			priceTable = new int* [seatTypeNumber];
			for (int i = 0; i < seatTypeNumber; i++) {
				priceTable[i] = new int [stationNumber];
				for (int j = 0; j < stationNumber; j++) {
					priceTable[i][j] = ptb[i][j];
				}
			}
			
			return true;
		}
		
		void openOneDay (QDate dato) {
			if (salingDate.find (dato)) {
				salingDate[dato].ableToBuy = true;
				return;
			}
			salingDate[dato].ableToBuy = true;
			salingDate[dato].restTickets = new int* [seatTypeNumber];
			for (int i = 0; i < seatTypeNumber; i++) {
				salingDate[dato].restTickets[i] = new int [stationNumber - 1];
				for (int j = 0; j < stationNumber - 1; j++) salingDate[dato].restTickets[i][j] = seatNumber[i];
			}
		}
		
		bool closeOneDay (QDate datc) {
			if (!salingDate.find (datc)) {
				return false;
			}
			salingDate[datc].ableToBuy = false;
			return true;
		}
		
		struct TrainPoint {
			int seatTypePoint;
			int loadStationPoint;
			int unLoadStationPoint;
		};
		
		TrainPoint getPoint (std::string lsta, std::string ulsta, std::string set) {
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
		
		struct RestTicketsInformation {
			int restTicketsNumber;
			int restTicketsPrice;
			TrainPoint restTicketsPoint;
		};
		
		RestTicketsInformation showRestTickets (QDate dat, std::string lsta, std::string ulsta, std::string set) {
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
		
		int buyTickets (QDate dat, std::string lsta, std::string ulsta, std::string set, int num) {
			RestTicketsInformation rti = showRestTickets (dat, lsta, ulsta, set);
			if (restTicketsPrice == -1 || restTicketsNumber <= num) return 0;
			for (int i = rti.restTicketsPoint.loadStationPoint; i < rti.restTicketsPoint.unLoadStationPoint; i++) {
				salingDate[dat].restTickets[rti.restTicketsPoint.seatTypePoint][i] -= num;
			}
			return rti.restTicketsPrice * num;
		}
		
		int cancelTickets (QDate dat, std::string lsta, std::string ulsta, std::string set, int num) {
			RestTicketsInformation rti = showRestTickets (dat, lsta, ulsta, set);
			for (int i = rti.restTicketsPoint.loadStationPoint; i < rti.restTicketsPoint.unLoadStationPoint; i++) {
				salingDate[dat].restTickets[rti.restTicketsPoint.seatTypePoint][i] += num;
			}
			return rti.restTicketsPrice * num;
		}
		
		bool openDate (QDate dat) {
			if (!salingDate.find (dat)) return false;
			else return salingDate[dat].ableToBuy;
		}
		
		QTrain ask (QDate dat, std::string lsta, std::string ulsta) {
			QTrain qt;
			TrainPoint tp = getPoint (lsta, ulsta, seatType[0]);
			if (!salingDate.find (dat)) qt.ableToBuy = false;
			else qt.ableToBuy = salingDate[dat].ableToBuy;
			qt.trainID = trainID;
			qt.seatTypeNumber = seatTypeNumber;
			qt.seatType = new std::string [seatTypeNumber];
			for (int i = 0; i < seatTypeNumber; i++) {
				qt.seatType[i] = seatType[i];
			}
			qt.loadStation = lsta;
			qt.unLoadStation = ulsta;
			qt.price = new int [seatTypeNumber];
			qt.number = new int [seatTypeNumber];
			for (int i = 0; i < seatTypeNumber; i++) {
				RestTicketsInformation rti = showRestTickets (dat, lsta, ulsta, seatType[i]);
				qt.price[i] = rti.restTicketsPrice;
				qt.number[i] = rti.restTicketsNumber;
			}
			qt.loadStationLeaveTime = leaveTime[tp.loadStationPoint];
			qt.unLoadStationReachTime = reachTime[tp.unLoadStationPoint];
			return qt;
		}
		
		TrainRoute ask () {
			TrainRoute tr;
			
			tr.trainID = trainID;
			tr.seatTypeNumber = seatTypeNumber;
			tr.stationNumber = stationNumber;
			
			tr.stationName = new std::string [stationNumber];
			for (int i = 0; i < stationNumber; i++) tr.stationName[i] = stationName[i];
			
			tr.mileAge = new int [stationNumber];
			for (int i = 0; i < stationNumber; i++) tr.mileAge[i] = mileAge[i];
			
			tr.reachTime = new QTime [stationNumber];
			for (int i = 0; i < stationNumber; i++) tr.reachTime[i] = reachTime[i];
			
			tr.leaveTime = new QTime [stationNumber];
			for (int i = 0; i < stationNumber; i++) tr.leaveTime[i] = leaveTime[i];
			
			tr.seatType = new std::string [seatTypeNumber];
			for (int i = 0; i < seatTypeNumber; i++) tr.seatType[i] = seatType[i];
			
			return tr;
		}
		
	};
}

#endif
