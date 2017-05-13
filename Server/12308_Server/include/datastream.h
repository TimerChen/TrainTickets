#ifndef TTD_DATASTREAM_H
#define TTD_DATASTREAM_H

#include <iostream>
#include <QDateTime>
#include <QDataStream>



namespace ttd
{

class DataBase_Account
{
public:
	class Ticket;
	class Account;
	class ticLog;
};


QDataStream& operator << (QDataStream& out, const DataBase_Account::Ticket &data);
QDataStream& operator >> (QDataStream& in, DataBase_Account::Ticket &data);

QDataStream& operator << (QDataStream& out, const DataBase_Account::Account &data);
QDataStream& operator >> (QDataStream& in, DataBase_Account::Account &data);

QDataStream& operator << (QDataStream& out, const DataBase_Account::ticLog &data);
QDataStream& operator >> (QDataStream& in, DataBase_Account::ticLog &data);

}



#endif // TTD_FILE_H
