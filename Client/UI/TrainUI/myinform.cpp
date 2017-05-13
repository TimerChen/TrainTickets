#include "myinform.h"
#include "ui_myinform.h"
#include <QMessageBox>
#include "uistructs.h"
#include "toserverstructs.h"

Myinform::Myinform(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent)
    : QDialog(parent), ui(new Ui::Myinform),
      // userType(user)
      nowaccount(_now)
{
    ui->setupUi(this);
    setTabOrder(ui->nameLineEdit,ui->changenameBtn);
    setTabOrder(ui->changenameBtn,ui->oldpwdLineEdit);
    setTabOrder(ui->oldpwdLineEdit,ui->newpwdLineEdit);
    setTabOrder(ui->newpwdLineEdit,ui->confirmNewPwdLindeEdit);
    setTabOrder(ui->confirmNewPwdLindeEdit,ui->changepwdButton);
    setTabOrder(ui->changenameBtn, ui->exitBtn);


    ui->oldpwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->newpwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmNewPwdLindeEdit->setEchoMode(QLineEdit::Password);

    QRegExp rx("^[a-zA-Z0-9]+");
    QRegExpValidator *pReg =
        new QRegExpValidator(rx, this); /// change to smart point
    ui->oldpwdLineEdit->setValidator(pReg);
    ui->oldpwdLineEdit->setMaxLength(12);
    ui->newpwdLineEdit->setValidator(pReg);
    ui->newpwdLineEdit->setMaxLength(12);
    ui->confirmNewPwdLindeEdit->setValidator(pReg);
    ui->confirmNewPwdLindeEdit->setMaxLength(12);


    ui->IDlabel->setText("ID:"+nowaccount->userID);
}

Myinform::~Myinform() { delete ui; }

void Myinform::on_changenameBtn_clicked()
{
    frontask::changeUsrName cn(ui->nameLineEdit->text());
    if (ui->nameLineEdit->text() == "") {
        QMessageBox::warning(this,tr("请输入用户名"),tr("请输入有效用户名"),QMessageBox::Yes);
    }
    else {
        ///发送frontask::changeusrname
        ///发送 cn 到server来修改用户名
        if(true) {
            QMessageBox::information(this, "用户名更新成功","用户名更新成功",QMessageBox::Yes);
        }
            else QMessageBox::warning(this,"用户名更新失败","抱歉，用户名更新失败",QMessageBox::Cancel);
    }

}

void Myinform::on_changepwdButton_clicked()
{
    frontask::changePwd cp(nowaccount->userID, ui->oldpwdLineEdit->text(), ui->newpwdLineEdit->text());
    if (ui->newpwdLineEdit->text() != ui->confirmNewPwdLindeEdit->text()) {
        QMessageBox::warning(this,"密码不匹配","两次输入的密码不匹配",QMessageBox::Cancel);
    }else if (ui->newpwdLineEdit->text().length() < 6) {
        QMessageBox::warning(this, "密码长度不足", "请输入密码长度大于等于6", QMessageBox::Cancel);
    }
    else {
        ///发送frontask::changepwd
        ///发送 cp 给服务器
        if(true) {
            QMessageBox::information(this, "密码更新成功","密码更新成功",QMessageBox::Yes);
        }
        else QMessageBox::warning(this,"密码更新失败","抱歉，密码更新失败",QMessageBox::Cancel);
    }
}
