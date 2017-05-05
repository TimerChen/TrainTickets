#include "stationsearch.h"
#include "ui_stationsearch.h"

StationSearch::StationSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StationSearch)
{
    ui->setupUi(this);
}

StationSearch::~StationSearch()
{
    delete ui;
}
