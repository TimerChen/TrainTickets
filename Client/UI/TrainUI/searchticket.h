#ifndef SEARCHTICKET_H
#define SEARCHTICKET_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class SearchTicket;
}

class SearchTicket : public QDialog {
    Q_OBJECT

  public:
    explicit SearchTicket(ttd::shared_ptr<uistructs::nowAccount> _now,
                          QWidget *parent = 0,
                          int search = Ui::stationToStation);
    ~SearchTicket();

  private slots:

    void on_buyTicketBtn_clicked();

  private:
    Ui::SearchTicket *ui;
    int searchType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif // SEARCHTICKET_H
