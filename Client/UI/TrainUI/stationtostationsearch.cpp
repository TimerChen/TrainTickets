#include "stationtostationsearch.h"
#include "ui_stationtostationsearch.h"

StationToStationSearch::StationToStationSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StationToStationSearch)
{
    ui->setupUi(this);
}

StationToStationSearch::~StationToStationSearch()
{
    delete ui;
}
