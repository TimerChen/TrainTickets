#include <fstream>

class Account               //账户类基类
{
 private:
    const string Account_ID{};      //账户ID
    string Account_NickName;//
    string Account_Password;
 
 public:
    Account() = 0;
    ~Account() = 0;
}

class User:public Account   //用户账户类
{
 private:
    class *Ticket;           //票类：指向已定票（已定票数组）
    int numOfticket;         //已定票数
 
 public:
    User(){}                 //建立用户账户
    ~User(){}                //用户帐户析构函数
    bool ChangePassword(const string &NewPassword);
    bool ChangeUserNickName(const string &NewNickName)

}