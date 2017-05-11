#include "myticket.h"
#include "ui_myticket.h"
#include <QTableView>
#include <QStandardItem>

Myticket::Myticket(QWidget *parent, int user) :
    QDialog(parent),
    ui(new Ui::Myticket),
    userType(user)
{
    ui->setupUi(this);
    ///设置列宽和标签栏
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(7);

    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("车次"));
    model->setHeaderData(2,Qt::Horizontal,tr("发站"));
    model->setHeaderData(3,Qt::Horizontal,tr("到站"));
    model->setHeaderData(4,Qt::Horizontal,tr("发站时刻"));
    model->setHeaderData(5,Qt::Horizontal,tr("到站时刻"));
    model->setHeaderData(6,Qt::Horizontal,tr("座位类型"));
    //model->setHeaderData(7,Qt::Horizontal,tr("票价"));
    //model->setHeaderData(8,Qt::Horizontal,tr("余票量"));
    //model->setHeaderData(9,Qt::Horizontal,tr("是否可购买"));
    ui->ticketsTableView->setModel(model);


    ui->ticketsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->ticketsTableView->setColumnWidth(0,50);
    ui->ticketsTableView->setColumnWidth(1,100);
    ui->ticketsTableView->setColumnWidth(2,100);
    ui->ticketsTableView->setColumnWidth(3,100);
    ui->ticketsTableView->setColumnWidth(4,100);
    ui->ticketsTableView->setColumnWidth(5,150);
    ui->ticketsTableView->setColumnWidth(6,100);
   // ui->ticketsTableView->setColumnWidth(7,100);
    //ui->ticketsTableView->setColumnWidth(8,100);
    //ui->ticketsTableView->setColumnWidth(9,100);
    ui->ticketsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ticketsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ticketsTableView->setWordWrap(true);
    ui->ticketsTableView->setAlternatingRowColors(true);
    ui->ticketsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
   // ui->ticketsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ///测试用
    model->setItem(0,0,new QStandardItem(tr("0")));
    model->setItem(0,1,new QStandardItem(tr("233")));
    model->setItem(0,2,new QStandardItem(tr("闵行")));
    model->setItem(0,3,new QStandardItem(tr("升天")));
    model->setItem(0,4,new QStandardItem(tr("24：01")));
    model->setItem(0,5,new QStandardItem(tr("24：02")));
    model->setItem(0,6,new QStandardItem(tr("双脚")));
   // model->setItem(0,7, new QStandardItem(tr("666")));
   // model->setItem(0,8,new QStandardItem(tr("100")));
   // model->setItem(0,9,new QStandardItem(tr("是")));

    model->setItem(0,0,new QStandardItem(tr("1")));
    model->setItem(1,1,new QStandardItem(tr("33")));
    model->setItem(1,2,new QStandardItem(tr("升天")));
    model->setItem(1,3,new QStandardItem(tr("闵行")));
    model->setItem(1,4,new QStandardItem(tr("24：01")));
    model->setItem(1,5,new QStandardItem(tr("24：02")));
    model->setItem(1,6,new QStandardItem(tr("双脚")));
   // model->setItem(1,7, new QStandardItem(tr("999")));
    //model->setItem(1,8,new QStandardItem(tr("105")));
//    model->setItem(1,9,new QStandardItem(tr("是")));
}

Myticket::~Myticket()
{
    delete ui;
}
