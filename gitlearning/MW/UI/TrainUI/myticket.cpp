#include "myticket.h"
#include "ui_myticket.h"

Myticket::Myticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Myticket)
{
    ui->setupUi(this);
}

Myticket::~Myticket()
{
    delete ui;
}
