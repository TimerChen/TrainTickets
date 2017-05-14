#include "stationtostationsearch.h"
#include <QMessageBox>
#include "searchticket.h"
#include "toserverstructs.h"
#include "ui_stationtostationsearch.h"

StationToStationSearch::StationToStationSearch(
    ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent,
    QString _adminID, QString _adminName)
    : QDialog(parent),
      ui(new Ui::StationToStationSearch),
      nowaccount(_now),
      adminID(_adminID),
      adminName(_adminName) {
    ui->setupUi(this);
    ui->dateEdit->setCalendarPopup(true);
}

StationToStationSearch::~StationToStationSearch() { delete ui; }

void StationToStationSearch::on_searchbotton_clicked() {
    if (true) {  //保证输入合法

        SearchTicket ticket(this,ui->dateEdit->date(), nowaccount,
                            Ui::stationToStation, ui->fromLineEdit->text(),
                            ui->toLineEdit->text());
        ticket.exec();

    } else {
        QMessageBox::warning(this, tr("警告"), tr("输入不合法"),
                             QMessageBox::Yes);
    }
}
