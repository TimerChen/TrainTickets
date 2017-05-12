#include "stationsearch.h"
#include "searchticket.h"
#include "ui_stationsearch.h"
#include <QMessageBox>

StationSearch::StationSearch(ttd::shared_ptr<uistructs::nowAccount> _now,
                             QWidget *parent)
    : QDialog(parent), ui(new Ui::StationSearch), nowaccount(_now) {
    ui->setupUi(this);
}

StationSearch::~StationSearch() { delete ui; }

void StationSearch::on_searchbotton_clicked() {
    if (true) {     //保证输入合法
        if (true) { //发送
            // ui->stationLineEdit->text()ui->dateEdit->text()给服务器以查询车票
            SearchTicket ticket(nowaccount, this);
            ticket.exec();
        } else
            QMessageBox::warning(this, tr("警告"), tr("请输入有效字符"),
                                 QMessageBox::Yes);
    } else {
        QMessageBox::warning(this, tr("警告"), tr("输入不合法"),
                             QMessageBox::Yes);
    }
}
