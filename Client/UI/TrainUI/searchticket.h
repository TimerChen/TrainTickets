#ifndef SEARCHTICKET_H
#define SEARCHTICKET_H

#include "mainwindow.h"
#include <QDialog>
#include <QStandardItemModel>
#include <QDate>

namespace Ui {
class SearchTicket;
}

class SearchTicket : public QDialog {
    Q_OBJECT

  public:
    explicit SearchTicket(QDate _date, ttd::shared_ptr<uistructs::nowAccount> _now,
                          QWidget *parent = 0,
                          int search = Ui::stationToStation);
    ~SearchTicket();

  private slots:

    void on_buyTicketBtn_clicked();

  private:
    Ui::SearchTicket *ui;
    int searchType;

    QDate date;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
    ttd::shared_ptr<QStandardItemModel> model;
};

#endif // SEARCHTICKET_H
