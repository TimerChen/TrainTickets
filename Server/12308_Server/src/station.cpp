/*
 * Writed by Hanjing Wang.
 * Rewrited by Jingxiao Chen.
 *
 *
 */
#include "include/station.h"

Station::Station()
{}

Station::Station(const QString& Sname)
	:stationName(Sname)
{}

Station::Station(const QString& Sname,
				 const ttd::vector<QString> &Trains)
	:stationName(Sname),
	  trains(Trains)
{}

Station::~Station()
{}

void Station::insert(const QString &add_ref)
{ trains.push_back(add_ref); }

bool Station::remove(const QString &mod_ref)
{
	using namespace ttd;
	vector<QString>::iterator it = trains.begin();
	vector<QString>::iterator it_end = trains.end();

	for (;it != it_end;++it)
	{
		if(*it == mod_ref)
			   break;
	}

	if (it != it_end)
	{
		trains.erase(it);
		return true;
	}
	else
		return false;
}

int Station::Query(const QDate& _date, const int& fuzzy)
{
	using namespace ttd;
	vector<pair<QDate, QString> > ans;
	vector<QString>::iterator it = trains.begin();
	vector<QString>::iterator it_end = ++trains.end();

	if (fuzzy == 0)
	{
		for (;it != it_end;++it)
		{
			if(Trainmap[*it].openDate(_date))
				   ans.push_back(pair<QDate, QString>(_date, *it));
		}

	}

	else
	{
		for(;it != it_end;++it)
		{
			for(int i = 0 - fuzzy; i <= fuzzy; ++i)
			{
				QDate tmp = _data.addDays(i);
				if(Trainmap[*it].openDate(tmp))
					   ans.push_back(pair<QDate, QString>(tmp, *it));
			}
		}
	}

	return ans;
}
