#include "addplan.h"
#include "ui_addplan.h"

addPlan::addPlan(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPlan),
    nowaccount(_now)
{
    ui->setupUi(this);

    modelSeatType = new QStandardItemModel();
    modelSeatType->setColumnCount(3);
    modelSeatType->setHeaderData(0,Qt::Horizontal,tr("编号"));
    modelSeatType->setHeaderData(1,Qt::Horizontal,tr("座位类型"));
    modelSeatType->setHeaderData(2,Qt::Horizontal,tr("数量"));
    ui->seatTypeTableView->setModel(modelSeatType.getadress());

    ui->seatTypeTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->seatTypeTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->seatTypeTableView->setWordWrap(true);
    ui->seatTypeTableView->setAlternatingRowColors(true);
    ui->seatTypeTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->seatTypeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);


    modelStation = new QStandardItemModel();
    modelStation->setColumnCount(4);
    modelStation->setHeaderData(0, Qt::Horizontal, tr("站名"));
    modelStation->setHeaderData(1, Qt::Horizontal, tr("停站时间"));
    modelStation->setHeaderData(2,Qt::Horizontal,tr("座位类型"));
    modelStation->setHeaderData(3, Qt::Horizontal, tr("票价"));
    ui->stationsTableView->setModel(modelStation.getadress());

    ui->stationsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->stationsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->stationsTableView->setWordWrap(true);
    ui->stationsTableView->setAlternatingRowColors(true);
    ui->stationsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->stationsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);


}

addPlan::~addPlan()
{
    delete ui;
}
