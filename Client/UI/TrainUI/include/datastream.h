#ifndef TTD_FILE_H
#define TTD_FILE_H

#include <iostream>
#include <QDateTime>
#include <QDataStream>

namespace ttd
{

QDataStream& operator << (QDataStream& out, const vector<T>&v);
QDataStream& operator << (QDataStream& out, const map<T>&m);
QDataStream& operator >> (QDataStream& in, const vector<T>&v);
QDataStream& operator >> (QDataStream& in, const map<T>&m);


}



#endif // TTD_FILE_H
