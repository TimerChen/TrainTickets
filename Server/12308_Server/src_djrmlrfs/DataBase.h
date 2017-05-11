#ifndef DATABASE_H
#define DATABASE_H
/*
	We need Map/HashMap , Vector and ID Manager.
*/

/*
	Base class of Data bases.
*/

//A class for translate time more conveniently.
//That is
#include <string>
#include "vector.hpp"
#include "smartpoint.hpp"
#include "map.hpp"
namespace ttd {
	template <class T>
	class vector;
	template<class Key,class T,class Compare
	>class map;
}
class Train;
class QTrain;
class Ticket;
class Account;
class DataBase_Account;
class DataBase_Log;
class DataBase_User;
class DataBase_Train;



class DataBase_Base
{
public:
	std::string dataBase_name;
	DataBase_Base( const std::string &Name = "Default" )
	:dataBase_name( Name )
	{  }
	virtual ~DataBase_Base()
	{  }
protected:
	virtual void loadData(){};
	virtual void saveData(){};
};

#endif
