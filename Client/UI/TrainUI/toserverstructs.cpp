#include "toserverstructs.h"
#include <QDate>
#include <QString>

frontask::stationToStationSearch::stationToStationSearch() {}
frontask::stationToStationSearch::stationToStationSearch(const QDate _time,
                                                         const QString _from,
                                                        const  QString _to)
    : fromStation(_from), toStation(_to), time(_time) {}
QDataStream &operator << (QDataStream &out, const frontask::stationToStationSearch &data)
{
	out << data.fromStation << data.toStation << data.time;
	return out;
}
QDataStream &operator >> (QDataStream &in, frontask::stationToStationSearch &data)
{
	in >> data.fromStation >> data.toStation >> data.time;
	return in;
}


//frontask::stationToStationSearch::stationToStationSearch(
//    const stationToStationSearch& rs)
//    : fromStation(rs.fromStation), toStation(rs.toStation), time(rs.time) {}

frontask::stationSearch::stationSearch() {}
//frontask::stationSearch::stationSearch(const stationSearch& rs)
//    : time(rs.time), station(rs.station) {}
frontask::stationSearch::stationSearch(const QDate _time, const QString _station)
    : time(_time), station(_station) {}

QDataStream &operator << (QDataStream &out, const frontask::stationSearch &data)
{
	out << data.time << data.station;
	return out;
}
QDataStream &operator >> (QDataStream &in, frontask::stationSearch &data)
{
	in >> data.time >> data.station;
	return in;
}



frontask::trainSearch::trainSearch() {}
//frontask::trainSearch::trainSearch(const trainSearch& rs)
//    : time(rs.time), trainID(rs.trainID) {}
frontask::trainSearch::trainSearch(const QDate _time, const QString _train)
    : time(_time), trainID(_train) {}

QDataStream &operator << (QDataStream &out, const frontask::trainSearch &data)
{
	out << data.time << data.trainID;
	return out;
}

QDataStream &operator >> (QDataStream &in, frontask::trainSearch &data)
{
	in >> data.time >> data.trainID;
	return in;
}

//frontask::loginAccount::loginAccount(const loginAccount& rl)
//    : userID(rl.userID), pwd(rl.pwd) {}
frontask::loginAccount::loginAccount(const QString _userID, const QString _pwd)
    : userID(_userID), pwd(_pwd) {}

QDataStream &operator << (QDataStream &out, const frontask::loginAccount &data)
{ out << data.userID << data.pwd; return out; }
QDataStream &operator >> (QDataStream &in, frontask::loginAccount &data)
{ in >> data.userID >> data.pwd; return in;}



//frontask::regist::regist(const regist& rl)
//    : name(rl.name), pwd(rl.pwd) {}
frontask::regist::regist(const QString _userID, const QString _pwd)
    : userID(_userID), pwd(_pwd) {}


QDataStream &operator << (QDataStream &out, const frontask::regist &data)
{ out << data.userID << data.pwd; return out; }
QDataStream &operator >> (QDataStream &in, frontask::regist &data)
{ in >> data.userID >> data.pwd; return in; }

//frontask::changeUsrName::changeUsrName(const changeUsrName &_rc):newname(_rc.newname){}
frontask::changeUsrName::changeUsrName(const QString _usrid, const QString _newname):usrID(_usrid),newname(_newname){}
QDataStream &operator << (QDataStream &out, const frontask::changeUsrName &data)
{ out << data.usrID << data.newname; return out; }

QDataStream &operator >> (QDataStream &in, frontask::changeUsrName &data)
{ in >> data.usrID >> data.newname; return out; }

//frontask::changePwd::changePwd(const changePwd &rc):usrID(rc.usrID), oldpwd(rc.oldpwd),newpwd(rc.newpwd){}
frontask::changePwd::changePwd(const QString _usrid, const QString _old, QString _new):usrID(_usrid), oldpwd(_old),newpwd(_new){}
QDataStream &operator << (QDataStream &out, const frontask::changePwd &data)
{ out << data.usrID << data.oldpwd << data.newpwd; return out; }
QDataStream &operator >> (QDataStream &in, frontask::changePwd &data)
{ in >> data.usrID >> data.oldpwd >> data.newpwd; return in; }


frontask::targetTicket::targetTicket(){}
//frontask::targetTicket::targetTicket(const targetTicket &rb):time(rb.time),buyNum(rb.buyNum),usrID(rb.usrID),trainID(rb.trainID),seatType(rb.seatType),loadStation(rb.loadStation),unLoadStation(rb.unLoadStation){}
frontask::targetTicket::targetTicket(const QDate _time, const int _buyNum, const QString _usrID, const QString _trainID, const QString _seatType, const QString _load, const QString _unload):time(_time),buyNum(_buyNum),usrID(_usrID),trainID(_trainID),seatType(_seatType),loadStation(_load),unLoadStation(_unload){}

QDataStream &operator << (QDataStream &out, const frontask::targetTicket &data)
{
	out << data.time << data.buyNum << data.usrID
		<< data.trainID  << data.seatType
		<< data.loadStation << data.unLoadStation;
	return out;
}

QDataStream &operator >> (QDataStream &in, frontask::targetTicket &data)
{
	in >> data.time >> data.buyNum >> data.ussID
		>> data.trainID >> data.seatType
		>> data.loadStation >> data.unLoadStation;
	return in;
}
