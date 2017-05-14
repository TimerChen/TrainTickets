#include "addseattype.h"
#include "ui_addseattype.h"

addSeatType::addSeatType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addSeatType)
{
    ui->setupUi(this);
}

addSeatType::~addSeatType()
{
    delete ui;
}
