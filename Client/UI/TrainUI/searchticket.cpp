#include "searchticket.h"
#include "ui_searchticket.h"
#include <QStandardItemModel>
//#include <QFile>
#include <QTableView>
#include <QMessageBox>
#include "../../../Server/12308_Server/include/Train.h"
#include "../../../Server/12308_Server/include/vector.hpp"

SearchTicket::SearchTicket(QWidget *parent, int user,int search) :
    QDialog(parent),
    ui(new Ui::SearchTicket),
    userType(user),
    searchType(search)
{
    ui->setupUi(this);

    ///设置列宽和标签栏
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(10);

    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("车次"));
    model->setHeaderData(2,Qt::Horizontal,tr("发站"));
    model->setHeaderData(3,Qt::Horizontal,tr("到站"));
    model->setHeaderData(4,Qt::Horizontal,tr("发站时刻"));
    model->setHeaderData(5,Qt::Horizontal,tr("到站时刻"));
    model->setHeaderData(6,Qt::Horizontal,tr("座位类型"));
    model->setHeaderData(7,Qt::Horizontal,tr("票价"));
    model->setHeaderData(8,Qt::Horizontal,tr("余票量"));
    model->setHeaderData(9,Qt::Horizontal,tr("是否可购买"));
    ui->ticketsTableView->setModel(model);


    ui->ticketsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->ticketsTableView->setColumnWidth(0,50);
    ui->ticketsTableView->setColumnWidth(1,100);
    ui->ticketsTableView->setColumnWidth(2,100);
    ui->ticketsTableView->setColumnWidth(3,100);
    ui->ticketsTableView->setColumnWidth(4,100);
    ui->ticketsTableView->setColumnWidth(5,150);
    ui->ticketsTableView->setColumnWidth(6,100);
    ui->ticketsTableView->setColumnWidth(7,100);
    ui->ticketsTableView->setColumnWidth(8,100);
    ui->ticketsTableView->setColumnWidth(9,100);
    ui->ticketsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ticketsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ticketsTableView->setWordWrap(true);
    ui->ticketsTableView->setAlternatingRowColors(true);
    ui->ticketsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ticketsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ///测试用
    model->setItem(0,0,new QStandardItem(tr("0")));
    model->setItem(0,1,new QStandardItem(tr("233")));
    model->setItem(0,2,new QStandardItem(tr("闵行")));
    model->setItem(0,3,new QStandardItem(tr("升天")));
    model->setItem(0,4,new QStandardItem(tr("24：01")));
    model->setItem(0,5,new QStandardItem(tr("24：02")));
    model->setItem(0,6,new QStandardItem(tr("双脚")));
    model->setItem(0,7, new QStandardItem(tr("666")));
    model->setItem(0,8,new QStandardItem(tr("100")));
    model->setItem(0,9,new QStandardItem(tr("是")));

    model->setItem(0,0,new QStandardItem(tr("1")));
    model->setItem(1,1,new QStandardItem(tr("33")));
    model->setItem(1,2,new QStandardItem(tr("升天")));
    model->setItem(1,3,new QStandardItem(tr("闵行")));
    model->setItem(1,4,new QStandardItem(tr("24：01")));
    model->setItem(1,5,new QStandardItem(tr("24：02")));
    model->setItem(1,6,new QStandardItem(tr("双脚")));
    model->setItem(1,7, new QStandardItem(tr("999")));
    model->setItem(1,8,new QStandardItem(tr("105")));
    model->setItem(1,9,new QStandardItem(tr("是")));

    ///将文件内的东西显示到ticketsTableView里
  /*
if (searchType == Ui::stationToStation){
    QFile tickets("searchres.txt");//change to correct name
    tickets.open(QIODevice::ReadOnly  |QIODevice::Text);
    Qtrain qtrain;
    vector<Qtrain> qtrains;
    int cnt = 0;
    while(tickets>>qtrain) {
        ++i;
        qtrains.push_back(qtrain);
    }
    int deltaforseat = 0;
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < qtrains[i].seatTypeNumber; ++j){
        model->setItem(i+deltaForSeat,0,new QStandardItem(QString::number(i,10)));
        model->setItem(i+deltaForSeat,1,new QStandardItem(qtrains[i].trainNumber));
        model->setItem(i+deltaForSeat,2,new QStandardItem(qtrains[i].loadStation));
        model->setItem(i+deltaForSeat,3,new QStandardItem(qtrains[i].unLoadStation));
        model->setItem(i+deltaForSeat,4,new QStandardItem(qtrains[i].loadStationLeaveTime.to_string()));
        model->setItem(i+deltaForSeat,5,new QStandardItem(qtrains[i].unLoadStationReachTime.to_string()));
        model->setItem(i+deltaForSeat,6,new QStandardItem(seatType[j]));
        model->setItem(i+deltaForSeat,7, new QStandardItem(QString::number(qtrains[i].price[j],10)));
        model->setItem(i+deltaForSeat,8,new QStandardItem(QString::number(qtrains[i].number,10)));
        if (qtrains[i].ableToBuy) model->setItem(i+deltaForSeat,9,new QStandardItem("是"));
        else  model->setItem(i+deltaForSeat,9,new QStandardItem("否"));
        ++deltaForSeat;
      }
      //  ++deltaForSeat;//用于不同车次间空行
    }
    }
*/




}

SearchTicket::~SearchTicket()
{
    delete ui;
}


void SearchTicket::on_buyTicketBtn_clicked()
{
/*    int curRow = ui->ticketsTableView->currentIndex().row();
    QAbstractItemModel *modessl = ui->ticketsTableView->model();
    QModelIndex indextmp = modessl->index(curRow,0);
*/
//    if (searchType == Ui::stationToStation){
//        ToServerStructs::buyTickets targetTicket;
//        int i = datatmp.toInt();
//        targetTicket.trainID = qtrains[i].trainID;
//        targetTicket.loadStation = qtrains[i].loadStation;
//        targetTicket.unLoadStation = qtrains[i].unLoadStation;
//        targetTicket.leaveTime = qtrains[i].leaveTime;
//        targetTicket.reachTime = qtrains[i].reachTime;
//        QString s= "您是否要购买以下车票：\n车次：" + QString::fromStdString(targetTicket.trainID) + "\n发站" +  QString::fromStdString(targetTicket.loadStation) +"\n到站:"
//                +  QString::fromStdString(targetTicket.unLoadStation) + "\n发车时间：" + targetTicket.leaveTime.toString() +"\n到站时间:"
//                +targetTicket.reachTime.toString() + "\n座位类型：" + modessl->data(modessl->index(curRow,5)).toString()
//                + "\n票价："+modessl->data(modessl->index(curRow,6)).toString()+"\n总张数："+ui->ticketNumLineEdit->text();
//        QMessageBox::StandardButton qmb = QMessageBox::question(this,"确认购票",s, QMessageBox::Yes|QMessageBox::No);
//        if (qmb == QMessageBox::Yes){
//            if (true){//发送targetTicket到服务器请求购买该车票
//                QMessageBox::information(this,"成功","购票成功",QMessageBox::Yes);
//            }
//            else QMessageBox::warning(this,"失败","非常抱歉，购票失败",QMessageBox::Cancel);
//        }
//    }
}
