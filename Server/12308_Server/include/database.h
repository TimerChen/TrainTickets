/*
	Writed by Jingxiao Chen.
*/

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
#include <QString>
#include "include/vector.hpp"
#include "include/map.hpp"
#include "include/smartpoint.hpp"

namespace ttd {
	template <class T>
	class vector;
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
	QString dataBase_name;
	DataBase_Base( const QString &Name = "Default" );
	~DataBase_Base();
protected:
	void loadData();
	void saveData();
};





#endif
