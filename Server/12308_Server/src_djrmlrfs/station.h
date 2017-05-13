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
#include "map.hpp"

//Reply of station query
//Data of station
class Station
{
private:
	ttd::map<QString,ttd::vector<QString> > staData;
public:

	//constructor
	Station();
	//destructor
	~Station();
	int exist(const QString&sta, const QString&tra);
	//valid add train plan at this station
	bool insert(const QString&sta, const QString& add_ref);
	//valid delete train plan at this station
	bool remove(const QString&sta, const QString& mod_ref);
	ttd::vector<QString> pass(const QString &sta);
	ttd::vector<QString> bothPass(const QString &sta, const QString &stb);
};

#endif // STATION_HPP
