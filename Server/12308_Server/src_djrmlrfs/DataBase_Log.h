#ifndef TTD_LOG_H
#define TTD_LOG_H

#include <cstdio>
#include <QString>
#include <QDateTime>
#include "DataBase.h"
#include "DataBase_Account.h"
class DataBase_Log : public DataBase_Base
{
public:
	void buyTicket(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traId,
	 const QDate &dat, const QString &lsta, const QString &ulsta, const QString &set, const int &num);
	void returnTicket(/*const QDateTime &now,+*/const QString &AccId, const QString &name, const QString &traId,
	 const QDate &dat, const QString &lsta, const QString &ulsta, const QString &set, const int &num);
	void questTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traId);
	void questOne(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &staId);
	void questTwo(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &sta, const QString &stb);
	void questTic(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &qname, const QString &id);
	void questLog(/*const QDateTime &now,*/const QString &AccId, const QString &name);
	void questAcc(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &qname, const QString &id);
	void newAccount(/*const QDateTime &now,*/const QString &AccId, const QString &name);
	void modifyAccount(/*const QDateTime &now,*/const QString &AccId, const QString &name);
	void newTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID);
	void modifyTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID);
	void delTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID);
	void openDay(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID, const Qdate &day);
	void closeDay(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID, const Qdate &day);
	
private:
	ttd::vector<QString> accLog, ticLog, traLog, qstLog;
	DataBase_Log(const Qstring &Name = "Default");
	~DataBase_Log();
};
#endif
