#include "include/DataBase_Log.h"
void DataBase_Log::buyTicket(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traId,
 const QDate &dat, const QString &lsta, const QString &ulsta, const QString &set, const int &num)
{
	ticLog.push_back(/*"In "+now.toString()+","+*/name+"("+AccId+") bought "+QString::number(num)+
	" Tickets("+set+") from "+lsta+" to "+ulsta+" in Train "+traId+" at "+dat.toString());
}
void DataBase_Log::returnTicket(/*const QDateTime &now,+*/const QString &AccId, const QString &name, const QString &traId,
 const QDate &dat, const QString &lsta, const QString &ulsta, const QString &set, const int &num)
{
	ticLog.push_back(/*"In "+now.toString()+","+*/name+"("+AccId+") returned "+QString::number(num)+
	" of his Tickets("+set+") from "+lsta+" to "+ulsta+" in Train "+traId+" at "+dat.toString());
}

void DataBase_Log::questTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traId)
{
	qstLog.push_back(/*"In "+now.toString()+","+*/name+"("+AccId+") queried information about Train "+traId);
}
void DataBase_Log::questOne(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &staId)
{
	qstLog.push_back(/*"In "+now.toString()+","+*/name+"("+AccId+") queried all Trains pass station "+staId);
}
void DataBase_Log::questTwo(/*const QDateTime &now,*/const QString &AccId, const QString &name,
 const QString &sta, const QString &stb)
{
	qstLog.push_back(/*"In "+now.toString()+","+*/name+"("+AccId+
	") queried information about Trains pass both station "+sta+" and station "+stb);
}
void DataBase_Log::questTic(/*const QDateTime &now,*/const QString &AccId, const QString &name,
 const QString &qname, const QString &id)
{
	qstLog.push_back(/*"In "+now.toString()+","+*/"Admin "+name+"("+AccId+
	") queried all buy(return) tickets operations of user "+qname+"("+id+")");
}
void DataBase_Log::questLog(/*const QDateTime &now,*/const QString &AccId, const QString &name)
{
	qstLog.push_back(/*"In "+now.toString()+","+*/"Admin "+name+"("+AccId+") viewed the Log");
}
void DataBase_Log::questAcc(/*const QDateTime &now,*/const QString &AccId, const QString &name,
 const QString &qname, const QString &id)
{
	qstLog.push_back(/*"In "+now.toString()+","+*/"Admin "+name+"("+AccId+
	") queried all basic information of user "+qname+"("+id+")");
}

void DataBase_Log::newAccount(/*const QDateTime &now,*/const QString &AccId, const QString &name)
{
	accLog.push_back(/*"In "+now.toString()+","+*/"A new User "+name+"("+AccId+") joined us");
}
void DataBase_Log::modifyAccount(/*const QDateTime &now,*/const QString &AccId, const QString &name)
{
	accLog.push_back(/*"In "+now.toString()+","+*/"User "+AccId+" modified self information and now he calls "+name);
}

void DataBase_Log::newTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID)
{
	traLog.push_back(/*"In "+now.toString()+","+*/"Admin "+name+" ("+AccId+") created a new train "+traID);
}
void DataBase_Log::modifyTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID)
{
	traLog.push_back(/*"In "+now.toString()+","+*/"Admin "+name+" ("+AccId+") modified information of train "+traID);
}
void DataBase_Log::delTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID)
{
	traLog.push_back(/*"In "+now.toString()+","+*/"Admin "+name+" ("+AccId+") deleted train "+traID);
}
void DataBase_Log::openDay(/*const QDateTime &now,*/const QString &AccId, const QString &name,
 const QString &traID, const QDate &day)
{
	traLog.push_back(/*"In "+now.toString()+","+*/"Admin "+name+" ("+AccId+") allowed train "
	+traID+" to sell tickets in "+day.toString());
}
void DataBase_Log::closeDay(/*const QDateTime &now,*/const QString &AccId, const QString &name,
 const QString &traID, const QDate &day)
{
	traLog.push_back(/*"In "+now.toString()+","+*/"Admin "+name+" ("+AccId+") banned train "
	+traID+" to sell tickets in "+day.toString());
}
DataBase_Log::DataBase_Log(const QString &Name)
{
	dataBase_name = Name;
}
DataBase_Log::~DataBase_Log()
{	
}
//Unfinished
void DataBase_Log::saveData()
{

}
void DataBase_Log::loadData()
{

}
