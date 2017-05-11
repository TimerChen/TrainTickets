/*
	Edit by Hanjing Wang.
	Modify by TimeMachine.stat
*/
#ifndef STATION_HPP
#define STATION_HPP

#include <iostream>
#include <QDataStream>
#include <QString>
#include <QDateTime>
#include <QFile>

#include "utility.hpp"
#include "vector.hpp"



class station
{
private:
	ttd::vector<QString>train_ref;
    QFile file;

public:
    station(const QString& sname);                         //constructor
    ~station();                                           //destructor
    void Insert(const QString& add_ref);                   //valid add train plan at this station
    bool Delete(const QString& mod_ref);                   //valid delete train plan at this station
    int Query(const QDate& _date, const int& fuzzy = 0);  //valid fuzzy query operation according to date provided(unit: QData("XXXX-XX-XX"))
};

#endif // STATION_HPP
