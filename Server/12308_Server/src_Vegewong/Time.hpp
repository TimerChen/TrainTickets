#include <cstdio>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#define MIN 60
#define HOU 3600
#define DAY 86400
#define MONTH 2678400
#define YEAR 31622400

class Time
{
 // private:
    //bool time_valid(const short &Year, const short &Month, const short &Day,
                   // const short &Hou, const short &Min, const short &Sec);

  public:
    Time(const int &t = 0);
    Time(const string &t);
    short year, month, day;
    short hou, min, sec;
    int to_int();
    Time &set(const int &t = 0);
    string to_string();
    stringstream stream;
};

Time::Time(const int &t)
{
    int time_proce = t;

    year = time_proce / YEAR;
    time_proce -= YEAR * year;
    year += 2015;
    //
    month = time_proce / MONTH;
    time_proce -= month * MONTH;
    //
    day = time_proce / DAY;
    time_proce -= day * DAY;
    //
    hou = time_proce / HOU;
    time_proce -= hou * HOU;
    //
    min = time_proce / MIN;
    time_proce -= min * MIN;
    //
    sec = time_proce;
}

Time::Time(const string &t)
{
    //sscanf(t, "%d-%d-%d %d:%d:%d", &year, &month, &day,
    //                              &hou, &min, &sec);
    //以上代码因为C++11特性无法工作
    char tmp;
    
    stream.clear();
    stream << t;
    stream >> year >> tmp >> month >> tmp >> day 
                          >> hou >> tmp >> min >> tmp >> sec;
}

string Time::to_string()
{
    stream.clear();
    string string_to_output1, string_to_output2, string_to_output3;
    
    stream << year << '-' << month << '-' << day << ' ';
    stream << setfill('0') << setw(2) << hou << ':';
    stream << setfill('0') << setw(2) << min << ':' << setfill('0') << setw(2) << sec;
    stream >> string_to_output1;
    stream >> string_to_output2;
    string_to_output3 = string_to_output1 + ' ' + string_to_output2;
    
    return string_to_output3;
}

int Time::to_int()
{
    int tmp = 0;
    tmp = (year - 2015) * YEAR + month * MONTH + day * DAY
        + hou * HOU + min * MIN + sec;

    return tmp;
}