#include "DataBase_Account.h"
char DataBase_Account::str16[]= "0123456789abcdef";
unsigned int DataBase_Account::k[] = {0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,0xa679438e,0x49b40821,0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
unsigned int DataBase_Account::s[] = {7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22,5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20,4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21};
DataBase_Account::Account DataBase_Account::Account::operator=(const Account &acc)
{
	id_number = acc.id_number;
	id = acc.id, name = acc.name;
	passwordHash = acc.passwordHash;
	isAdmin = acc.isAdmin, log = acc.log;
	bought = acc.bought;
}
QString DataBase_Account::Hex(int a)
{
	int b;
	QString str1, Password = "";
	for (int i = 0; i < 4; ++i)
	{
		str1 = "";
		b = ((a>>i*8)%(1<<8))&0xff;
		for (int j = 0; j < 2; ++j)	str1.insert(0,1,str16[b%16]), b /= 16;
		Password += str1;
	}
	return Password;
}

QString DataBase_Account::getPasswordHash( const QString &Password )
{
	unsigned int strlength, atemp = 0x67452301, btemp = 0xefcdab89, ctemp = 0x98badcfe, dtemp = 0x10325476;
	unsigned int strByte[16];
	for (int i = 0; i < 16; ++i)	strByte[i] = 0;	int tmp = Password.length();	tmp--;
	for (int i = 0; i <= tmp; ++i)	strByte[i>>2] |= (Password[i])<<((i%4)*8);
	strByte[tmp>>2] |= 0x80<<(((tmp%4))*8), strByte[16-2] = tmp*8;
	unsigned int f, g, a = atemp, b = btemp, c = ctemp, d = dtemp;
	for (int i = 0; i < 64; ++i)
	{
		if (i < 16)	f = ((b^c)|((~b)&d)), g = i;
		else if (i < 32)	f = ((b&d)|(c&(~d))), g = (5*i+1)%16;
		else if (i < 48)	f = (b^c^d), g = (3*i+5)%16;
		else	f = ((b^c)|(~d)), g = (7*i)%16;
		unsigned int tmp = d, x = a+f+k[i]+strByte[g];
        d = c, c = b, b = b+((x<<s[i])|(x>>(32-s[i]))), a = tmp;
	}
	atemp += a, btemp += b, ctemp += c, dtemp += d;
	return Hex(atemp).append(Hex(btemp)).append(Hex(ctemp)).append(Hex(dtemp));
}

DataBase_Account::DataBase_Account( const QString &Name)
{
	dataBase_name = Name;
	accNums = 0;
	Numbers.clear();
	accData.clear();
}
int DataBase_Account::Register( const Account &NewAccout, const QString &Password)
{
	QString Id = NewAccout.id;
	if (Password.length()>16 || Id.length()>16)	return 0;//too long
	if (Id == "Default")	return 1;					// we don't allow some call this name
	if (getIdNumber(Id) != -1)	return 1;				// UserId used
	Account tmp = NewAccout;
	tmp.id_number = accNums;
	if (Password!="000000")	tmp.passwordHash = getPasswordHash(Password);
	Numbers[Id] = accNums++;
	accData.push_back(tmp);
	return 2;
}
	
int DataBase_Account::getIdNumber( const QString &Id )
{
	if (Numbers.find(Id) == Numbers.end())	return -1;	//not found
	return Numbers[Id];
}


DataBase_Account::Account DataBase_Account::queryAccount(QString ID)
{
	return accData[getIdNumber(ID)];
}

DataBase_Account::Account DataBase_Account::queryAccount(int ID)
{
	return accData[ID];
}

void DataBase_Account::modifyAccount(const int &Id, const QString &newPassword, const QString &newName)
{
	accData[Id].name = newName;
	accData[Id].passwordHash = getPasswordHash(newPassword);
}

DataBase_Account::~DataBase_Account()
{
}

int DataBase_Account::buyTicket(const int &Id, const QString &trainId, const QString &from, const QString &to,
	const QDateTime &fromTime, const QDateTime &toTime, const int &price, const QString &type, const int &num)
{
	//please cheak weather num < 0 or num > leftnum
	Ticket tmp(accData[Id].name,from,to,trainId,fromTime,toTime,price,type);
	accData[Id].bought[tmp] += num, accData[Id].log.push_back(ticLog(trainId,from,to,fromTime,num));
	return price*num;
}
int DataBase_Account::returnTicket(const int &Id, const QString &trainId, const QString &from, const QString &to,
	const QDateTime &fromTime, const QDateTime &toTime, const int &price, const QString &type, const int &num)
{
	//please cheak weather num < 0 or num > leftnum
	//the front can insure there is such ticket
	Ticket tmp(accData[Id].name,from,to,trainId,fromTime,toTime,price,type);
	ttd::map<Ticket,int>::iterator it = accData[Id].bought.find(tmp);
	it->second -= num;
	if (0==it->second)
	{
		accData[Id].bought.erase(it);
	}
	accData[Id].log.push_back(ticLog(trainId,from,to,fromTime,-num));
	return price*num;
}
ttd::vector<DataBase_Account::ticLog> DataBase_Account::quiryLog(const int &Id)
{
	return accData[Id].log;
}
ttd::map<DataBase_Account::Ticket,int> DataBase_Account::ownedTicket(const int &Id)
{
	return accData[Id].bought;
}
