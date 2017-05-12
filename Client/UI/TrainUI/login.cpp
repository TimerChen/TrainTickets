#include "login.h"
#include "include/smartpoint.hpp"
#include "regist.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent)
    : QDialog(parent), ui(new Ui::Login), nowaccount(_now) {
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->usrLineEdit->setFocus();
    setTabOrder(ui->usrLineEdit, ui->pwdLineEdit);
    setTabOrder(ui->pwdLineEdit, ui->loginBtn);
    setTabOrder(ui->loginBtn, ui->auloginBtn);
    setTabOrder(ui->auloginBtn, ui->registBtn);
    setTabOrder(ui->registBtn, ui->exitBtn);
    setTabOrder(ui->exitBtn, ui->usrLineEdit);
    QRegExp rx("^[a-zA-Z0-9]+");
    QRegExpValidator *pReg =
        new QRegExpValidator(rx, this); /// change to smart point
    ui->pwdLineEdit->setValidator(pReg);
    ui->pwdLineEdit->setMaxLength(12);

    ui->usrLineEdit->setMaxLength(12);
    ui->usrLineEdit->setValidator(pReg);
}

Login::~Login() { delete ui; }

void Login::on_loginBtn_clicked() {
    if (ui->usrLineEdit->text() == "mw" &&
        ui->pwdLineEdit->text() == "123456") { // send ui->usrLineEdit->text()
                                               // and ui->pwdLineEdit->text()
        // to the server to check normal account, change the thing in if()
        // get the account detail from the server

        nowaccount->userType = Ui::normal;
        // nowaccount->name =
        nowaccount->userID = ui->usrLineEdit->text();
        // nowaccount->IDcard =
        accept();
    } else {
        ui->pwdLineEdit->clear();
        ui->pwdLineEdit->setFocus();
        QMessageBox::warning(this, tr("警告"), tr("用户名或密码错误！"),
                             QMessageBox::Yes);
    }
}

void Login::on_auloginBtn_clicked() { // unavailable now
    if (ui->usrLineEdit->text() == "mw" &&
        ui->pwdLineEdit->text() == "123456") { // send ui->usrLineEdit->text()
                                               // and ui->pwdLineEdit->text()
        // to the server to check normal account, change the thing in if()
        // get the account detail from the server

        nowaccount->userType = Ui::admin;
        // nowaccount->name =
        nowaccount->userID = ui->usrLineEdit->text();
        // nowaccount->IDcard =
        accept();
    } else {
        QMessageBox::warning(this, tr("警告"), tr("用户名或密码错误！"),
                             QMessageBox::Yes);
    }
}

void Login::on_registBtn_clicked() {
    Regist reg(this);
    reg.exec();
}
