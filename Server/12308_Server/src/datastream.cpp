/*
 *  Writed by Jingxiao Chen.
 *
 *
 */
#include <include/vector.hpp>
#include <include/station.h>
#include <include/train.h>
#include <include/DataBase_Account.h>
#include <include/DataBase_User.h>


template<class T>
QDataStream& operator << (QDataStream& out, const ttd::vector<T>&v)
{
	out << (quint32)(v.size());
	for (size_t i = 0; i < v.size(); ++i)
		out << v[i] ;
	return out;
}

template<class T>
QDataStream& operator >> (QDataStream& in, ttd::vector<T>&v)
{
	v.clear();
	quint32 tmp_n;
	in >> tmp_n;
	v = ttd::vector<T>( tmp_n );
	for( size_t i = 0; i < tmp_n; ++i )
		in >> v[i];
	return in;
}


QDataStream& operator << (QDataStream& out, const QTrain &data)
{
	out << data.ableToBuy << data.trainID
		<< data.seatTypeNumber
		<< data.loadStation << data.unLoadStation
		<< data.seatType << data.price << data.seatNumber
		<< data.loadStationLeaveTime << data.unLoadStationReachTime;

	return out;
}
QDataStream& operator >> (QDataStream& in, QTrain &data)
{
	in >> data.ableToBuy >> data.trainID
			>> data.seatTypeNumber
			>> data.loadStation >> data.unLoadStation
			>> data.seatType >> data.price >> data.seatNumber
			>> data.loadStationLeaveTime >> data.unLoadStationReachTime;
	return in;
}
QDataStream& operator << (QDataStream& out, const TrainRoute &data)
{
	out << data.trainID
		<< data.seatTypeNumber << data.stationNumber
		<< data.stationName << data.mileAge
		<< data.reachTime << data.leaveTime
		<< data.seatType;
	return out;
}
QDataStream& operator >> (QDataStream& in, TrainRoute &data)
{
	in >> data.trainID
			>> data.seatTypeNumber >> data.stationNumber
			>> data.stationName >> data.mileAge
			>> data.reachTime >> data.leaveTime
			>> data.seatType;
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

//Database_Account

QDataStream& operator << (QDataStream& out, const DataBase_Account::Ticket &data)
{
	out	<< data.buyer << data.loadStation << data.unLoadStation
		<< data.trainID << data.loadTime << data.unLoadTime
		<< data.price << data.seatType;
	return out;
}
QDataStream& operator >> (QDataStream& in, DataBase_Account::Ticket &data)
{
	in  >> data.buyer >> data.loadStation >> data.unLoadStation
		>> data.trainID >> data.loadTime >> data.unLoadTime
		>> data.price >> data.seatType;

	return in;
}

QDataStream& operator << (QDataStream& out, const DataBase_Account::Account &data)
{
	out	<< data.id << data.id_number << data.name
		<< data.passwordHash << data.isAdmin << data.log
		<< data.bought;
	return out;
}

QDataStream& operator >> (QDataStream& in, DataBase_Account::Account &data)
{
	in	>> data.id >> data.id_number >> data.name
		>> data.passwordHash >> data.isAdmin >> data.log
		>> data.bought;
	return in;
}

QDataStream& operator << (QDataStream& out, const DataBase_Account::ticLog &data)
{
	out	<< data.train << data.fromStation << data.toStation
		<< data.date << data.num ;
	return out;
}

QDataStream& operator >> (QDataStream& in, DataBase_Account::ticLog &data)
{
	in	>> data.train >> data.fromStation >> data.toStation
		>> data.date >> data.num ;
	return in;
}

