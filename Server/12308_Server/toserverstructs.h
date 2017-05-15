#ifndef TOSERVERSTRUCTS_H
#define TOSERVERSTRUCTS_H

#include <QDate>
#include <QString>
#include <QDataStream>

namespace frontask {
enum {
    stationtostationsearch,  // send stationToStationSearch
    stationsearch,           // send stationSearch
    trainsearch,             // send trainSearch
    login,                   // send loginAccount
    aulogin,                 // send auLoginAccount
	logout,
    reg,                     // send regist
    changeusrname,           // send changeUsrName
    changepwd,               // send changePwd
    modifymyticket,          // send targetTicket
    buyTicket,               // send targetTicket
    getmytickets,            // send usrID
    adminmodifyusrtickets,   // send pair(targetTicket, adminID)
    adminaddusrtickets,      // send pair(targetTicket, adminID)
    adminchangeusrpwd,       // send pair(changePwd,adminID)
    adminchangeusrname,      // send pair(changeUsrName, adminID)
    admindeleteusr,          // send pair(usrID, usrID)
    stopsellticket,          // send pair(targetTicket, adminID)
    deletetrain,             // send pair(targetTicket, adminID)
    startselltrain,          // send pair(targetTicket, adminID)
    addplane                 // send pair(QString, adminID)
};
struct stationToStationSearch {
    QString fromStation, toStation;
    QDate time;
    stationToStationSearch();
    // stationToStationSearch(const stationToStationSearch &rs);
    explicit stationToStationSearch(const QDate _time, const QString _from = "",
                                    QString _to = "");
};

struct stationSearch {
    QDate time;
    QString station;

    stationSearch();
    // stationSearch(const stationSearch &rs);
    explicit stationSearch(const QDate _time, const QString _station = "");
};

struct trainSearch {
    QDate time;
    QString trainID;

    trainSearch();
    // trainSearch(const trainSearch &rs);
    trainSearch(const QDate _time, const QString _train = "");
};

struct loginAccount {
    QString userID;
    QString pwd;

    // loginAccount(const loginAccount &rl);
    loginAccount(const QString _userID = "", const QString _pwd = "");
};

struct auLoginAccount {
    QString userID;
    QString pwd;

    // auLoginAccount(const auLoginAccount &rl);
    auLoginAccount(const QString _userID = "", const QString _pwd = "");
};

struct regist {
    QString userID;
    QString pwd;
    // regist(const regist &rl);
    regist(const QString _userID = "", const QString _pwd = "");
};

struct changeUsrName {
    QString newname;
    // changeUsrName(const changeUsrName &rc);
    changeUsrName(const QString _newname = "");
};

struct changePwd {
    QString usrID;
    QString oldpwd;
    QString newpwd;
    // changePwd(const changePwd &rc);
    changePwd(const QString _usrid = "", const QString _old = "",
              const QString _new = "");
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
    // targetTicket(const targetTicket &rb);
    targetTicket(const QDate _time, const int _buyNum = 0,
                 const QString _usrID = "", const QString _trainID = "",
                 const QString _seatType = "", const QString _load = "",
                 const QString _unload = "");
};
}

QDataStream &operator << (QDataStream &out, const frontask::stationToStationSearch &data);
QDataStream &operator >> (QDataStream &in, frontask::stationToStationSearch &data);

QDataStream &operator << (QDataStream &out, const frontask::stationSearch &data);
QDataStream &operator >> (QDataStream &in, frontask::stationSearch &data);

QDataStream &operator << (QDataStream &out, const frontask::trainSearch &data);
QDataStream &operator >> (QDataStream &in, frontask::trainSearch &data);

QDataStream &operator << (QDataStream &out, const frontask::loginAccount &data);
QDataStream &operator >> (QDataStream &in, frontask::loginAccount &data);

QDataStream &operator << (QDataStream &out, const frontask::regist &data);
QDataStream &operator >> (QDataStream &in, frontask::regist &data);

#endif  // TOSERVERSTRUCTS_H
