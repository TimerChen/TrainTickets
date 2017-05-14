#ifndef ADDPLANSIMPLE_H
#define ADDPLANSIMPLE_H

#include <QDialog>
#include "include/smartpoint.hpp"
#include "uistructs.h"

namespace Ui {
class addplansimple;
}

class addplansimple : public QDialog
{
    Q_OBJECT

public:
    explicit addplansimple(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent = 0);
    ~addplansimple();

private slots:
    void on_addPlanBtn_clicked();

private:
    Ui::addplansimple *ui;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif // ADDPLANSIMPLE_H
