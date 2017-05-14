#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "include/smartpoint.hpp"
#include "uistructs.h"
#include "addplan.h"
#include "trainsearch.h"
#include "addplansimple.h"

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
