#ifndef MYTICKET_H
#define MYTICKET_H

#include <QDialog>
#include <QStandardItemModel>
#include "mainwindow.h"

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
    ttd::shared_ptr<QStandardItemModel> model;
};

#endif  // MYTICKET_H
