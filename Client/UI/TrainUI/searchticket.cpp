#include "searchticket.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTableView>
#include "include/DataBase_Train.h"
#include "include/vector.hpp"
#include "login.h"
#include "modifyplanofatrain.h"
#include "toserverstructs.h"
#include "ui_searchticket.h"

SearchTicket::SearchTicket(QWidget *parent, QDate _date,
                           ttd::shared_ptr<uistructs::nowAccount> _now,
                           int search, QString _ask1, QString _ask2,
                           QString _adminID, QString _adminName)
    : QDialog(parent),
      ui(new Ui::SearchTicket),
      searchType(search),
      date(_date),
      nowaccount(_now),
      ask1(_ask1),
      ask2(_ask2),
      adminID(_adminID),
      adminName(_adminName) {
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint);
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);

    ///设置列宽和标签栏
    ui->calLabel->setText("日期：" + date.toString());
    if (searchType != Ui::stationToStation) ui->buyTicketBtn->setEnabled(false);
    if (nowaccount->userType == Ui::admin) {
        ui->buyTicketBtn->setEnabled(true);
        ui->buyTicketBtn->setText(tr("修改计划"));
    }else if (nowaccount->userType == Ui::searchusr) {
        ui->buyTicketBtn->setText("为用户添加该车票");
    }
    QRegExp rx("^[0-9]+$");
    pReg = new QRegExpValidator(rx, this);  /// change to smart point
    ui->ticketNumLineEdit->setValidator(pReg.getadress());

    model = new QStandardItemModel();
    model->setColumnCount(9);

    model->setHeaderData(0, Qt::Horizontal, tr("车次"));
    model->setHeaderData(1, Qt::Horizontal, tr("发站"));
    model->setHeaderData(2, Qt::Horizontal, tr("到站"));
    model->setHeaderData(3, Qt::Horizontal, tr("发站时刻"));
    model->setHeaderData(4, Qt::Horizontal, tr("到站时刻"));
    model->setHeaderData(5, Qt::Horizontal, tr("座位类型"));
    model->setHeaderData(6, Qt::Horizontal, tr("票价"));
    model->setHeaderData(7, Qt::Horizontal, tr("余票量"));
    model->setHeaderData(8, Qt::Horizontal, tr("是否可购买"));
    ui->ticketsTableView->setModel(model.getadress());

    ui->ticketsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->ticketsTableView->setColumnWidth(0, 200);
    ui->ticketsTableView->setColumnWidth(1, 200);
    ui->ticketsTableView->setColumnWidth(2, 200);
    ui->ticketsTableView->setColumnWidth(3, 200);
    ui->ticketsTableView->setColumnWidth(4, 200);
    ui->ticketsTableView->setColumnWidth(5, 150);
    ui->ticketsTableView->setColumnWidth(6, 100);
    ui->ticketsTableView->setColumnWidth(7, 100);
    ui->ticketsTableView->setColumnWidth(8, 150);
    // ui->ticketsTableView->setColumnWidth(9, 100);
    ui->ticketsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ticketsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ticketsTableView->setWordWrap(true);
    ui->ticketsTableView->setAlternatingRowColors(true);
    ui->ticketsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ticketsTableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Fixed);
    model->setItem(0, 0, new QStandardItem(tr("无")));

    ///将文件内的东西显示到ticketsTableView里

    // test
    DataBase_Train::QTrain qtrain;
    qtrain.ableToBuy = true;
    qtrain.trainID = "2502B";
    qtrain.seatTypeNumber = 3;
    qtrain.loadStation = "交大";
    qtrain.unLoadStation = "华师大";
    qtrain.price.push_back(100);
    qtrain.price.push_back(200);
    qtrain.price.push_back(250);
    qtrain.seatType.push_back("单腿");
    qtrain.seatType.push_back("双腿");
    qtrain.seatType.push_back("三腿");
    qtrain.seatNumber.push_back(50);
    qtrain.seatNumber.push_back(10);
    qtrain.seatNumber.push_back(1);
    qtrain.loadStationLeaveTime =
        QDateTime::fromString("2017-04-01 12:07:50", "yyyy-MM-dd hh:mm:ss");
    qtrain.unLoadStationReachTime =
        QDateTime::fromString("2017-04-01 13:07:50", "yyyy-MM-dd hh:mm:ss");
    // test
    DataBase_Train::TrainRoute ttrainrout;
    ttrainrout.trainID = "360SB";
    ttrainrout.seatTypeNumber = 3;
    ttrainrout.stationNumber = 3;
    ttrainrout.stationName.push_back("f");
    ttrainrout.stationName.push_back("u");
    ttrainrout.stationName.push_back("c");
    ttrainrout.mileAge.push_back(1);
    ttrainrout.mileAge.push_back(2);
    ttrainrout.mileAge.push_back(3);
    ttrainrout.reachTime.push_back(
        QDateTime::fromString("01 12:07:50", "dd hh:mm:ss"));
    ttrainrout.reachTime.push_back(
        QDateTime::fromString("01 13:07:50", "dd hh:mm:ss"));
    ttrainrout.reachTime.push_back(
        QDateTime::fromString("02 14:07:50", "dd hh:mm:ss"));
    ttrainrout.leaveTime.push_back(
        QDateTime::fromString("01 12:27:50", "dd hh:mm:ss"));
    ttrainrout.leaveTime.push_back(
        QDateTime::fromString("01 13:37:50", "dd hh:mm:ss"));
    ttrainrout.leaveTime.push_back(
        QDateTime::fromString("02 14:47:50", "dd hh:mm:ss"));
    ttrainrout.seatType.push_back("k");
    ttrainrout.seatType.push_back("y");
    ttrainrout.seatType.push_back("o");
    ttd::vector<int> v1(3), v2(3), v3(3);
    v1[0] = 22, v1[1] = 33, v1[2] = 44;
    v2[0] = 122, v2[1] = 133, v2[2] = 144;
    v3[0] = 222, v3[1] = 233, v3[2] = 244;
    ttrainrout.priceTable.push_back(v1);
    ttrainrout.priceTable.push_back(v2);
    ttrainrout.priceTable.push_back(v3);

    ttd::vector<DataBase_Train::QTrain> qtrains;
    // test
    qtrains.push_back(qtrain);
    qtrains.push_back(qtrain);

    DataBase_Train::TrainRoute trainroute;
    // test
    trainroute = ttrainrout;

    ttd::vector<DataBase_Train::TrainRoute> vtrainroute;
    // test
    vtrainroute.push_back(ttrainrout);
    vtrainroute.push_back(ttrainrout);

    if (searchType == Ui::stationToStation) {

        frontask::stationToStationSearch sss(date, ask1, ask2);
		bool no_error = true;
		try{
			qtrains =
			((MainWindow*)(parentWidget()->parentWidget()))->query_sts_remote
								(sss);
		}catch(...){
			no_error = false;
		}

		if (no_error) {  ///发送sss到服务器
            ///获得qtrains



            int deltaForSeat = 0;
            for (size_t i = 0; i < qtrains.size(); ++i) {
                for (int j = 0; j < qtrains[i].seatTypeNumber; ++j) {
                    model->setItem(i + deltaForSeat, 0,
                                   new QStandardItem(qtrains[i].trainID));
                    model->setItem(i + deltaForSeat, 1,
                                   new QStandardItem(qtrains[i].loadStation));
                    model->setItem(i + deltaForSeat, 2,
                                   new QStandardItem(qtrains[i].unLoadStation));
                    model->setItem(i + deltaForSeat, 3,
                                   new QStandardItem(
                                       qtrains[i].loadStationLeaveTime.toString(
                                           "hh:mm:ss")));
                    model->setItem(
                        i + deltaForSeat, 4,
                        new QStandardItem(
                            qtrains[i].unLoadStationReachTime.toString(
                                "hh:mm:ss")));

                    model->setItem(i + deltaForSeat, 5,
                                   new QStandardItem(qtrains[i].seatType[j]));
                    model->setItem(i + deltaForSeat, 6,
                                   new QStandardItem(QString::number(
                                       qtrains[i].price[j], 10)));
                    model->setItem(i + deltaForSeat, 7,
                                   new QStandardItem(QString::number(
                                       qtrains[i].seatNumber[j], 10)));
                    if (qtrains[i].ableToBuy)
                        model->setItem(i + deltaForSeat, 8,
                                       new QStandardItem("是"));
                    else
                        model->setItem(i + deltaForSeat, 8,
                                       new QStandardItem("否"));
                    ++deltaForSeat;
                }
            }
        } else {
            QMessageBox::warning(this, tr("警告"), tr("请输入有效字符"),
                                 QMessageBox::Yes);
            this->close();
        }
    } else if (searchType == Ui::trainSearch) {
        frontask::trainSearch sss(date, ask1);

		bool no_error = true;
		try{
			trainroute =
			((MainWindow*)(parentWidget()->parentWidget()))->query_t_remote
								(sss);
		}catch(...){
			no_error = false;
		}

		if (no_error) {
            ///发送frontask::trainsearch
            ///发送sss到服务器
            ///获得trainroute
            ui->calLabel->setText("始发日期： " + date.toString());
            model->setHeaderData(6, Qt::Horizontal, tr("发出第 天"));
            model->setHeaderData(7, Qt::Horizontal, tr("里程"));
            model->setHeaderData(8, Qt::Horizontal, tr(""));
            int deltaForSeat = 0;
            for (int i = 0; i < trainroute.stationNumber; ++i) {
                model->setItem(i + deltaForSeat, 0,
                               new QStandardItem(trainroute.trainID));
                if (i == 0)
                    model->setItem(
                        i + deltaForSeat, 1,
                        new QStandardItem(trainroute.stationName[i]));
                else
                    model->setItem(
                        i + deltaForSeat, 2,
                        new QStandardItem(trainroute.stationName[i]));
                model->setItem(
                    i + deltaForSeat, 3,
                    new QStandardItem(
                        trainroute.leaveTime[i].toString("hh:mm:ss")));
                model->setItem(
                    i + deltaForSeat, 4,
                    new QStandardItem(
                        trainroute.reachTime[i].toString("hh:mm:ss")));
                model->setItem(
                    i + deltaForSeat, 6,
                    new QStandardItem(trainroute.reachTime[i].toString("dd")));
                model->setItem(i + deltaForSeat, 7,
                               new QStandardItem(
                                   QString::number(trainroute.mileAge[i], 10)));
                if (i == 0) {
                    for (int j = 0; j < trainroute.seatTypeNumber; ++j) {
                        model->setItem(i + deltaForSeat, 0,
                                       new QStandardItem(trainroute.trainID));
                        model->setItem(
                            i + deltaForSeat, 5,
                            new QStandardItem(trainroute.seatType[j]));
                        ++deltaForSeat;
                    }
                    --deltaForSeat;
                }
            }

        } else {
            QMessageBox::warning(this, tr("警告"), tr("请输入有效字符"),
                                 QMessageBox::Yes);
        }
    } else {
        frontask::stationSearch sss(date, ask1);

		bool no_error = true;
		try{
			vtrainroute =
			((MainWindow*)(parentWidget()->parentWidget()))->query_s_remote
								(sss);
		}catch(...){
			no_error = false;
		}

		if (no_error) {
            ///发送frontask::stationsearch
            ///发送sss到服务器
            ///获得vtrainroute
            ui->calLabel->setText("始发日期： " + date.toString());
            model->setHeaderData(6, Qt::Horizontal, tr("发出第 天"));
            model->setHeaderData(7, Qt::Horizontal, tr("里程"));
            model->setHeaderData(1, Qt::Horizontal, tr("始发站"));
            model->setHeaderData(8, Qt::Horizontal, tr(""));
            int deltaForSeat = 0;
            for (size_t t = 0; t < vtrainroute.size(); ++t) {
                model->setItem(t + deltaForSeat, 0,
                               new QStandardItem(vtrainroute[t].trainID));
                for (int i = 0; i < vtrainroute[t].stationNumber; ++i) {
                    if (i == 0)
                        model->setItem(
                            t + deltaForSeat, 1,
                            new QStandardItem(vtrainroute[t].stationName[i]));
                    else
                        model->setItem(
                            t + deltaForSeat, 2,
                            new QStandardItem(vtrainroute[t].stationName[i]));
                    model->setItem(
                        t + deltaForSeat, 4,
                        new QStandardItem(
                            vtrainroute[t].leaveTime[i].toString("hh:mm:ss")));
                    model->setItem(
                        t + deltaForSeat, 3,
                        new QStandardItem(
                            vtrainroute[t].reachTime[i].toString("hh:mm:ss")));
                    model->setItem(
                        t + deltaForSeat, 6,
                        new QStandardItem(
                            vtrainroute[t].reachTime[i].toString("dd")));
                    model->setItem(t + deltaForSeat, 7,
                                   new QStandardItem(QString::number(
                                       vtrainroute[t].mileAge[i], 10)));
                    if (i == 0) {
                        for (int j = 0; j < vtrainroute[t].seatTypeNumber;
                             ++j) {
                            model->setItem(
                                t + deltaForSeat, 5,
                                new QStandardItem(vtrainroute[t].seatType[j]));
                            ++deltaForSeat;
                        }
                    } else
                        ++deltaForSeat;
                }
            }

        } else {
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
    QString trainID = modessl->data(modessl->index(curRow, 0)).toString();
    QString usrID = nowaccount->userID;
    QString seatType = modessl->data(modessl->index(curRow, 5)).toString();
    QString load = modessl->data(modessl->index(curRow, 1)).toString();
    QString unload = modessl->data(modessl->index(curRow, 2)).toString();

    int remaintickets = modessl->data(modessl->index(curRow, 7)).toInt();
    QString abletobuy = modessl->data(modessl->index(curRow, 8)).toString();

    frontask::targetTicket targetticket(date, buyNum, usrID, trainID, seatType,
                                        load, unload);

    QString trainInform =
        "车次：" + targetticket.trainID + "\n发站日期：" + date.toString();
    if (nowaccount->userType == Ui::annonymous) {
        Login log(nowaccount, this);
        log.setAuloginEnable(false);
        log.exec();
    } else if (nowaccount->userType == Ui::normal || nowaccount->userType == Ui::searchusr) {
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
                           modessl->data(modessl->index(curRow, 3)).toString() +
                           "\n到站时间： " +
                           modessl->data(modessl->index(curRow, 4)).toString() +
                           "\n座位类型：" + targetticket.seatType + "\n票价：" +
                           modessl->data(modessl->index(curRow, 6)).toString() +
                           "\n总张数：" + ui->ticketNumLineEdit->text();
            QMessageBox::StandardButton qmb = QMessageBox::question(
                this, "确认购票", "您是否要购买以下车票：\n" + trainInform,
                QMessageBox::Yes | QMessageBox::No);
            if (qmb == QMessageBox::Yes) {
                if (nowaccount->userType == Ui::searchusr) {
                    ///发送frontask::adminaddusrticket
                    /// 发送pair(targetticket, adminID)
                }else {
                ///发送frontask::buyticket
                ///发送targetticket到服务器来买票
                }
                if (true) {
                    QMessageBox::information(this, "成功", "购票成功",
                                             QMessageBox::Yes);
                } else
                    QMessageBox::warning(this, "失败", "非常抱歉，购票失败",
                                         QMessageBox::Cancel);
            }
        }
    } else  {
        modifyPlanOfATrain m(nowaccount, targetticket, trainInform, this);
        // this->hide();
        m.exec();
        this->close();
    }
}
