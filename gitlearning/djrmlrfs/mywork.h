#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;
//using STL and stupid ways
#define H(x,y,z)	((x)^(y)^(z))
#define I(x,y,z)	((y)^((x)|(~z)))
#define	F(x,y,z)	(((x)&(y))|((~x)&(z)))    
#define G(x,y,z)	(((x)&(z))|((y)&(~z)))
#define	shift(x,n)	(((x)<<(n))|((x)>>(32-(n))))
const unsigned int k[]={0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,0xa679438e,0x49b40821,0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
const unsigned int s[]={7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22,5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20,4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21};
const char str16[] = "0123456789abcdef";
class DataBase_Base// Maybe someone else will write it
{
public:
	DataBase_Base( const string &Name = "Default" )
	{ loadData(); }
	~DataBase_Base()
	{ saveData(); }                         
private:
	virtual void loadData();
	virtual void saveData();
};
//A class to save Account's information.
class DataBase_Account : public DataBase_Base
{
	friend class DataBase_User;
	//Real information of one person.
	struct IdentifyInformation
	{
		string name;
		int identificationCardNumber;
		//0-normal 1-student
		short 	identifyType,
				age;
		IdentifyInformation operator=(const IdentifyInformation &he)
		{
			name = he.name;
			identificationCardNumber = he.identificationCardNumber;
			identifyType = he.identifyType;
			age = he.age;
			return*this;
		}
	};
	// some values have default value.
	struct Account
	{
		//Account(){}
		Account( const string &Id="Default", const short identifyType=0 )
		{
			//no id number
			id_number = -1;
			//id and passwordhash = hash("000000")
			id = Id, passwordHash = "e1119c269cdb64f851aef6db68c49610";
			//unknown means -1
			self.age = -1;
			self.name = "Default";;
			self.identifyType = identifyType;
			self.identificationCardNumber = -1;
			// we have no friends
			friends.clear();
			//not admin
			isAdmin = 0;
		}
		Account operator=(const Account &acc)
		{
			id_number = acc.id_number;
			id = acc.id, passwordHash = acc.passwordHash;
			self = acc.self;
			friends = acc.friends;
			isAdmin = acc.isAdmin;
			return*this;
		}
		//Id for saving and finding quickly.
		int id_number;
		//Your id for register.
		string	id,
		//We only save the hash code of password.
				passwordHash;
		IdentifyInformation self;
		//You can buy tickets for your friends.
		vector<IdentifyInformation>friends;
		//If this is a admin account.
		bool isAdmin;
	};
	//MD5 copied from internet
	//Get the hash code of a password.
	string Hex(int a)
	{
		int b;
		string str1, Password = "";
		for (int i = 0; i < 4; ++i)
		{
			str1 = "";
			b = ((a>>i*8)%(1<<8))&0xff;
			for (int j = 0; j < 2; ++j)	str1.insert(0,1,str16[b%16]), b /= 16;
			Password += str1;
		}
		return Password;
	}
	string getPasswordHash( const string &Password )
	{
		unsigned int strlength, atemp = 0x67452301, btemp = 0xefcdab89, ctemp = 0x98badcfe, dtemp = 0x10325476;
		unsigned int strByte[16];
		for (int i = 0; i < 16; ++i)	strByte[i] = 0;	int tmp = Password.length();	tmp--;
		for (int i = 0; i <= tmp; ++i)	strByte[i>>2] |= (Password[i])<<((i%4)*8);
		strByte[tmp>>2] |= 0x80<<(((tmp%4))*8), strByte[16-2] = tmp*8;
		unsigned int f, g, a = atemp, b = btemp, c = ctemp, d = dtemp;
		for (int i = 0; i < 64; ++i)
		{
			if (i < 16)	f = F(b,c,d), g = i;
			else if (i < 32)	f = G(b,c,d), g = (5*i+1)%16;
			else if (i < 48)	f = H(b,c,d), g = (3*i+5)%16;
			else	f = I(b,c,d), g = (7*i)%16;
			unsigned int tmp = d;
	        d = c, c = b, b = b+shift((a+f+k[i]+strByte[g]),s[i]), a = tmp;
		}
		atemp += a, btemp += b, ctemp += c, dtemp += d;
		return Hex(atemp).append(Hex(btemp)).append(Hex(ctemp)).append(Hex(dtemp));
	}
public:
	DataBase_Account( const string &Name = "Default" )
	{
		ThisAccountName = Name;
		accNums = 0;
		Numbers.clear();
		accData.clear();
	}
	~DataBase_Account();

	//Register or lead-in a NEW account.
	//return 0:illegal 1:used-ID 2:succeed.
	int Register( const Account &NewAccout, const string &Password = "000000" )
	{
		string Id = NewAccout.id;
		if (Password.length()>16 || Id.length()>16)	return 0;//too long,else allow all kinds of password
		if (Id == "Default")	return 0;//I don't know weather its legal will make trouble
		if (getIdNumber(Id) != 0)	return 1;
		Numbers[Id] = ++accNums;
		Account temp = NewAccout;
		temp.passwordHash = getPasswordHash(Password);
		temp.id_number = accNums;
		accData[accNums] = temp;
		return 2;
	}
	//I dont know how to write so templatly use map
	//Get the id_number by your string Id ( in logn ).
	//return 0:not find
	int getIdNumber( const string &Id )
	{
		return Numbers[Id];
	}

private:
	string ThisAccountName;
	int accNums;
	map<string,int> Numbers;
	map<int,Account> accData;
};
//A class for save the user who connect with server.
//So it will never save data.
//User and Account
class DataBase_User : public DataBase_Base             //前后端分离进行身份验证,
{
public:
	DataBase_User( const string &Name = "Default") 
	{
		nowTempId = 0;
		ThisUsersName = Name;
		userData.clear();
		nowAccData = NULL;
	}
	~DataBase_User()
	{
		nowAccData = NULL;
	}

	// Login with your account id and password.
	// return 0: failed
	// return else : template id
	int login( const string &ID, const string &password )
	{
		if (nowAccData == NULL)	return 0;
		int Temp = nowAccData->getIdNumber(ID);
		if (Temp == 0)	return 0;
		if (nowAccData->getPasswordHash(password) != nowAccData->accData[Temp].passwordHash)	return 0;
		userData[++nowTempId] = Temp;
		return nowTempId;
	}

	//-1:not exist.
	int query_identifyType( int UserId )
	{
		if (nowAccData == NULL)	return 0;
		if (userData[UserId] == 0)	return -1;
		return nowAccData->accData[userData[UserId]].self.identifyType;
	}
private:
	bool logout( const int id )
	{
		if (userData[id] == 0)	return 0;
		userData.erase(id);		return 1;
	}
	string ThisUsersName;
	int nowTempId;
	map<int,int> userData;
	DataBase_Account *nowAccData;
};
//The data base of Train and Stations.
class DataBase_Train : public DataBase_Base
{
	//we suppose there're such kinds of tickets
	enum ticType{ydz,edz,wz,swz,yz,rz,tdz,rwx,gjrw};
	struct Ticket
	{
		int number,//left tickets numbers
		price,		//price*100 from start
		miles;		//distance from strat
		Ticket():number(200),price(-1),miles(0){};
	};
	
	struct tcra
	{
		string name;
		int days;
		tcra(string a, int b):name(a),days(b){}
		bool operator<(const tcra &a)
		{
			if (name < a.name)	return true;
			return days<a.days;
		}
	};
	//A train schedule.
	struct Train
	{
		//Id for saving and finding quickly.
		int id_number;
		//The same train in different days is consider different
		int days;//from 3-28
		//
		string trainNumber;

		//real ID of stations.
		vector<int>stations;

		//Numbers of different types of tickets.
		int nType;
		vector<ticType>ticketType;

		//real price*100
		//The price of tickets. price[i]-price[j]
		//price[i]==-1 means you can't buy a ticket which reaches station i.
		//maybe use like this traData[id_number].tickets[ydz][12].price = 10000;
		vector<vector<Ticket> > tickets;
		
		//I really don't know how many kinds of times will be used here???
		vector<int>reachTime;
		vector<int>startTime;
		Train operator=(const Train &tra)
		{
			days = tra.days;
			id_number = tra.id_number;
			trainNumber = tra.trainNumber;
			stations = tra.stations;
			nType = tra.nType;
			ticketType = tra.ticketType;
			tickets = tra.tickets;
			reachTime = tra.reachTime;
			startTime = tra.startTime;
		}
	};
	int traNums;
	string thisTrainName;
	map<tcra,int> insell;
	map<int,Train> traData;
public:
	DataBase_Train( const string &Name = "Default" )
	{
		thisTrainName = Name;
		traNums = 0;
		traData.clear();
	}
	~DataBase_Train()
	{
		traNums = 0;
	}
	void addNewTrain( const Train &t )
	{
		//if there already such train, i regard this as change information  
		tcra nowTra(t.trainNumber,t.days);
		Train tmp = t;
		if (insell.find(nowTra) == insell.end())
			tmp.id_number = ++traNums;
		else	tmp.id_number = insell[nowTra];
		traData[traNums] = tmp;
		insell[nowTra] = tmp.id_number;
	}
	bool deleteTrain(const int id)
	{
		//no such train in sell
		if (traData.find(id) == traData.end())	return 0;
		Train tmp = traData[id];
		tcra nowTra(tmp.trainNumber,tmp.days);
		insell.erase(nowTra), traData.erase(id);
		return 1;
	}
};
