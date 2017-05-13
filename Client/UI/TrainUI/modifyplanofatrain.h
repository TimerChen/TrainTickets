#ifndef MODIFYPLANOFATRAIN_H
#define MODIFYPLANOFATRAIN_H

#include "include/smartpoint.hpp"
#include "uistructs.h"
#include <QDialog>

namespace Ui {
class modifyPlanOfATrain;
}

class modifyPlanOfATrain : public QDialog {
    Q_OBJECT

  public:
    explicit modifyPlanOfATrain(ttd::shared_ptr<uistructs::nowAccount> _now,
                                QWidget *parent = 0);
    ~modifyPlanOfATrain();

private slots:
    void on_deleteTrainBtn_clicked();

    void on_stopSellBtn_clicked();

    void on_startsellBtn_clicked();

private:
    Ui::modifyPlanOfATrain *ui;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif // MODIFYPLANOFATRAIN_H
