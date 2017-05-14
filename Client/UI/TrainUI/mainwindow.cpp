#include "mainwindow.h"
#include <QMessageBox>
#include "adminwindow.h"
#include "login.h"
#include "myinform.h"
#include "myticket.h"
#include "regist.h"
#include "stationsearch.h"
#include "stationtostationsearch.h"
#include "trainsearch.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      nowaccount(new uistructs::nowAccount) {
    ui->setupUi(this);
    ui->myticketBtn->setEnabled(false);
    ui->myinformBtn->setEnabled(false);
    ui->logoutBtn->setEnabled(false);
    ui->nameLabel->hide();
    ui->welcomeLabel->hide();

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_loginBtn_clicked() {
    Login log(nowaccount, this);
    if (log.exec() == QDialog::Accepted) {
        int userType = nowaccount->userType;
        ui->loginBtn->setEnabled(false);
        ui->regBtn->setEnabled(false);
        ui->myinformBtn->setEnabled(true);
        ui->logoutBtn->setEnabled(true);
        ui->myticketBtn->setEnabled(true);
        ui->welcomeLabel->show();
        ui->nameLabel->show();
        ui->nameLabel->setText(nowaccount->name + "!!");
        if (userType == Ui::admin) {
            AdminWindow adw(nowaccount, this);
            this->hide();
            if(adw.exec() == QDialog::Accepted) this->show();
            else qApp->quit();
            this->on_logoutBtn_clicked();
        }
    }
}

void MainWindow::on_regBtn_clicked() {
    Regist reg(this);
    reg.exec();
}

void MainWindow::on_logoutBtn_clicked() {
    /// send a package to server to log out
    ui->myticketBtn->setEnabled(false);
    ui->myinformBtn->setEnabled(false);
    ui->logoutBtn->setEnabled(false);
    ui->loginBtn->setEnabled(true);
    ui->regBtn->setEnabled(true);
    nowaccount->userType = Ui::annonymous;
    nowaccount->name = "";
    nowaccount->userID = "";
    // nowaccount->IDcard = "";
    ui->nameLabel->hide();
    ui->welcomeLabel->hide();
}

void MainWindow::on_myticketBtn_clicked() {
    Myticket myticket(nowaccount, this);

    myticket.exec();
}

void MainWindow::on_myinformBtn_clicked() {
    Myinform myinform(nowaccount, this);

    myinform.exec();
}

void MainWindow::on_stationToStationSearchBtn_clicked() {
    StationToStationSearch s(nowaccount, this);

    s.exec();
}

void MainWindow::on_trainSearchBtn_clicked() {
    TrainSearch s(nowaccount, this);

    s.exec();
}

void MainWindow::on_stationSearchBtn_clicked() {
    StationSearch s(nowaccount, this);

    s.exec();
}
