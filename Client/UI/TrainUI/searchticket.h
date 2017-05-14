#ifndef SEARCHTICKET_H
#define SEARCHTICKET_H

#include <QDate>
#include <QDialog>
#include <QRegExpValidator>
#include <QStandardItemModel>
#include "mainwindow.h"

namespace Ui {
class SearchTicket;
}

class SearchTicket : public QDialog {
    Q_OBJECT

   public:
    explicit SearchTicket(QDate _date,
                          ttd::shared_ptr<uistructs::nowAccount> _now,
                          int search, QString _ask1, QWidget *parent = 0,
                          QString _ask2 = "");
    ~SearchTicket();

   private slots:

    void on_buyTicketBtn_clicked();

   private:
    Ui::SearchTicket *ui;
    int searchType;

    QDate date;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
    ttd::shared_ptr<QStandardItemModel> model;
    QString ask1, ask2;
    ttd::shared_ptr<QRegExpValidator> pReg;
};

#endif  // SEARCHTICKET_H
