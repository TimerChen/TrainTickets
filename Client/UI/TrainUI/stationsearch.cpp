#include "stationsearch.h"
#include "searchticket.h"
#include "ui_stationsearch.h"
#include <QMessageBox>
#include "toserverstructs.h"
#include <QCompleter>
#include <QFile>

StationSearch::StationSearch(ttd::shared_ptr<uistructs::nowAccount> _now,
                             QWidget *parent)
    : QDialog(parent), ui(new Ui::StationSearch), nowaccount(_now) {
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
    ui->stationLineEdit->setCompleter(completer);
    stationName.close();

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
