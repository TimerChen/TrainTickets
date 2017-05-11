#include "trainsearch.h"
#include "ui_trainsearch.h"
#include "searchticket.h"
#include <QMessageBox>

TrainSearch::TrainSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainSearch)
{
    ui->setupUi(this);
}

TrainSearch::~TrainSearch()
{
    delete ui;
}

void TrainSearch::on_searchbotton_clicked()
{
    if (true) {//保证输入合法
        if (true){ //发送 ui->trainIDLineEdit->text(),ui->dateEdit->text()给服务器以查询车票
            SearchTicket ticket(this);
            ticket.exec();
        }
        else QMessageBox::warning(this,tr("警告"),tr("请输入有效字符"),QMessageBox::Yes);
    }
    else {
       QMessageBox::warning(this,tr("警告"),tr("输入不合法"),QMessageBox::Yes);
    }
}
