//Time.hpp
//Vegewong 2017/4/11 0:53
//该类实现了 int → 普通时间 转换的功能
//默认时间的字符串按照"XXXX-XX-XX,XX:XX(:XX)"格式给出 e.g.2017-03-28,15:39(:59)
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
class TimeFormatError{};

bool isLeap(const short &Year)
{
    return (Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0));
}

class Time
{
  private:
    bool time_valid(const short &Year, const short &Month, const short &Day,
                    const short &Hou, const short &Min, const short &Sec);

  public:
    Time(const int &t = 0);
    Time(const string &t);
    short year, month, day;
    short hou, min, sec;
    int to_int();
    Time &set(const int &t = 0);
    string to_string();
};

bool Time::time_valid(const short &Year, const short &Month, const short &Day, const short &Hou,
                      const short &Min, const short &Sec)
{
    if (2010 < Year && Year < 2020 && 0 < Month && Month <= 12 && 0 < Day 
        && 0 <= Hou && Hou <= 24 && 0 <= Min && Min <= 59 && 0 <= Sec && Sec <= 59)
    {
        switch (Month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            if (Day <= 31)
                return true;
            else
                return false;
            break;
        }
        case 2:
        {
            if ((isLeap(Year) && Day <= 29) || (!isLeap(Year) && Day <= 28))
                return true;
            else
                return false;
            break;
        }
        default:
        {
            if (Day <= 30)
                return true;
            else
                return false;
            break;
        }
        }
    }
}

Time::Time(const string &t)
{
    scanf("%d%c%d%c%d%c%d%c%d", &year, &month,
          &day, &hou, &min); //读取各数值,并丢弃其后符号
    char tmp;
    scanf("%c", &tmp);
    if (tmp == '\0')
        sec = 0;
    else if (tmp == ':')
        scanf("%d", &sec);
    else
        throw TimeFormatError();

    if (!time_valid(year, month, day, hou, min, sec))
        throw TimeFormatError();
}

Time::Time(const int &t)
{
    int time_proce = t;

    year = time_proce / (366 * 86400);
    time_proce -= 366 * 86400 * year;
    year += 2010;
    //
    month = time_proce / (86400 * 31);
    time_proce -= month * 31 * 86400;
    //
    day = time_proce / 86400;
    time_proce -= day * 86400;
    //
    hou = time_proce / 3600;
    time_proce = hou * 3600;
    //
    min = time_proce / 60;
    time_proce = min * 60;
    //
    sec = time_proce;
}

int Time::to_int()
{
    return (sec + min * 60 + hou * 3600 + day * 86400 + 
            month * 31 * 86400 + year * 366 * 86400);
}

string Time::to_string()
{
    char year_s[4];
    char month_s[2];
    char day_s[2];
    char hou_s[2];
    char min_s[2];
    char sec_s[2];
    itoa(year, year_s, 10);
    itoa(month, month_s, 10);
    itoa(day, day_s, 10);
    itoa(hou, hou_s, 10);
    itoa(min, min_s, 10);
    itoa(sec, sec_s, 10);
    
    string time_ans = year_s;
    time_ans+'-'+month_s+'-'+day_s+','+hou_s+':'+min_s+':'+sec_s;
    return time_ans;
}