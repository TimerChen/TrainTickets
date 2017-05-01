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
    ui->myticketBtn->setEnabled(false);
    ui->modifyAccountBtn->setEnabled(false);
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
        ui->loginBtn->setEnabled(false);
        ui->regBtn->setEnabled(false);
        ui->myticketBtn->setEnabled(true);
        ui->modifyAccountBtn->setEnabled(true);
        ui->logoutBtn->setEnabled(true);
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
    ui->modifyAccountBtn->setEnabled(false);
    ui->logoutBtn->setEnabled(false);
    ui->loginBtn->setEnabled(true);
    ui->regBtn->setEnabled(true);
}
