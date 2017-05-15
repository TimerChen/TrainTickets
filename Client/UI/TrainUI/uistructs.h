#ifndef UISTRUCTS_H
#define UISTRUCTS_H

//#include "mainwindow.h"
#include <QString>

namespace uistructs {
enum { annonymous, normal, admin };
struct nowAccount {
    int userType;
    QString name;
    QString userID;
    // QString IDcard;
    nowAccount(int _userType = annonymous, QString _name = "",
               QString _userID = "");
};
}

#endif  // UISTRUCTS_H
