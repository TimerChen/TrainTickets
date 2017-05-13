#include "searchticket.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTableView>
#include "include/train.h"
#include "include/vector.hpp"
#include "login.h"
#include "modifyplanofatrain.h"
#include "toserverstructs.h"
#include "ui_searchticket.h"

SearchTicket::SearchTicket(QDate _date,
                           ttd::shared_ptr<uistructs::nowAccount> _now,
                           int search, QString _ask1, QWidget *parent,
                           QString _ask2)
    : QDialog(parent),
      ui(new Ui::SearchTicket),
      searchType(search),
      ask1(_ask1),
      ask2(_ask2),
      date(_date),
      nowaccount(_now) {
    ui->setupUi(this);

    ///设置列宽和标签栏
    ui->calLabel->setText("日期：" + date.toString());
    if (searchType != Ui::stationToStation) ui->buyTicketBtn->setEnabled(false);
    if (nowaccount->userType == Ui::admin) {
        ui->buyTicketBtn->setEnabled(true);
        ui->buyTicketBtn->setText(tr("修改计划"));
    }
    QRegExp rx("^[0-9]+$");
    QRegExpValidator *pReg =
        new QRegExpValidator(rx, this);  /// change to smart point
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
    //    ui->ticketsTableView->setColumnWidth(0, 50);
    //    ui->ticketsTableView->setColumnWidth(1, 100);
    //    ui->ticketsTableView->setColumnWidth(2, 100);
    //    ui->ticketsTableView->setColumnWidth(3, 100);
    //    ui->ticketsTableView->setColumnWidth(4, 100);
    //    ui->ticketsTableView->setColumnWidth(5, 150);
    //    ui->ticketsTableView->setColumnWidth(6, 100);
    //    ui->ticketsTableView->setColumnWidth(7, 100);
    //    ui->ticketsTableView->setColumnWidth(8, 100);
    //    ui->ticketsTableView->setColumnWidth(9, 100);
    ui->ticketsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ticketsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ticketsTableView->setWordWrap(true);
    ui->ticketsTableView->setAlternatingRowColors(true);
    ui->ticketsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ticketsTableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents);
    model->setItem(0, 0, new QStandardItem(tr("0")));
    model->setItem(0, 1, new QStandardItem(tr("无")));

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

    // test
    QTrain qtrain;
    qtrain.ableToBuy = true;
    qtrain.trainID = "2502B";
    qtrain.seatNumber = 3;
    qtrain.loadStation = "交大";
    qtrain.unLoadStation="华师大";
    qtrain.price.push_back(100);
    qtrain.price.push_back(200);
    qtrain.price.push_back(250);
    qtrain.seatNumber.push_back(50);
    qtrain.seatNumber.push_back(10);
    qtrain.seatNumber.push_back(1);
    qtrain.loadStationLeaveTime = QDateTime::fromString("2017-04-01 12:07:50:541", "yyyy-MM-dd hh:mm:ss:zzz");
    qtrain.unLoadStationReachTime = QDateTime::fromString("2017-04-01 13:07:50:541", "yyyy-MM-dd hh:mm:ss:zzz");



    ttd::vector<QTrain> qtrains;
    //test
    qtrains.push_back(qtrain);
    qtrains.push_back(qtrain);


    ttd::vector<TrainRoute> trainroute;
    if (searchType == Ui::stationToStation) {
        frontask::stationToStationSearch sss(date, ask1, ask2);
        if (true) {  ///发送sss到服务器
            ///获得qtrains
            int deltaForSeat = 0;
            for (size_t i = 0; i < qtrains.size(); ++i) {
                for (int j = 0; j < qtrains[i].seatTypeNumber; ++j) {
                    model->setItem(i + deltaForSeat, 0,
                                   new QStandardItem(QString::number(i, 10)));
                    model->setItem(i + deltaForSeat, 1,
                                   new QStandardItem(qtrains[i].trainID));
                    model->setItem(i + deltaForSeat, 2,
                                   new QStandardItem(qtrains[i].loadStation));
                    model->setItem(i + deltaForSeat, 3,
                                   new QStandardItem(qtrains[i].unLoadStation));
                    model->setItem(
                        i + deltaForSeat, 4,
                        new QStandardItem(
                            qtrains[i].loadStationLeaveTime.toString()));
                    model->setItem(
                        i + deltaForSeat, 5,
                        new QStandardItem(
                            qtrains[i].unLoadStationReachTime.toString()));
                    model->setItem(i + deltaForSeat, 6,
                                   new QStandardItem(qtrains[i].seatType[j]));
                    model->setItem(i + deltaForSeat, 7,
                                   new QStandardItem(QString::number(
                                       qtrains[i].price[j], 10)));
                    model->setItem(i + deltaForSeat, 8,
                                   new QStandardItem(QString::number(
                                       qtrains[i].seatNumber[j], 10)));
                    if (qtrains[i].ableToBuy)
                        model->setItem(i + deltaForSeat, 9,
                                       new QStandardItem("是"));
                    else
                        model->setItem(i + deltaForSeat, 9,
                                       new QStandardItem("否"));
                    ++deltaForSeat;
                }
            }
        } else {
            QMessageBox::warning(this, tr("警告"), tr("请输入有效字符"),
                                 QMessageBox::Yes);
            this->close();
        }
    } else if (searchType == Ui::stationSearch) {
        frontask::stationSearch sss(date,ask1);
        if (true){///发送sss到服务器
            ///获得trainroute

        }else {
            QMessageBox::warning(this, tr("警告"), tr("请输入有效字符"),
                             QMessageBox::Yes);
        }
    } else {
        frontask::trainSearch sss(date,ask1);
        if (true){///发送sss到服务器
            ///获得trainroute

        }else{
            QMessageBox::warning(this, tr("警告"), tr("请输入有效字符"),
                             QMessageBox::Yes);
        }
    }

}

SearchTicket::~SearchTicket() { delete ui; }

void SearchTicket::on_buyTicketBtn_clicked() {
    int curRow = ui->ticketsTableView->currentIndex().row();
    QAbstractItemModel *modessl = ui->ticketsTableView->model();

    int buyNum = ui->ticketNumLineEdit->text().toInt();
    QString trainID = modessl->data(modessl->index(curRow, 1)).toString();
    QString usrID = nowaccount->userID;
    QString seatType = modessl->data(modessl->index(curRow, 6)).toString();
    QString load = modessl->data(modessl->index(curRow, 2)).toString();
    QString unload = modessl->data(modessl->index(curRow, 3)).toString();

    int remaintickets = modessl->data(modessl->index(curRow, 8)).toInt();
    QString abletobuy = modessl->data(modessl->index(curRow, 9)).toString();

    frontask::targetTicket targetticket(date, buyNum, usrID, trainID, seatType,
                                        load, unload);

    QString trainInform =
        "车次：" + targetticket.trainID + "\n发站日期：" + date.toString();
    if (nowaccount->userType == Ui::annonymous) {
        Login log(nowaccount, this);
        log.setAuloginEnable(false);
        log.exec();
    } else if (nowaccount->userType == Ui::normal) {
        if (abletobuy == tr("否")) {
            QMessageBox::warning(this, "无法购买", "该票还未发售",
                                 QMessageBox::Cancel);
        } else if (buyNum > remaintickets) {
            QMessageBox::warning(this, "无法购买", "余票不足",
                                 QMessageBox::Cancel);
        } else {
            trainInform += "\n发站： " + targetticket.loadStation +
                           "\n到站： " + targetticket.unLoadStation +
                           "\n发车时间：" +
                           modessl->data(modessl->index(curRow, 4)).toString() +
                           "\n到站时间： " +
                           modessl->data(modessl->index(curRow, 5)).toString() +
                           "\n座位类型：" + targetticket.seatType + "\n票价：" +
                           modessl->data(modessl->index(curRow, 7)).toString() +
                           "\n总张数：" + ui->ticketNumLineEdit->text();
            QMessageBox::StandardButton qmb = QMessageBox::question(
                this, "确认购票", "您是否要购买以下车票：\n" + trainInform,
                QMessageBox::Yes | QMessageBox::No);
            if (qmb == QMessageBox::Yes) {
                ///发送frontask::buyticket
                ///发送targetticket到服务器来买票
                if (true) {
                    QMessageBox::information(this, "成功", "购票成功",
                                             QMessageBox::Yes);
                } else
                    QMessageBox::warning(this, "失败", "非常抱歉，购票失败",
                                         QMessageBox::Cancel);
            }
        }
    } else {
        modifyPlanOfATrain m(nowaccount, targetticket, trainInform, this);
        // this->hide();
        m.exec();
        this->close();
    }
}
