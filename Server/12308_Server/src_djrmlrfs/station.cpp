#include "station.h"
Station::Station()
{
	staData.clear();
}
Station::~Station()
{
	
}
int Station::exist(const QString&sta, const QString&tra)
{
	ttd::map<QString,ttd::vector<QString> >::iterator it = staData.find(sta);
	if (it == staData.end())	return 0;	//no such station
	for (ttd::vector<QString>::iterator rator = it->second.begin(); rator != it->second.end(); rator++)
		if (*rator == tra)	return 1;	//exist
	return 2;							//exist station, no train
	
}
bool Station::insert(const QString&sta, const QString& add_ref)
{
	if (exist(sta,add_ref))	return 0;
	staData[sta].push_back(add_ref);
	return 1;
}
bool Station::remove(const QString&sta, const QString& mod_ref)
{
	ttd::map<QString,ttd::vector<QString> >::iterator it = staData.find(sta);
	if (it == staData.end())	return 0;	//no such station
	for (ttd::vector<QString>::iterator rator = it->second.begin(); rator != it->second.end(); rator++)
		if (*rator == mod_ref)	{it->second.erase(rator);	return 1;}	//exist
	return 0;							//exist station, no train
	
}
ttd::vector<QString> Station::pass(const QString &sta)
{
	return staData[sta];
}
ttd::vector<QString> Station::bothPass(const QString &sta, const QString &stb)
{
	ttd::vector<QString> ans = staData[sta], tmp = staData[stb];
	for(int i = 0; i < ans.size(); i++)
	{
		bool ok = 0;
		for (int j = 0; j < tmp.size(); j++)
			if (ans[i] == tmp[j])
			{
				ok = 1;
				break;
			}
		if (!ok)	ans.erase(i--);
	}
}
