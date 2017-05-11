#include "station.h"

station::station(const string& sname)
{
	QString tmp;
	tmp.fromStdString(sname);

	file.setFileName(tmp);
	file.open(tmp);
}

station::~station()
{

}

void station::Insert(const string& add_ref)
{
	train_ref.push_back(add_ref);
}

bool station::Delete(const string &mod_ref)
{
	vector::iterator it = train_ref.begin();
	vector::iterator it_end = ++train_ref.end();

	for (;it != it_end;++it)
	{
		if(*it == mod_ref)
			   break;
	}

	if (it != it_end)
	{
		erase(it);
		return true;
	}
	else
		return false;
}

int station::Query(const QDate& _date, const int& fuzzy)
{

	vector<pair<QDate, string> > ans;
	vector::iterator it = train_ref.begin();
	vector::iterator it_end = ++train_ref.end();

	if (fuzzy == 0)
	{
		for (;it != it_end;++it)
		{
			if(Trainmap[*it].openDate(_date))
				   ans.push_back(pair<QDate, string>(_date, *it));
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
					   ans.push_back(pair<QDate, string>(tmp, *it));
			}
		}
	}

	return ans;
}
