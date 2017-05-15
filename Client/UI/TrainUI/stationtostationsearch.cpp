#include "stationtostationsearch.h"
#include <QMessageBox>
#include "searchticket.h"
#include "toserverstructs.h"
#include "ui_stationtostationsearch.h"
#include <QFile>
#include <QCompleter>

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

    QFile stationName(":/src/stationfile");
    stationName.open(QIODevice::ReadOnly);
    QTextStream in(&stationName);
    QStringList word_list;
    QString tmps;
    while (!in.atEnd()) {
        in >> tmps;
        word_list<< tmps;
        //qDebug() << tmps << endl;
    }
    //word_list<<"Java"<<"C++"<<"C#"<<"PHP"<<"Perl"<<"Python"<<"Delphi"<<"Ruby";
    QCompleter *completer = new QCompleter(word_list, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->fromLineEdit->setCompleter(completer);
    ui->toLineEdit->setCompleter(completer);
    stationName.close();
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
