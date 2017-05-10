#ifndef TOSERVERSTRUCTS_H
#define TOSERVERSTRUCTS_H
#include <QTime>

class ToServerStructs
{
public:
    ToServerStructs();
    struct buyTickets{
        std::string trainID;
        std::string seatType;
        std::string loadStation, unLoadStation;
        QTime reachTime, leaveTime;
    };
};

#endif // TOSERVERSTRUCTS_H
