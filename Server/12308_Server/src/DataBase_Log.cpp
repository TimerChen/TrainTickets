#include "include/DataBase_Log.h"

#include <QFile>
#include <QDataStream>
#include <QDateTime>

void DataBase_Log::buyTicket(/*const QDateTime &now,*/const int &UserId, const QString &traId,
 const QDate &dat, const QString &lsta, const QString &ulsta, const QString &set, const int &num)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + QString::number(UserId) +" bought "+QString::number(num)+
	" Tickets("+set+") from "+lsta+" to "+ulsta+" in Train "+traId+" at "+dat.toString());
}
void DataBase_Log::returnTicket(/*const QDateTime &now,+*/const QString &AccId, const QString &name, const QString &traId,
 const QDate &dat, const QString &lsta, const QString &ulsta, const QString &set, const int &num)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + name+"("+AccId+") returned "+QString::number(num)+
	" of his Tickets("+set+") from "+lsta+" to "+ulsta+" in Train "+traId+" at "+dat.toString());
	ticLog.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + name+"("+AccId+") returned "+QString::number(num)+
	" of his Tickets("+set+") from "+lsta+" to "+ulsta+" in Train "+traId+" at "+dat.toString());
}

void DataBase_Log::questTrain(const int &UserId, const QString &traId)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + QString::number(UserId) + " queried information about Train "+traId);
}
void DataBase_Log::questOne(const int &UserId, const QString &staId)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + QString::number(UserId) + "queried all Trains pass station "+staId);
}
void DataBase_Log::questTwo
(const int &UserId, const QDate &dat, const QString &sta, const QString &stb)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + QString::number(UserId) +
	"queried information about Trains pass both station " + dat.toString("[yyyy-MM-dd]") +sta+" and station "+stb);
}
void DataBase_Log::questTic( const int &UserId, const int &id )
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + "Userid: "+QString::number(UserId)
	+ "queried all buy(return) tickets operations of user " + QString::number(id));
}
void DataBase_Log::questLog(const int &UserId )
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + QString::number(UserId) + " viewed the Log");
}
void DataBase_Log::questAcc( const int &UserId, const QString &qname, const QString &id)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + "Admin "+QString::number(UserId)
	+ " queried all basic information of user "+qname+"("+id+")");
}

void DataBase_Log::newAccount(/*const QDateTime &now,*/const QString &AccId, const QString &name)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "A new User "+name+"("+AccId+") joined us");
	accLog.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "A new User "+name+"("+AccId+") joined us");
}
void DataBase_Log::modifyAccount(/*const QDateTime &now,*/const int &UserId, const int &id)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + "User "+QString::number(UserId)
				   +" modified self information and now he calls "+ QString::number(id) );
}

void DataBase_Log::newTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "User "+AccId+" modified self information and now he calls "+name);
	traLog.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "Admin "+name+" ("+AccId+") created a new train "+traID);
}
void DataBase_Log::modifyTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "Admin "+name+" ("+AccId+") modified information of train "+traID);
	traLog.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "Admin "+name+" ("+AccId+") modified information of train "+traID);
}
void DataBase_Log::delTrain(/*const QDateTime &now,*/const QString &AccId, const QString &name, const QString &traID)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "Admin "+name+" ("+AccId+") deleted train "+traID);
	traLog.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "Admin "+name+" ("+AccId+") deleted train "+traID);
}
void DataBase_Log::openDay(/*const QDateTime &now,*/const QString &AccId, const QString &name,
 const QString &traID, const QDate &day)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "Admin "+name+" ("+AccId+") allowed train "
	+traID+" to sell tickets in "+day.toString());
	traLog.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "Admin "+name+" ("+AccId+") allowed train "
	+traID+" to sell tickets in "+day.toString());
}
void DataBase_Log::closeDay(/*const QDateTime &now,*/const QString &AccId, const QString &name,
 const QString &traID, const QDate &day)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "Admin "+name+" ("+AccId+") banned train "
	+traID+" to sell tickets in "+day.toString());
	traLog.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ") + "Admin "+name+" ("+AccId+") banned train "
	+traID+" to sell tickets in "+day.toString());
}

ttd::pair<int,QString>
	DataBase_Log::login
	(const QString &ID, const QString &pwd,
	 const ttd::pair<int, QString> &re)
{
	log.push_back(QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				  + "Login: " + ID + " " + pwd + " "
				  + QString("Return: %1").arg(re.first) + re.second );
	return re;
}
bool DataBase_Log::logout(const int &UserId, const bool &re)
{
	log.push_back((QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				  + QString("Logout: %1").arg(UserId)) + " "
				  + QString("Return: %1").arg(re) );
	return re;
}

void DataBase_Log::newConnection(const QString &Ip)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + "New connection: " + Ip );
}
void DataBase_Log::disconnect(const int &UserId)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + "disconnect: " + QString::number(UserId) );
}

void DataBase_Log::any(const QString &content)
{
	log.push_back( QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss ddd]  ")
				   + content );
}

DataBase_Log::DataBase_Log(const QString &Name)
	:DataBase_Base( Name ) {}
DataBase_Log::~DataBase_Log()
{ saveData(); }
//Unfinished
void DataBase_Log::loadData()
{
	QFile file( dataBase_name + "_Log" + ".dat" );
	if(!file.open(QIODevice::ReadOnly))
		return;
	QDataStream in(&file);
	in.setVersion(QDataStream::Qt_5_0);
	in >> log;
	file.close();
}
void DataBase_Log::saveData()
{
	QFile file( dataBase_name + "_Log" + ".dat" );
	file.open(QIODevice::WriteOnly);
	QDataStream out(&file);
	out.setVersion(QDataStream::Qt_5_0);
	out << log;
	file.close();
}

