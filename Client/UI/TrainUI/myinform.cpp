#include "myinform.h"
#include "ui_myinform.h"
#include <QMessageBox>
#include "uistructs.h"
#include "toserverstructs.h"

Myinform::Myinform(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent)
    : QDialog(parent), ui(new Ui::Myinform),
      // userType(user)
      nowaccount(_now) {
    ui->setupUi(this);

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
    }

}

void Myinform::on_changepwdButton_clicked()
{
    frontask::changePwd cp(nowaccount->userID, ui->oldpwdLineEdit->text(), ui->newpwdLineEdit->text());
    if (ui->newpwdLineEdit->text() != ui->confirmNewPwdLindeEdit->text()) {
        QMessageBox::warning(this,"密码不匹配","两次输入的密码不匹配",QMessageBox::Cancel);
    }else {
        ///发送frontask::changepwd
        ///发送 cp 给服务器
    }
}
