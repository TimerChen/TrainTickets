#include "stationsearch.h"
#include "searchticket.h"
#include "ui_stationsearch.h"
#include <QMessageBox>
#include "toserverstructs.h"

StationSearch::StationSearch(ttd::shared_ptr<uistructs::nowAccount> _now,
                             QWidget *parent)
    : QDialog(parent), ui(new Ui::StationSearch), nowaccount(_now) {
    ui->setupUi(this);
    ui->dateEdit->setCalendarPopup(true);
}

StationSearch::~StationSearch() { delete ui; }

void StationSearch::on_searchbotton_clicked() {
    if (true) {     //保证输入合法

            SearchTicket ticket(this, ui->dateEdit->date(), nowaccount, Ui::stationSearch, ui->stationLineEdit->text());
            ticket.exec();

    } else {
        QMessageBox::warning(this, tr("警告"), tr("输入不合法"),
                             QMessageBox::Yes);
    }
}
