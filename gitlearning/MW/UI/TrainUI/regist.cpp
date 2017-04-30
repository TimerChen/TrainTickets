#include "regist.h"
#include "ui_regist.h"

Regist::Regist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Regist)
{
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmpwdLineEdit->setEchoMode(QLineEdit::Password);
}

Regist::~Regist()
{
    delete ui;
}

void Regist::on_loginBtn_clicked()
{
    if (ui->confirmpwdLineEdit->text() == ui->pwdLineEdit->text() && true){//server permits
        accept();
    }
}

void Regist::on_backtologinBtn_clicked()
{
    accept();
}
