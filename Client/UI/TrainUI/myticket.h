#ifndef MYTICKET_H
#define MYTICKET_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Myticket;
}

class Myticket : public QDialog
{
    Q_OBJECT

public:
    explicit Myticket(QWidget *parent = 0, int user = Ui::annonymous);
    ~Myticket();

private:
    Ui::Myticket *ui;
    int userType;
};

#endif // MYTICKET_H
