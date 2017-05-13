/*
 *  Writed by Jingxiao Chen.
 *
 *
 */
/*
#include <include/vector.hpp>
#include <include/station.h>
#include <include/train.h>
#include <include/DataBase_Account.h>
#include <include/DataBase_User.h>





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
}*/


