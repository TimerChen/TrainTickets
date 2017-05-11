# Time类说明文档

* 第一部分:包含库与名字空间

  ```c++
  #include <cstdio>     //sscanf使用
  #include <string>     //string类操作
  #include <sstream>    //stringstream流
  #include <iomanip>    //格式化输出
  using namespace std;
  ```

  ​

* 第二部分:构造函数

​        在本文件内实现的构造函数有两类

​	1.参数为int类构造函数

​		此函数参考了Unix时间戳

​		考虑到测试数据应该是在2016~2017间,故计秒数基点设置在了2015年1月1日 00:00:00

​		同时为了减少判定和运算时间,将转换过程简单化为

​                年 = 366 * 24 * 3600 s--以YEAR表示

​		月 = 31 * 3600 s--以MONTH表示

​		日 = 86400 s--DAY

​      		时 = 3600 s--HOU

​		分 = 60 s--MIN

```c++
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
```

​	2.以string为参数的构造函数

```c++
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
```

​	NOTE:时间的输入格式为"XXXX-XX-XX XX:XX:XX" 

​	e.g. 2017-03-28 18:28:00

* 第三部分:string和int转换

  ```c++
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
  //同样转换为"XXXX-XX-XX XX:XX:XX"的时间格式
  int Time::to_int()
  {
      int tmp = 0;
      tmp = (year - 2015) * YEAR + month * MONTH + day * DAY
          + hou * HOU + min * MIN + sec;

      return tmp;
  }
  ```

  ​

* 第四部分:正确性

  该部分已经通过time-test.cpp的使用检验了正确性



# 祝安!

#### Vegewong 

#### 2017/4/12 17:08