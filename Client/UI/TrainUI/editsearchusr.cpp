#include "editsearchusr.h"
#include "ui_editsearchusr.h"
#include "myticket.h"
#include "myinform.h"
#include "stationsearch.h"
#include "stationtostationsearch.h"
#include "trainsearch.h"

editSearchUsr::editSearchUsr(
    ttd::shared_ptr<uistructs::nowAccount> _editaccount, QWidget *parent, QString _adminID, QString _adminName)
    : QDialog(parent), ui(new Ui::editSearchUsr), editaccount(_editaccount), adminID(_adminID),adminName(_adminName) {
    ui->setupUi(this);
    ui->welcomeLabel_2->setText("管理员：" + adminName + "， 您好！");
    ui->nameLabel_2->setText("您正在修改用户:\tID: " + editaccount->userID +
                           "\t用户名：" + editaccount->userID + "的信息");
}

editSearchUsr::~editSearchUsr() { delete ui; }

void editSearchUsr::on_myticketBtn_2_clicked()
{
    Myticket myticket(editaccount, this, adminID, adminName);

        myticket.exec();
}

void editSearchUsr::on_myinformBtn_2_clicked()
{
    Myinform myinform(editaccount, this, adminID, adminName);

       myinform.exec();
}

void editSearchUsr::on_stationToStationSearchBtn_2_clicked()
{
    StationToStationSearch s(editaccount, this, adminID, adminName);

       s.exec();
}

void editSearchUsr::on_trainSearchBtn_2_clicked()
{
    TrainSearch s(editaccount, this);

    s.exec();
}

void editSearchUsr::on_stationSearchBtn_2_clicked()
{
    StationSearch s(editaccount, this);

    s.exec();
}

void editSearchUsr::on_deleteUsrBtn_clicked()
{
    ///发送frontask::admindeleteusr
    /// 发送pair(nowaccount->userID, adminID)
    this->close();
}
