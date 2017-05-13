/*
	Edited by Hanjing Wang.
	Modified by Jingxiao Chen.
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


//Reply of station query
//Data of station
class Station
{
private:
	QString stationName;
	ttd::vector<QString>trains;
public:

	//constructor
	Station();
	Station(const QString& Sname);
	Station(const QString& Sname,
			const ttd::vector<QString> &Trains);
	//destructor
	~Station();
	//valid add train plan at this station
	void insert(const QString& add_ref);
	//valid delete train plan at this station
	bool remove(const QString& mod_ref);

	//I don't know what is this function --TimerChen
	
	//valid fuzzy query operation according to date provided(unit: QData("XXXX-XX-XX"))
	//int Query(const QDate& _date, const int& fuzzy = 0);
};

#endif // STATION_HPP
