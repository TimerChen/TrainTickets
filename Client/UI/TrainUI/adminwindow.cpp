#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "include/smartpoint.hpp"
#include "uistructs.h"
#include "addplan.h"
#include "trainsearch.h"
#include "addplansimple.h"
#include "myinform.h"
#include "searchusr.h"
#include "syslog.h"

AdminWindow::AdminWindow(
    ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent)
    : QDialog(parent), ui(new Ui::AdminWindow), nowaccount(_now) {
    ui->setupUi(this);
    ui->nameLabel->setText(nowaccount->name);
}

AdminWindow::~AdminWindow() { delete ui; }

void AdminWindow::on_addPlanBtn_clicked()
{
    addplansimple ap(nowaccount, this);
    ap.exec();
}

void AdminWindow::on_trainSearchBtn_clicked()
{
    TrainSearch s(nowaccount, this);
    s.exec();
}

void AdminWindow::on_myinformBtn_clicked()
{
    Myinform m(nowaccount, this);
    m.exec();
    ui->nameLabel->setText(nowaccount->name);
}

void AdminWindow::on_searchAccountBtn_clicked()
{
    searchUsr su(nowaccount, this);
    su.exec();
}

void AdminWindow::on_pushButton_clicked()
{
    sysLog sl(nowaccount->userID, this);
    sl.exec();
}
