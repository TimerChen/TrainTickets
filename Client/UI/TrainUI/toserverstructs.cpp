#include "toserverstructs.h"
#include <QDate>
#include <QString>

frontask::stationToStationSearch::stationToStationSearch() {}
frontask::stationToStationSearch::stationToStationSearch(QDate _time,
                                                         QString _from,
                                                         QString _to)
    : fromStation(_from), toStation(_to), time(_time) {}
frontask::stationToStationSearch::stationToStationSearch(
    const stationToStationSearch& rs)
    : fromStation(rs.fromStation), toStation(rs.toStation), time(rs.time) {}

frontask::stationSearch::stationSearch() {}
frontask::stationSearch::stationSearch(const stationSearch& rs)
    : time(rs.time), station(rs.station) {}
frontask::stationSearch::stationSearch(QDate _time, QString _station)
    : time(_time), station(_station) {}

frontask::trainSearch::trainSearch() {}
frontask::trainSearch::trainSearch(const trainSearch& rs)
    : time(rs.time), trainID(rs.trainID) {}
frontask::trainSearch::trainSearch(QDate _time, QString _train)
    : time(_time), trainID(_train) {}

frontask::loginAccount::loginAccount() {}
frontask::loginAccount::loginAccount(const loginAccount& rl)
    : userID(rl.userID), pwd(rl.pwd) {}
frontask::loginAccount::loginAccount(QString _userID, QString _pwd)
    : userID(_userID), pwd(_pwd) {}

frontask::auLoginAccount::auLoginAccount() {}
frontask::auLoginAccount::auLoginAccount(const auLoginAccount& rl)
    : userID(rl.userID), pwd(rl.pwd) {}
frontask::auLoginAccount::auLoginAccount(QString _userID, QString _pwd)
    : userID(_userID), pwd(_pwd) {}