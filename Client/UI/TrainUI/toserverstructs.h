#ifndef TOSERVERSTRUCTS_H
#define TOSERVERSTRUCTS_H

#include <QDate>
#include <QString>

namespace frontask {
enum { stationtostationsearch, stationsearch, trainsearch, login };
struct stationToStationSearch {
    QString fromStation, toStation;
    QDate time;
    stationToStationSearch();
    stationToStationSearch(const stationToStationSearch &rs);
    explicit stationToStationSearch(QDate _time, QString _from = "",
                                    QString _to = "");
};

struct stationSearch {
    QString station;
    QDate time;
    stationSearch();
    stationSearch(const stationSearch &rs);
    explicit stationSearch(QDate _time, QString _station = "");
};

struct trainSearch {
    QString trainID;
    QDate time;
    trainSearch();
    trainSearch(const trainSearch &rs);
    trainSearch(QDate _time, QString _train = "");
};

struct loginAccount {
    QString userID;
    QString pwd;
    loginAccount();
    loginAccount(const loginAccount &rl);
    loginAccount(QString _userID = "", QString _pwd = "");
}
}

#endif // TOSERVERSTRUCTS_H
