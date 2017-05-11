#include <QMessageBox>
#include "mainwindow.h"
#include "regist.h"
#include "login.h"
#include "ui_mainwindow.h"
#include "myticket.h"
#include "myinform.h"
#include "stationtostationsearch.h"
#include "stationsearch.h"
#include "trainsearch.h"
#include "adminwindow.h"

MainWindow::MainWindow(QWidget *parent, int user) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    userType(user)
{
    ui->setupUi(this);
    ui->myticketBtn->setEnabled(false);
    ui->myinformBtn->setEnabled(false);
    ui->logoutBtn->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginBtn_clicked()
{
    Login log(this);
    if (log.exec() == QDialog::Accepted) {
        //add something that show you have loged in
        userType = log.getUserType();
        ui->loginBtn->setEnabled(false);
        ui->regBtn->setEnabled(false);
        ui->myinformBtn->setEnabled(true);
        ui->logoutBtn->setEnabled(true);
        ui->myticketBtn->setEnabled(true);
       if (userType == Ui::admin) {
            AdminWindow adw(this);
            this->hide();
            adw.exec();
            this->show();
            this->on_logoutBtn_clicked();
        }
    }
}

void MainWindow::on_regBtn_clicked()
{
    Regist reg(this);
    reg.exec();
}

void MainWindow::on_logoutBtn_clicked()
{
    ///send a package to server to log out
    ui->myticketBtn->setEnabled(false);
    ui->myinformBtn->setEnabled(false);
    ui->logoutBtn->setEnabled(false);
    ui->loginBtn->setEnabled(true);
    ui->regBtn->setEnabled(true);
    userType = Ui::annonymous;
}

void MainWindow::on_myticketBtn_clicked()
{
    Myticket myticket(this,userType);

    myticket.exec();
}

void MainWindow::on_myinformBtn_clicked()
{
    Myinform myinform(this,userType);

    myinform.exec();

}

void MainWindow::on_stationToStationSearchBtn_clicked()
{
    StationToStationSearch s(this,userType);

    s.exec();
}

void MainWindow::on_trainSearchBtn_clicked()
{
    TrainSearch s(this,userType);

    s.exec();

}

void MainWindow::on_stationSearchBtn_clicked()
{
    StationSearch s(this,userType);

    s.exec();

}
