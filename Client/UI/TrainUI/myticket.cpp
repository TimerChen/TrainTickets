#include "myticket.h"
#include <QMessageBox>
#include <QStandardItem>
#include <QTableView>
#include "include/DataBase_Train.h"
#include "include/vector.hpp"
#include "toserverstructs.h"
#include "ui_myticket.h"
#include "include/DataBase_Account.h"

Myticket::Myticket(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent,
                   QString _adminID, QString _adminName)
    : QDialog(parent),
      ui(new Ui::Myticket),
      nowaccount(_now),
      adminID(_adminID),
      adminName(_adminName) {
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint);
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
    ui->numLineEdit->setText(tr("1"));

    ///设置列宽和标签栏
    model = new QStandardItemModel();
    model->setColumnCount(8);

    model->setHeaderData(0, Qt::Horizontal, tr("车次"));
    model->setHeaderData(1, Qt::Horizontal, tr("发站"));
    model->setHeaderData(2, Qt::Horizontal, tr("到站"));
    model->setHeaderData(3, Qt::Horizontal, tr("发站时刻"));
    model->setHeaderData(4, Qt::Horizontal, tr("到站时刻"));
    model->setHeaderData(5, Qt::Horizontal, tr("座位类型"));
    model->setHeaderData(6, Qt::Horizontal, tr("张数"));
    model->setHeaderData(7, Qt::Horizontal, tr("价格"));

    ui->ticketsTableView->setModel(model.getadress());

    ui->ticketsTableView->setColumnWidth(0, 200);
    ui->ticketsTableView->setColumnWidth(1, 200);
    ui->ticketsTableView->setColumnWidth(2, 200);
    ui->ticketsTableView->setColumnWidth(3, 300);
    ui->ticketsTableView->setColumnWidth(4, 300);
    ui->ticketsTableView->setColumnWidth(5, 200);
    ui->ticketsTableView->setColumnWidth(6, 150);
    ui->ticketsTableView->setColumnWidth(7, 100);

    ui->ticketsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->ticketsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ticketsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ticketsTableView->setWordWrap(true);
    ui->ticketsTableView->setAlternatingRowColors(true);
    ui->ticketsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ticketsTableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Fixed);

    ///测试用
    //    model->setItem(0, 0, new QStandardItem(tr("233")));
    //    model->setItem(0, 1, new QStandardItem(tr("闵行")));
    //    model->setItem(0, 2, new QStandardItem(tr("升天")));
    //    model->setItem(0, 3, new QStandardItem(tr("周日 1月1 2017")));
    //    model->setItem(0, 4, new QStandardItem(tr("24：01")));
    //    model->setItem(0, 5, new QStandardItem(tr("24：02")));
    //    model->setItem(0, 6, new QStandardItem(tr("双脚")));
    //    model->setItem(0, 7, new QStandardItem(tr("6")));

    //    model->setItem(1, 0, new QStandardItem(tr("33")));
    //    model->setItem(1, 1, new QStandardItem(tr("升天")));
    //    model->setItem(1, 2, new QStandardItem(tr("闵行")));
    //    model->setItem(1, 3, new QStandardItem(tr("周日 1月1 2017")));
    //    model->setItem(1, 4, new QStandardItem(tr("24：01")));
    //    model->setItem(1, 5, new QStandardItem(tr("24：02")));
    //    model->setItem(1, 6, new QStandardItem(tr("双脚")));
    //    model->setItem(1, 7, new QStandardItem(tr("7")));

    // test
    //ttd::map<DataBase_Account::Ticket,int> qtrain;
//    DataBase_Account::Ticket qtrain1;

//    qtrain.trainID = "2502B";
//    qtrain.loadStation = "交大";
//    qtrain.unLoadStation = "华师大";

//    qtrain1.trainID = "25002B";
//    qtrain1.loadStation = "华师大";
//    qtrain1.unLoadStation = "交大";

//    qtrain.price = 100;
//    qtrain1.price = 200;
//    qtrain.seatType.push_back("单腿");
//    qtrain1.seatType.push_back("三腿");

//    qtrain.loadTime =
//        QDateTime::fromString("2017-04-01 12:07:50", "yyyy-MM-dd hh:mm:ss");
//    qtrain.unLoadTime =
//        QDateTime::fromString("2017-04-01 13:07:50", "yyyy-MM-dd hh:mm:ss");
//    qtrain1.loadTime =
//        QDateTime::fromString("2017-04-12 12:07:50", "yyyy-MM-dd hh:mm:ss");
//    qtrain1.unLoadTime =
//        QDateTime::fromString("2017-04-13 13:07:50", "yyyy-MM-dd hh:mm:ss");

    ///发送frontask::getmytickets
    ///发送nowaccount->usrID
    ///获得ttd::map< , int> qtrain
	///
	ttd::map<DataBase_Account::Ticket, int> qtrains;
	bool no_error = true;
    if(nowaccount->userType == Ui::searchusr) {
        try{
            //qDebug()<<nowaccount->userID << endl;
            qtrains = ((MainWindow*)(parentWidget()->parentWidget()->parentWidget()->parentWidget()))->
                    askTickets_remote(nowaccount->userID);
        }catch(...){
            no_error = false;
        }
    }else {
        try{
            //qDebug()<<nowaccount->userID<< endl;
            qtrains = ((MainWindow*)(parentWidget()))->
                    askTickets_remote(nowaccount->userID);
        }catch(...){
            no_error = false;
        }
    }
    int deltaForSeat = 0;
    int i = 0;
    for (ttd::map<DataBase_Account::Ticket,int>::iterator it = qtrains.begin(); it != qtrains.end(); ++it) {
            double price = double(it->first.price)/100;
            model->setItem(i + deltaForSeat, 0,
                           new QStandardItem(it->first.trainID));
            model->setItem(i + deltaForSeat, 1,
                           new QStandardItem(it->first.loadStation));
            model->setItem(i + deltaForSeat, 2,
                           new QStandardItem(it->first.unLoadStation));
            model->setItem(
                i + deltaForSeat, 3,
                new QStandardItem(it->first.loadTime.toString(
					"yyyy-MM-dd hh:mm:ss")));
            model->setItem(
                i + deltaForSeat, 4,
                new QStandardItem(it->first.unLoadTime.toString(
					"yyyy-MM-dd hh:mm:ss")));

            model->setItem(i + deltaForSeat, 5,
                           new QStandardItem(it->first.seatType));
            model->setItem(
                i + deltaForSeat, 6,
                new QStandardItem(QString::number(it->second,10)));
            model->setItem(i + deltaForSeat, 7,
                           new QStandardItem(
                               QString::number(price, '.', 2)));
            ++deltaForSeat;
            ++i;
    }
}

Myticket::~Myticket() { delete ui; }

void Myticket::on_modifyTicketBtn_clicked() {
    int curRow = ui->ticketsTableView->currentIndex().row();
    //QAbstractItemModel *modessl = ui->ticketsTableView->model();

    QDate date = model->data(model->index(curRow, 3)).toDate();
    int totalNum = model->data(model->index(curRow, 6)).toInt();
    int tuiNum = ui->numLineEdit->text().toInt();
    QString trainID = model->data(model->index(curRow, 0)).toString();
    QString usrID = nowaccount->userID;
    QString seatType = model->data(model->index(curRow, 5)).toString();
    QString load = model->data(model->index(curRow, 1)).toString();
    QString unload = model->data(model->index(curRow, 2)).toString();
    //int price = model->data(model->index(curRow,7)).toInt();

    frontask::targetTicket targetticket(date, tuiNum, usrID, trainID, seatType,
                                        load, unload);

    QString trainInform =
        "车次：" + targetticket.trainID + /*"\n发站日期：" + date.toString() +*/
        "\n发站： " + targetticket.loadStation + "\n到站： " +
        targetticket.unLoadStation + "\n发车时间：" +
        model->data(model->index(curRow, 3)).toString() + "\n到站时间： " +
        model->data(model->index(curRow, 4)).toString() + "\n座位类型：" +
        targetticket.seatType + "\n票价：" +
        model->data(model->index(curRow, 7)).toString() + "\n退票张数：" +
        QString::number(targetticket.buyNum, 10) + "\n原张数： " +
        QString::number(totalNum, 10);
    if (totalNum < tuiNum) {
        QMessageBox::warning(this, "退订失败", "退票失败,退票张数过多",
                             QMessageBox::Cancel);
    } else {
        QMessageBox::StandardButton qmb = QMessageBox::question(
            this, "确认退票", "您是否要退订以下车票：\n" + trainInform,
            QMessageBox::Yes | QMessageBox::No);
        if (qmb == QMessageBox::Yes) {

			bool no_error = true;
            if (nowaccount->userType == Ui::searchusr) {
                ///发送adminmodifyusrticket
                ///发送pair(targetticket, adminID)
				try{
					((MainWindow*)(parentWidget()->parentWidget()->parentWidget()->parentWidget()))->
							returnTickets_remote(targetticket);
				}catch(...){
					no_error = false;
				}
            }else {
            ///发送frontask::modifyticket
			///发送targetticket到服务器来买票
				try{
					((MainWindow*)(parentWidget()))->
							returnTickets_remote(targetticket);
				}catch(...){
					no_error = false;
				}
            }
			if (no_error) {
                QMessageBox::information(this, "成功", "退票成功",
                                         QMessageBox::Yes);
                model->setItem(curRow,6,new QStandardItem(QString::number(totalNum - tuiNum,10)));
            } else
                QMessageBox::warning(this, "失败", "非常抱歉，退票失败",
                                     QMessageBox::Cancel);
        }
    }
}
