#include "trainsearch.h"
#include "ui_trainsearch.h"

TrainSearch::TrainSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainSearch)
{
    ui->setupUi(this);
}

TrainSearch::~TrainSearch()
{
    delete ui;
}
