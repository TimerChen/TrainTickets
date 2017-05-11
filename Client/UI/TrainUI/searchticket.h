#ifndef SEARCHTICKET_H
#define SEARCHTICKET_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class SearchTicket;
}

class SearchTicket : public QDialog
{
    Q_OBJECT

public:
    explicit SearchTicket(QWidget *parent = 0, int user = Ui::annonymous, int search = Ui::stationToStation);
    ~SearchTicket();

private slots:

    void on_buyTicketBtn_clicked();

private:
    Ui::SearchTicket *ui;
    int userType;
    int searchType;
};

#endif // SEARCHTICKET_H
