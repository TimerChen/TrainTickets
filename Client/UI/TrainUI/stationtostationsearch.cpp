#include "stationtostationsearch.h"
#include "searchticket.h"
#include "ui_stationtostationsearch.h"
#include <QMessageBox>
#include "toserverstructs.h"

StationToStationSearch::StationToStationSearch(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent)
    : QDialog(parent), ui(new Ui::StationToStationSearch), nowaccount(_now) {
    ui->setupUi(this);
    ui->dateEdit->setCalendarPopup(true);
}

StationToStationSearch::~StationToStationSearch() { delete ui; }

void StationToStationSearch::on_searchbotton_clicked() {
    if (true) {     //保证输入合法

            SearchTicket ticket(ui->dateEdit->date(), nowaccount, Ui::stationToStation, ui->fromLineEdit->text(), this, ui->toLineEdit->text());
            ticket.exec();


    } else {
        QMessageBox::warning(this, tr("警告"), tr("输入不合法"),
                             QMessageBox::Yes);
    }
}
