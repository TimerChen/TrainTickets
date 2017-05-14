#ifndef SEARCHUSR_H
#define SEARCHUSR_H

#include <QDialog>
#include "uistructs.h"
#include "include/smartpoint.hpp"

namespace Ui {
class searchUsr;
}

class searchUsr : public QDialog
{
    Q_OBJECT

public:
    explicit searchUsr(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent = 0);
    ~searchUsr();

private slots:
    void on_searchBtn_clicked();

private:
    Ui::searchUsr *ui;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif // SEARCHUSR_H
