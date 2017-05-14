#ifndef EDITSEARCHUSR_H
#define EDITSEARCHUSR_H

#include <QDialog>
#include "include/smartpoint.hpp"
#include "uistructs.h"

namespace Ui {
class editSearchUsr;
}

class editSearchUsr : public QDialog {
    Q_OBJECT

   public:
    explicit editSearchUsr(ttd::shared_ptr<uistructs::nowAccount> _editaccount,
                           QWidget *parent = 0, QString _adminID = "",
                           QString _adminName = "");
    ~editSearchUsr();

private slots:
    void on_myticketBtn_2_clicked();

    void on_myinformBtn_2_clicked();

    void on_stationToStationSearchBtn_2_clicked();

    void on_trainSearchBtn_2_clicked();

    void on_stationSearchBtn_2_clicked();

    void on_deleteUsrBtn_clicked();

private:
    Ui::editSearchUsr *ui;
    ttd::shared_ptr<uistructs::nowAccount> editaccount;
    QString adminID;
    QString adminName;
};

#endif  // EDITSEARCHUSR_H
