#include "trainsearch.h"
#include "searchticket.h"
#include "ui_trainsearch.h"
#include <QMessageBox>
#include "toserverstructs.h"

TrainSearch::TrainSearch(ttd::shared_ptr<uistructs::nowAccount> _now,
                         QWidget *parent) :QDialog(parent), ui(new Ui::TrainSearch), nowaccount(_now) {
    ui->setupUi(this);
    ui->dateEdit->setCalendarPopup(true);
}

TrainSearch::~TrainSearch() { delete ui; }

void TrainSearch::on_searchbotton_clicked() {
    if (true) {     //保证输入合法
        frontask::trainSearch sss(ui->dateEdit->date(), ui->trainIDLineEdit->text());
        if (true) { //发送 sss 给服务器以查询车票
            SearchTicket ticket(sss.time, nowaccount, this);
            ticket.exec();
        } else
            QMessageBox::warning(this, tr("警告"), tr("请输入有效字符"),
                                 QMessageBox::Yes);
    } else {
        QMessageBox::warning(this, tr("警告"), tr("输入不合法"),
                             QMessageBox::Yes);
    }
}
