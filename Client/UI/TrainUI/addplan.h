#ifndef ADDPLAN_H
#define ADDPLAN_H

#include <QDialog>
#include "include/smartpoint.hpp"
#include "include/vector.hpp"
#include "uistructs.h"
#include <QStandardItemModel>

namespace Ui {
class addPlan;
}

class addPlan : public QDialog
{
    Q_OBJECT

public:
    explicit addPlan(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent = 0);
    ~addPlan();

private:
    Ui::addPlan *ui;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
    ttd::shared_ptr<QStandardItemModel> modelSeatType;
    ttd::shared_ptr<QStandardItemModel> modelStation;
};

#endif // ADDPLAN_H
