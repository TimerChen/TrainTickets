#include <iostream>
#include <sstream>
#include <string>
//#include <vector>
using namespace std;
class DataBase_Base //流程控制,基类库
{
  public:
    DataBase_Base(const string &Name = "Default")
    {
        initialize();
    }
    ~DataBase_Base()
    {
        saveData();
    }

  private:
    virtual void loadData();
    virtual void saveData();
};

class DataBase_Log : public DataBase_Base
{
    struct Log
    {
        //Who make this.
        int editor,
            //Type of this operation
            operat,
            //When this log be created ( For Search. )
            time;
        vector<int> detail;
    };

  private:
    vector<Log>DataBase_Log_storage;
    int BinarySearch(const int &timeToCompare);

  public:
    DataBase_Log(const string &Name = "Default"):DataBase_Base(Name) {}
    ~DataBase_Log();
    void addNewLog(const Log &NewLog)
    {
        if (DataBase_Log_storage.empty())
            DataBase_Log_storage.push_back(NewLog);
        else
        {
            int pos = BinarySearch(NewLog.time);
            DataBase_Log_storage.insert(DataBase_Log_storage.begin() + pos, NewLog);
        }
    }
    //Get logs of string.
    vector<string> getLogs(int StartTime, int EndTime)
    {
        int a = BinarySearch(StartTime) + 1;
        int b = BinarySearch(EndTime);
        stringstream int_to_string;
        string tmp;
        Log *Log_ptr;
        vector<string>temp;

        for (int i = a; i <= b; ++i)
        {
            int inttmp;
            Log_ptr = &DataBase_Log_storage[i];
            int_to_string << Log_ptr->editor << Log_ptr->operat << Log_ptr->time;
            for(vector<int>::iterator itr = Log_ptr->detail.begin(); itr != Log_ptr->detail.end(); ++itr)
            {
                int_to_string << *itr;
            }
            int_to_string >> tmp;
            temp.push_back(tmp);
        }
        return temp;
    }
    //Get logs of Log.
    vector<Log> getLogs_raw(int StartTime, int EndTime)
    {
        vector<Log> tmp;
        int a = BinarySearch(StartTime) + 1;
        int b = BinarySearch(EndTime);
        for (int i = a; i <= b; ++i)
        {
            tmp.push_back(DataBase_Log_storage[i]);
        }

        return tmp;
    }
};

int DataBase_Log::BinarySearch(const int &timeToCompare)
{
    int currentSize = DataBase_Log_storage.size();

    int l = 0, r = currentSize - 1;
    int mid = (l + r) / 2;
    if (DataBase_Log_storage[l].time > timeToCompare)
        mid = 0;
    else if (DataBase_Log_storage[r].time < timeToCompare)
        mid = r;
    else
    {
        while (l < r)
        {
            if (DataBase_Log_storage[mid].time >= timeToCompare)
            {
                r = mid - 1;
                mid = (r + l) / 2;
                continue;
            }
            else
            {
                if (DataBase_Log_storage[mid + 1].time >= timeToCompare)
                    break;
                else
                {
                    l = mid + 1;
                    mid = (r + l) / 2;
                }
            }
        }
    }
    return mid;
}
