#ifndef TOSERVERSTRUCTS_H
#define TOSERVERSTRUCTS_H

#include <QDate>
#include <QString>

namespace frontask {
enum {
    stationtostationsearch,
    stationsearch,
    trainsearch,
    login,
    aulogin,
    reg,
    changeusrname,
    changepwd,
    modifymyticket,
    buyTicket
};
struct stationToStationSearch {
    QString fromStation, toStation;
    QDate time;
    stationToStationSearch();
    stationToStationSearch(const stationToStationSearch &rs);
    explicit stationToStationSearch(const QDate _time, const QString _from = "",
                                    QString _to = "");
};

struct stationSearch {
    QDate time;
    QString station;

    stationSearch();
    stationSearch(const stationSearch &rs);
    explicit stationSearch(const QDate _time, const QString _station = "");
};

struct trainSearch {
    QDate time;
    QString trainID;

    trainSearch();
    trainSearch(const trainSearch &rs);
    trainSearch(const QDate _time, const QString _train = "");
};

struct loginAccount {
    QString userID;
    QString pwd;

    loginAccount(const loginAccount &rl);
    loginAccount(const QString _userID = "", const QString _pwd = "");
};

struct auLoginAccount {
    QString userID;
    QString pwd;

    auLoginAccount(const auLoginAccount &rl);
    auLoginAccount(const QString _userID = "", const QString _pwd = "");
};

struct regist {
    QString name;
    QString pwd;
    regist(const regist &rl);
    regist(const QString _name = "", const QString _pwd = "");
};

struct changeUsrName {
    QString newname;
    changeUsrName(const changeUsrName &rc);
    changeUsrName(const QString _newname = "");
};

struct changePwd {
    QString usrID;
    QString oldpwd;
    QString newpwd;
    changePwd(const changePwd &rc);
    changePwd(const QString _usrid, const QString _old, const QString _new);
};

struct modifyMyTicket {
    int ticketNum;
    QString trainID;
    QString usrID;
    QString loadStation;
    QString unLoadStation;

    modifyMyTicket(const int _ticketNum = 0, const QString _trainID = "",
                   const QString _usrID = "", const QString _load = "",
                   const QString _unload = "");
    modifyMyTicket(const modifyMyTicket &m);
};

struct targetTicket {
    QDate time;
    int buyNum;
    QString usrID;
    QString trainID;
    QString seatType;
    QString loadStation;
    QString unLoadStation;

    targetTicket();
    targetTicket(const targetTicket &rb);
    targetTicket(const QDate _time, const int _buyNum = 0,
                 const QString _usrID = "", const QString _trainID = "",
                 const QString _seatType = "", const QString _load = "",
                 const QString _unload = "");
};
}

#endif  // TOSERVERSTRUCTS_H
