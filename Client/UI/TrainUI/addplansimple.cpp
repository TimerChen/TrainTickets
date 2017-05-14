#include "addplansimple.h"
#include "ui_addplansimple.h"

addplansimple::addplansimple(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addplansimple)
{
    ui->setupUi(this);
}

addplansimple::~addplansimple()
{
    delete ui;
}
