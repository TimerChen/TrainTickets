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

            SearchTicket ticket(this, ui->dateEdit->date(), nowaccount, Ui::trainSearch, ui->trainIDLineEdit->text());
            ticket.exec();


    } else {
        QMessageBox::warning(this, tr("警告"), tr("输入不合法"),
                             QMessageBox::Yes);
    }
}
