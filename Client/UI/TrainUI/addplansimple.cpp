#include "addplansimple.h"
#include "ui_addplansimple.h"
#include <QMessageBox>

addplansimple::addplansimple(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addplansimple),
    nowaccount(_now)
{
    ui->setupUi(this);
}

addplansimple::~addplansimple()
{
    delete ui;
}

void addplansimple::on_addPlanBtn_clicked()
{
    QString newPlan = ui->textEdit->toPlainText();
    if (newPlan == "") {
        QMessageBox::warning(this,"内容不得为空", "对不起，编辑内容不得为空",QMessageBox::Cancel);
    }
    ///发送frontask::addplan
  ///发送pair(newPlan, nowaccount->userID
    else{
        if(true){///服务器返回是否成功
            QMessageBox::information(this, "添加计划成功","恭喜，您已成功添加一个运行计划",QMessageBox::Yes);
            this->accept();
        } else QMessageBox::warning(this,"添加失败", "对不起，发生了一个意外错误，添加计划失败",QMessageBox::Cancel);
    }
}
