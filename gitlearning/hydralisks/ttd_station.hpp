#ifndef TTD_STATION_HPP
#define TTD_STATION_HPP

#include <iostream>
#include <QDataStream>
#include <QString>
#include <QDateTime>
#include <QFile>

#include "ttd_utility.hpp"
#include "ttd_interact_station_train.hpp"
#include "ttd_vector.hpp"


namespace ttd
{

    class station
    {
    private:
        vector<string>train_ref;
        QFile file;

    public:
        station(const string& sname);                         //constructor
        ~station();                                           //destructor
        void Insert(const string& add_ref);                   //valid add train plan at this station
        bool Delete(const string& mod_ref);                   //valid delete train plan at this station
        int Query(const QDate& _date, const int& fuzzy = 0);  //valid fuzzy query operation according to date provided(unit: QData("XXXX-XX-XX"))
    };


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


}

#endif // TTD_STATION_HPP
