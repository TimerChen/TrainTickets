#include <fstream>
class Account;
class Train {
	enum{A,B,C,D,F};
	enum{first, bussiness, second};//还有一些
  private:
    string train_no;
    class Ticket {
      private:
        int carrage;
		int kind;//车票类型（一等座等）
		int row;
		int col;//用A，B，C，D，F记录
		Account *account=NULL;//指向用户的指针（用智能指针包裹）
public:


    };

    public:
};


class Account {
  private:
    string id;
    string nickname;
    string password; //用哈希值存储

  public:
    //用返回值表明操作是否成功
    bool regist(); //注册，其中调用读入，参数应该是某种输入流
    bool change_inform(); //修改用户信息，参数应该是某种输入流
    bool search(string name_of_search); //查询用户相关信息
};

Template<class T> void
readlist(ifstream &in， T list_of_point[]); //读入文件中的位置记录表
