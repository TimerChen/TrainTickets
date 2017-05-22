#include "regist.h"
#include <QMessageBox>
#include "toserverstructs.h"
#include "ui_regist.h"
#include "mainwindow.h"

Regist::Regist(QWidget *parent) : QDialog(parent), ui(new Ui::Regist) {
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmpwdLineEdit->setEchoMode(QLineEdit::Password);
    QRegExp rx("^[a-zA-Z0-9_]+");
    pReg = new QRegExpValidator(rx, this);  /// change to smart point
    ui->confirmpwdLineEdit->setValidator(pReg.getadress());
    ui->confirmpwdLineEdit->setMaxLength(12);
    ui->pwdLineEdit->setValidator(pReg.getadress());
    ui->pwdLineEdit->setMaxLength(12);
    ui->usrLineEdit->setValidator(pReg.getadress());
    ui->usrLineEdit->setMaxLength(12);
}

Regist::~Regist() { delete ui; }

/*void Regist::on_backtologinBtn_clicked()
{
    accept();
}*/

void Regist::on_registBtn_clicked() {
    if (ui->confirmpwdLineEdit->text() == ui->pwdLineEdit->text()) {
        frontask::regist rac(ui->usrLineEdit->text(), ui->pwdLineEdit->text());
        if (ui->usrLineEdit->text() == ""){
            QMessageBox::warning(this, "注册失败", "用户ID不得为空",
                                 QMessageBox::Cancel);
        }
        else if (ui->usrLineEdit->text().length() < 6) {
            QMessageBox::warning(this, "注册失败","抱歉,普通用户暂不支持6位以下用户ID\n如需获得6位一下靓号，请联系：\nTimeMachine@126.com\n当前会员价格为300元/2年\n我们在短期内将提价为400元/年\n欲购从速！！！",QMessageBox::Cancel);
        }
        else if (ui->pwdLineEdit->text().length() < 6) {
            QMessageBox::warning(this, "注册失败", "密码长度应不小于6位",
                                 QMessageBox::Cancel);
		} else if (true){
            /// 发送reg
            /// 发送rac
			int serverReturn
				= ((MainWindow*)parentWidget())->register_remote
					(ui->usrLineEdit->text(), ui->pwdLineEdit->text());

            if(serverReturn == 2){
                QMessageBox::information(this, "注册成功", "恭喜，注册成功！",
                                     QMessageBox::Yes);
                accept();
            }
			else if(serverReturn == 1)
				QMessageBox::warning(this, "注册失败", "存在的用户名",
									 QMessageBox::Cancel);
			else
				QMessageBox::warning(this, "注册失败", "非法操作",
									 QMessageBox::Cancel);

		}else if (false){
            QMessageBox::warning(this, "注册失败",
                                 "用户ID已存在或服务器拒绝本次注册",
                                 QMessageBox::Cancel);
        }
    } else {
        QMessageBox::warning(this, "密码不匹配", "确认密码不相同",
                             QMessageBox::Cancel);
    }
}
