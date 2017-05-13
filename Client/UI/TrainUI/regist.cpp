#include <QMessageBox>
#include "regist.h"
#include "ui_regist.h"
#include "toserverstructs.h"

Regist::Regist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Regist)
{
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmpwdLineEdit->setEchoMode(QLineEdit::Password);
    QRegExp rx("^[a-zA-Z0-9]+");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this); ///change to smart point
    ui->confirmpwdLineEdit->setValidator(pReg);
    ui->confirmpwdLineEdit->setMaxLength(12);
    ui->pwdLineEdit->setValidator(pReg);
    ui->pwdLineEdit->setMaxLength(12);
    ui->usrLineEdit->setValidator(pReg);
    ui->usrLineEdit->setMaxLength(12);
}

Regist::~Regist()
{
    delete ui;
}

/*void Regist::on_backtologinBtn_clicked()
{
    accept();
}*/

void Regist::on_registBtn_clicked()
{
    if (ui->confirmpwdLineEdit->text() == ui->pwdLineEdit->text()){
        frontask::regist rac(ui->usrLineEdit->text(), ui->pwdLineEdit->text());
        if (true)///send rac to server to reg
            accept();
        else {
            QMessageBox::warning(this,"注册失败","用户名已存在或服务器拒绝本次注册",QMessageBox::Yes);
        }
    } else {
        QMessageBox::warning(this, "密码不匹配", "确认密码不相同",QMessageBox::Cancel);
    }
}
