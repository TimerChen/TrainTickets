#include <QMessageBox>
#include "mainwindow.h"
#include "regist.h"
#include "login.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->myticketBtn->hide();
    ui->modifyAccountBtn->hide();
    ui->logoutBtn->hide();
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
        ui->loginBtn->hide();
        ui->regBtn->hide();
        ui->myticketBtn->show();
        ui->modifyAccountBtn->show();
        ui->logoutBtn->show();
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
    ui->myticketBtn->hide();
    ui->modifyAccountBtn->hide();
    ui->logoutBtn->hide();
    ui->loginBtn->show();
    ui->regBtn->show();
}
