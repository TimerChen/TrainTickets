#include "login.h"
#include "include/smartpoint.hpp"
#include "regist.h"
#include "ui_login.h"
#include <QMessageBox>
#include "include/utility.hpp"
#include "toserverstructs.h"

Login::Login(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent)
    : QDialog(parent), ui(new Ui::Login), nowaccount(_now) {
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->usrLineEdit->setFocus();
    setTabOrder(ui->usrLineEdit, ui->pwdLineEdit);
    setTabOrder(ui->pwdLineEdit, ui->loginBtn);
    setTabOrder(ui->loginBtn, ui->auloginBtn);
    //setTabOrder(ui->auloginBtn, ui->registBtn);
    //setTabOrder(ui->registBtn, ui->exitBtn);
    setTabOrder(ui->auloginBtn,ui->exitBtn);
    setTabOrder(ui->exitBtn, ui->usrLineEdit);
    QRegExp rx("^[a-zA-Z0-9_]+");
    pReg = new QRegExpValidator(rx, this);
    ui->pwdLineEdit->setValidator(pReg.getadress());
    ui->pwdLineEdit->setMaxLength(12);

    ui->usrLineEdit->setMaxLength(12);
    ui->usrLineEdit->setValidator(pReg.getadress());
}

Login::~Login() { delete ui; }

void Login::on_loginBtn_clicked() {
    frontask::loginAccount ac(ui->usrLineEdit->text(), ui->pwdLineEdit->text());

	ttd::pair<int, QString> serverReturn;
    serverReturn = ((MainWindow*)parentWidget())->login_remote
			(ui->usrLineEdit->text(), ui->pwdLineEdit->text());


	if ( serverReturn.first > 0 ||
		(ui->usrLineEdit->text() == "mw" &&
		ui->pwdLineEdit->text() == "123456") ) {
        ///发送login
        /// 发送ac
        // to the server to check normal account, change the thing in if()
        // get the account detail from the server

        nowaccount->userType = Ui::normal;
		nowaccount->name = serverReturn.second;
        nowaccount->userID = ui->usrLineEdit->text();
        // nowaccount->IDcard =


        accept();
    } else {
        ui->pwdLineEdit->clear();
        ui->pwdLineEdit->setFocus();
		QMessageBox::warning(this, tr("警告"), serverReturn.second,
                             QMessageBox::Cancel);
    }
}

void Login::on_auloginBtn_clicked() {
	frontask::loginAccount ac(ui->usrLineEdit->text(), ui->pwdLineEdit->text());

    ttd::pair<int, QString> serverReturn;
    serverReturn = ((MainWindow*)parentWidget())->aulogin_remote
            (ui->usrLineEdit->text(), ui->pwdLineEdit->text());

    if (serverReturn.first > 0 ||(ui->usrLineEdit->text() == "mw" &&
        ui->pwdLineEdit->text() == "123456")) {
        ///发送aulogin
        /// 发送ac
        // to the server to check admin account, change the thing in if()
        // get the account detail from the server

        nowaccount->userType = Ui::admin;
        nowaccount->name = serverReturn.second;
        nowaccount->userID = ui->usrLineEdit->text();
        // nowaccount->IDcard =
        accept();
    } else {
        ui->pwdLineEdit->clear();
        ui->pwdLineEdit->setFocus();
        QMessageBox::warning(this, tr("警告"), tr("用户名或密码错误！"),
                             QMessageBox::Cancel);
    }
}

//void Login::on_registBtn_clicked() {
//    Regist reg(this);
//    reg.exec();
//}

void Login::setAuloginEnable(bool flag){
    ui->auloginBtn->setEnabled(flag);
}
