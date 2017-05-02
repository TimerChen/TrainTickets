#include "myticket.h"
#include "ui_myticket.h"

Myticket::Myticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Myticket)
{
    ui->setupUi(this);
    ui->ticketsTextEdit->setReadOnly(true);
}

Myticket::~Myticket()
{
    delete ui;
}
