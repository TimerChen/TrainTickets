#ifndef MYTICKET_H
#define MYTICKET_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Myticket;
}

class Myticket : public QDialog {
    Q_OBJECT

  public:
    explicit Myticket(ttd::shared_ptr<uistructs::nowAccount> _now,
                      QWidget *parent = 0);
    ~Myticket();

private slots:
    void on_modifyTicketBtn_clicked();

private:
    Ui::Myticket *ui;
    // int userType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif // MYTICKET_H
