#include "searchticket.h"
#include "ui_searchticket.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTableView>
//#include "include/Train.h"
#include "include/vector.hpp"
#include "modifyplanofatrain.h"
#include "login.h"
#include "toserverstructs.h"

SearchTicket::SearchTicket(QDate _date, ttd::shared_ptr<uistructs::nowAccount> _now,
                           QWidget *parent,
                           int search)
    : QDialog(parent), ui(new Ui::SearchTicket), searchType(search),
      date(_date), nowaccount(_now) {
       ui->setupUi(this);

    ///设置列宽和标签栏
    ui->calLabel->setText("日期："+ date.toString());
    if (nowaccount->userType == Ui::admin) {
        ui->buyTicketBtn->setText(tr("修改计划"));
    }
    QRegExp rx("^[0-9]+$");
    QRegExpValidator *pReg =
        new QRegExpValidator(rx, this); /// change to smart point
    ui->ticketNumLineEdit->setValidator(pReg);

    model = new QStandardItemModel();
    model->setColumnCount(10);
    model->setHeaderData(0, Qt::Horizontal, tr("编号"));
    model->setHeaderData(1, Qt::Horizontal, tr("车次"));
    model->setHeaderData(2, Qt::Horizontal, tr("发站"));
    model->setHeaderData(3, Qt::Horizontal, tr("到站"));
    model->setHeaderData(4, Qt::Horizontal, tr("发站时刻"));
    model->setHeaderData(5, Qt::Horizontal, tr("到站时刻"));
    model->setHeaderData(6, Qt::Horizontal, tr("座位类型"));
    model->setHeaderData(7, Qt::Horizontal, tr("票价"));
    model->setHeaderData(8, Qt::Horizontal, tr("余票量"));
    model->setHeaderData(9, Qt::Horizontal, tr("是否可购买"));
    ui->ticketsTableView->setModel(model.getadress());

    ui->ticketsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->ticketsTableView->setColumnWidth(0, 50);
    ui->ticketsTableView->setColumnWidth(1, 100);
    ui->ticketsTableView->setColumnWidth(2, 100);
    ui->ticketsTableView->setColumnWidth(3, 100);
    ui->ticketsTableView->setColumnWidth(4, 100);
    ui->ticketsTableView->setColumnWidth(5, 150);
    ui->ticketsTableView->setColumnWidth(6, 100);
    ui->ticketsTableView->setColumnWidth(7, 100);
    ui->ticketsTableView->setColumnWidth(8, 100);
    ui->ticketsTableView->setColumnWidth(9, 100);
    ui->ticketsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ticketsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ticketsTableView->setWordWrap(true);
    ui->ticketsTableView->setAlternatingRowColors(true);
    ui->ticketsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ticketsTableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents);

    ///测试用
    model->setItem(0, 0, new QStandardItem(tr("0")));
    model->setItem(0, 1, new QStandardItem(tr("233")));
    model->setItem(0, 2, new QStandardItem(tr("闵行")));
    model->setItem(0, 3, new QStandardItem(tr("升天")));
    model->setItem(0, 4, new QStandardItem(tr("24：01")));
    model->setItem(0, 5, new QStandardItem(tr("24：02")));
    model->setItem(0, 6, new QStandardItem(tr("双脚")));
    model->setItem(0, 7, new QStandardItem(tr("666")));
    model->setItem(0, 8, new QStandardItem(tr("100")));
    model->setItem(0, 9, new QStandardItem(tr("是")));

    model->setItem(0, 0, new QStandardItem(tr("1")));
    model->setItem(1, 1, new QStandardItem(tr("33")));
    model->setItem(1, 2, new QStandardItem(tr("升天")));
    model->setItem(1, 3, new QStandardItem(tr("闵行")));
    model->setItem(1, 4, new QStandardItem(tr("24：01")));
    model->setItem(1, 5, new QStandardItem(tr("24：02")));
    model->setItem(1, 6, new QStandardItem(tr("双脚")));
    model->setItem(1, 7, new QStandardItem(tr("999")));
    model->setItem(1, 8, new QStandardItem(tr("105")));
    model->setItem(1, 9, new QStandardItem(tr("否")));

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
          model->setItem(i+deltaForSeat,0,new
  QStandardItem(QString::number(i,10)));
          model->setItem(i+deltaForSeat,1,new
  QStandardItem(qtrains[i].trainNumber));
          model->setItem(i+deltaForSeat,2,new
  QStandardItem(qtrains[i].loadStation));
          model->setItem(i+deltaForSeat,3,new
  QStandardItem(qtrains[i].unLoadStation));
          model->setItem(i+deltaForSeat,4,new
  QStandardItem(qtrains[i].loadStationLeaveTime.to_string()));
          model->setItem(i+deltaForSeat,5,new
  QStandardItem(qtrains[i].unLoadStationReachTime.to_string()));
          model->setItem(i+deltaForSeat,6,new QStandardItem(seatType[j]));
          model->setItem(i+deltaForSeat,7, new
  QStandardItem(QString::number(qtrains[i].price[j],10)));
          model->setItem(i+deltaForSeat,8,new
  QStandardItem(QString::number(qtrains[i].number,10)));
          if (qtrains[i].ableToBuy) model->setItem(i+deltaForSeat,9,new
  QStandardItem("是"));
          else  model->setItem(i+deltaForSeat,9,new QStandardItem("否"));
          ++deltaForSeat;
        }
        //  ++deltaForSeat;//用于不同车次间空行
      }
      }
  */
}

SearchTicket::~SearchTicket() { delete ui; }

void SearchTicket::on_buyTicketBtn_clicked() {
//    targetTicket.trainID = qtrains[i].trainID;
//    targetTicket.loadStation = qtrains[i].loadStation;
//    targetTicket.unLoadStation = qtrains[i].unLoadStation;
//    targetTicket.leaveTime = qtrains[i].leaveTime;
//    targetTicket.reachTime = qtrains[i].reachTime;
    int curRow = ui->ticketsTableView->currentIndex().row();
    QAbstractItemModel *modessl = ui->ticketsTableView->model();

    int buyNum = ui->ticketNumLineEdit->text().toInt();
    QString trainID = modessl->data(modessl->index(curRow,1)).toString();
    QString usrID = nowaccount->userID;
    QString seatType = modessl->data(modessl->index(curRow,6)).toString();
    QString load = modessl->data(modessl->index(curRow,2)).toString();
    QString unload = modessl->data(modessl->index(curRow,3)).toString();

    int remaintickets = modessl->data(modessl->index(curRow,8)).toInt();
    QString abletobuy = modessl->data(modessl->index(curRow,9)).toString();

    frontask::targetTicket targetticket(date,buyNum,usrID,trainID,seatType,load,unload);

    if (nowaccount->userType == Ui::annonymous) {
        Login log(nowaccount, this);
        log.setAuloginEnable(false);
        log.exec();
    }
    else if(nowaccount->userType == Ui::normal){
        if (abletobuy == tr("否")) {
            QMessageBox::warning(this, "无法购买","该票还未发售",QMessageBox::Cancel);
        }else if (buyNum > remaintickets) {
            QMessageBox::warning(this,"无法购买","余票不足",QMessageBox::Cancel);
        } else {
                QString s= "您是否要购买以下车票：\n车次：" +
                targetticket.trainID + "\n日期：" + date.toString() + "\n发站： " +
                targetticket.loadStation +"\n到站： "
                        +  targetticket.unLoadStation +
                        "\n发车时间：" + modessl->data(modessl->index(curRow,4)).toString()
                        +"\n到站时间： "
                        +modessl->data(modessl->index(curRow,5)).toString() + "\n座位类型：" +
                       targetticket.seatType
                        +
                        "\n票价："+ modessl->data(modessl->index(curRow,7)).toString()+"\n总张数："+ ui->ticketNumLineEdit->text();
                QMessageBox::StandardButton qmb =
                QMessageBox::question(this,"确认购票",s,
                QMessageBox::Yes|QMessageBox::No);
                if (qmb == QMessageBox::Yes){
                    ///发送frontask::buyticket
                    ///发送targetticket到服务器来买票
                    if (true){
                        QMessageBox::information(this,"成功","购票成功",QMessageBox::Yes);
                    }
                    else
                    QMessageBox::warning(this,"失败","非常抱歉，购票失败",QMessageBox::Cancel);
                }
        }
    }else {
        modifyPlanOfATrain m(nowaccount, this);
        //this->hide();
        m.exec();///此处要加车次信息
        ///此处发送给服务器重新查找该车次
        //this->show();
    }
}
