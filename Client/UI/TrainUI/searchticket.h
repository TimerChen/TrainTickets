#ifndef SEARCHTICKET_H
#define SEARCHTICKET_H

#include <QDialog>

namespace Ui {
class SearchTicket;
}

class SearchTicket : public QDialog
{
    Q_OBJECT

public:
    explicit SearchTicket(QWidget *parent = 0);
    ~SearchTicket();

private slots:

    void on_buyTicketBtn_clicked();

private:
    Ui::SearchTicket *ui;
};

#endif // SEARCHTICKET_H
