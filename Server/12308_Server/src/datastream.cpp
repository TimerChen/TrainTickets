/*
 *  Writed by Jingxiao Chen.
 *
 *
 */
#include <include/vector.hpp>
#include <include/station.h>
#include <include/train.h>
template<T>
QDataStream& operator << (QDataStream& out, const ttd::vector<T>&v)
{
	out << v.size ;
    for (int i = 0; i < v.sz; ++i)
		out << v[i] ;
    return out;
}

template<T>
QDataStream& operator >> (QDataStream& in, ttd::vector<T>&v)
{
	v.clear();
	int tmp_n;T d;
	in >> tmp_n;
	for( int i = 0; i < tmp_n; ++i )
	{
		in >> d;
		v.push_back(d);
	}
	return in;
}

QDataStream& operator << (QDataStream& out, const Ticket &data)
{
	out << data.ticketID;
	out << data.userName << data.loadStation << data.unLoadStation;
	out << data.trainID << data.loadTime << data.unLoadTime;
	out << price << seatType;
	return out;
}
QDataStream& operator >> (QDataStream& in, Ticket &data)
{
	Qstring un, ls, us, tID, st;
	QDataTime lt, ut;
	int pr, ticketID;
	in >> ticketID;
	in >> un >> ls >> us;
	in >> tID >> lt >> ut;
	in >> pr >> st;
	data = Ticket(un ,ls, us, tID, lt, ut, pr, st);
	data.ticketID = ticketID;
	return in;
}
QDataStream& operator << (QDataStream& out, const QTrain &data)
{
	out << data.ableToBuy << data.trainID;
	out << data.seatTypeNumber;
	out << data.loadStation << data.unLoadStation;
	out << data.seatType << data.price << data.number;
	out << data.loadStationLeaveTime << data.unLoadStationReachTime;

	return out;
}
QDataStream& operator >> (QDataStream& in, QTrain &data)
{
	in >> data.ableToBuy >> data.trainID;
	in >> data.seatTypeNumber;
	in >> data.loadStation >> data.unLoadStation;
	in >> data.seatType >> data.price >> data.number;
	in >> data.loadStationLeaveTime >> data.unLoadStationReachTime;
	return in;
}
QDataStream& operator << (QDataStream& out, const TrainRoute &data)
{
	out << data.trainID;
	out << data.seatTypeNumber << data.stationNumber;
	out << data.stationName << data.mileAge;
	out << data.reachTime << data.leaveTime;
	out << data.seatType;
	return out;
}
QDataStream& operator >> (QDataStream& in, TrainRoute &data)
{
	in >> data.trainID;
	in >> data.seatTypeNumber >> data.stationNumber;
	in >> data.stationName >> data.mileAge;
	in >> data.reachTime >> data.leaveTime;
	in >> data.seatType;
	return in;
}
QDataStream& operator << (QDataStream& out, const Train &data)
{
	out << data.trainID
		<< data.tooLateToReconstructe
		<< data.seatTypeNumber << data.stationNumber
		<< data.stationName << data.mileAge
		<< data.reachTime << data.leaveTime
		<< data.seatType << data.seatNumber << data.priceTable;
	return out;
}

QDataStream& operator >> (QDataStream& in, Train &data)
{
	in >> data.trainID
			>> data.tooLateToReconstructe
			>> data.seatTypeNumber >> data.stationNumber
			>> data.stationName >> data.mileAge
			>> data.reachTime >> data.leaveTime
			>> data.seatType >> data.seatNumber >> data.priceTable;
	return in;
}

QDataStream& operator << (QDataStream& out, const Train::TicketsPerDay &data)
{
	out << data.ableToBuy << data.restTickets;
	return out;
}

QDataStream& operator >> (QDataStream& in, Train::TicketsPerDay &data)
{
	in >> data.ableToBuy >> data.restTickets;
	return in;
}
