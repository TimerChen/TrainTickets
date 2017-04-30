#include <fstream>

class Ticket()
{
 private:
    string Ticket_Start;
    string Ticket_Determination;
    string Ticket_TrainNumber;

    int Ticket_Level;
    int Ticket_Price;
    int Ticket_Remain;
    int Ticket_Total;
    int Ticket_Sold;
    
    Tree *Ticket_BoughtUser;
}

template <class Typename>
class GeneralNode()
{
 private:
    Typename data;
    GeneralNode *GeneralNode_NextGen;
    GeneralNode *GeneralNode_NextBro;

 public:
    GeneralNode(){}
    ~GeneralNode(){}
    Typename GetStorage();                  //取出存储的data信息
    


}

template <class Typename>
class
class Account               //账户类基类
{
 private:
    const string Account_ID{};      //账户ID
    string Account_NickName;//
    string Account_Password;
    
    bool Account_isAdmin; 
 
 public:
    Account() = 0;
    ~Account() = 0;
    bool isAdmin();
    bool ChangeNickName(const string &Account_NewNickName);
    bool ChangePassword(const string &Account_OldPassword, const string &Account_NewPassword);
}

class User:public Account   //用户账户类
{
 private:
    class *Ticket;           //票类：指向已定票（已定票数组）
    int numOfticket;         //已定票数
 
 public:
    User(){}                 //建立用户账户
    ~User(){}                //用户帐户析构函数
    bool OrderTickets
}