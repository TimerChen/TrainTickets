#ifndef TOSERVERSTRUCTS_H
#define TOSERVERSTRUCTS_H

namespace frontask {
enum { stationtostationsearch, stationsearch };
struct stationToStationSearch {
    QString fromStation, toStation;
    QTime time;
    stationToStationSearch(QString _from, QString _to, QTime _time);
};
struct stationSearch
}

#endif // TOSERVERSTRUCTS_H
