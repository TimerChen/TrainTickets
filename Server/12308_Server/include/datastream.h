#ifndef TTD_DATASTREAM_H
#define TTD_DATASTREAM_H

#include <QDataStream>
#include "include/vector.hpp"
#include "include/DataBase_Account.h"

template<class T>
QDataStream& operator >> (QDataStream& in, ttd::vector<T>&v);

template<class T>
QDataStream& operator << (QDataStream& out, const ttd::vector<T>&v);

QDataStream& operator << (QDataStream& out, const DataBase_Account::Ticket &data);
QDataStream& operator >> (QDataStream& in, DataBase_Account::Ticket &data);

QDataStream& operator << (QDataStream& out, const DataBase_Account::Account &data);
QDataStream& operator >> (QDataStream& in, DataBase_Account::Account &data);

QDataStream& operator << (QDataStream& out, const DataBase_Account::ticLog &data);
QDataStream& operator >> (QDataStream& in, DataBase_Account::ticLog &data);





#endif // TTD_FILE_H
