#include <cstdio>
#include <string>
#include "DataBase_Account.h"
char DataBase_Account::str16[]= "0123456789abcdef";
unsigned int DataBase_Account::k[] = {0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,0xa679438e,0x49b40821,0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
unsigned int DataBase_Account::s[] = {7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22,5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20,4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21};
DataBase_Account::IdentifyInformation DataBase_Account::IdentifyInformation::operator=(const IdentifyInformation &he)
{
	name = he.name;
	identificationCardNumber = he.identificationCardNumber;
	identifyType = he.identifyType;
	age = he.age;
	return*this;
}



DataBase_Account::Account DataBase_Account::Account::operator=(const Account &acc)
{
	id_number = acc.id_number;
	id = acc.id, passwordHash = acc.passwordHash;
	self = acc.self;
	friends = acc.friends;
	return*this;
}

DataBase_Account::Account::Account(const std::string &Id, const short identifyType)
{
	//no id number
	id_number = -1;
	//id and passwordhash = hash("000000")
	id = Id, passwordHash = "e1119c269cdb64f851aef6db68c49610";
	//unknown means -1
	self.age = -1;
	self.name = "Default";;
	self.identifyType = identifyType;
	//aha
	self.identificationCardNumber = "000000000000000000";
	// we have no friends
	friends.clear();
	//not admin
	isAdmin = 0;
}
std::string DataBase_Account::Hex(int a)
{
	int b;
	std::string str1, Password = "";
	for (int i = 0; i < 4; ++i)
	{
		str1 = "";
		b = ((a>>i*8)%(1<<8))&0xff;
		for (int j = 0; j < 2; ++j)	str1.insert(0,1,str16[b%16]), b /= 16;
		Password += str1;
	}
	return Password;
}

std::string DataBase_Account::getPasswordHash( const std::string &Password )
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

DataBase_Account::DataBase_Account( const std::string &Name)
{
	DataBase_Account::dataBase_name = Name;
	accNums = 0;
	Numbers.clear();
	accData.clear();
}

int DataBase_Account::Register( const Account &NewAccout, const std::string &Password)
{
	std::string Id = NewAccout.id;
	if (Password.length()>16 || Id.length()>16)	return 0;//too long
	if (Id == "Default")	return 1;					// we don't allow some call this name
	if (getIdNumber(Id) != -1)	return 1;				// UserId used
	Account tmp = NewAccout;
	tmp.id_number = accNums;
	tmp.passwordHash = getPasswordHash(Password);
	Numbers[Id] = accNums++;
	accData.push_back(tmp);
	return 2;
}
	
int DataBase_Account::getIdNumber( const std::string &Id )
{
	if (Numbers.find(Id) == Numbers.end())	return -1;	//not found
	return Numbers[Id];
}


DataBase_Account::Account DataBase_Account::query_account(std::string ID)
{
	Account a;	int temp = getIdNumber(ID);
	// if there is no such account, return default information
	return accData[temp];
}

void DataBase_Account::modify_account(int Id, const Account &AccountInfo )
{
	accData[Id] = AccountInfo;
}

DataBase_Account::~DataBase_Account()
{
	
}
int main()
{
}
