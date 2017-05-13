#include "myticket.h"
#include "ui_myticket.h"
#include <QStandardItem>
#include <QTableView>
#include "toserverstructs.h"
#include <QMessageBox>

Myticket::Myticket(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent)
    : QDialog(parent), ui(new Ui::Myticket), nowaccount(_now) {
    ui->setupUi(this);
    ui->numLineEdit->setText(tr("1"));

    ///设置列宽和标签栏
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(9);

    model->setHeaderData(0, Qt::Horizontal, tr("编号"));
    model->setHeaderData(1, Qt::Horizontal, tr("车次"));
    model->setHeaderData(2, Qt::Horizontal, tr("发站"));
    model->setHeaderData(3, Qt::Horizontal, tr("到站"));
    model->setHeaderData(4, Qt::Horizontal, tr("发车日期"));
    model->setHeaderData(5, Qt::Horizontal, tr("发站时刻"));
    model->setHeaderData(6, Qt::Horizontal, tr("到站时刻"));
    model->setHeaderData(7, Qt::Horizontal, tr("座位类型"));
    model->setHeaderData(8, Qt::Horizontal, tr("张数"));

    // model->setHeaderData(7,Qt::Horizontal,tr("票价"));
    // model->setHeaderData(8,Qt::Horizontal,tr("余票量"));
    // model->setHeaderData(9,Qt::Horizontal,tr("是否可购买"));
    ui->ticketsTableView->setModel(model);

    ui->ticketsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->ticketsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ticketsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ticketsTableView->setWordWrap(true);
    ui->ticketsTableView->setAlternatingRowColors(true);
    ui->ticketsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // ui->ticketsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ///测试用
    model->setItem(0, 0, new QStandardItem(tr("0")));
    model->setItem(0, 1, new QStandardItem(tr("233")));
    model->setItem(0, 2, new QStandardItem(tr("闵行")));
    model->setItem(0, 3, new QStandardItem(tr("升天")));
    model->setItem(0, 4, new QStandardItem(tr("周日 1月1 2017")));
    model->setItem(0, 5, new QStandardItem(tr("24：01")));
    model->setItem(0, 6, new QStandardItem(tr("24：02")));
    model->setItem(0, 7, new QStandardItem(tr("双脚")));
    model->setItem(0, 8, new QStandardItem(tr("6")));

    // model->setItem(0,7, new QStandardItem(tr("666")));
    // model->setItem(0,8,new QStandardItem(tr("100")));
    // model->setItem(0,9,new QStandardItem(tr("是")));

    model->setItem(1, 0, new QStandardItem(tr("1")));
    model->setItem(1, 1, new QStandardItem(tr("33")));
    model->setItem(1, 2, new QStandardItem(tr("升天")));
    model->setItem(1, 3, new QStandardItem(tr("闵行")));
    model->setItem(1, 4, new QStandardItem(tr("周日 1月1 2017")));
    model->setItem(1, 5, new QStandardItem(tr("24：01")));
    model->setItem(1, 6, new QStandardItem(tr("24：02")));
    model->setItem(1, 7, new QStandardItem(tr("双脚")));
    model->setItem(1, 8, new QStandardItem(tr("7")));
    // model->setItem(1,7, new QStandardItem(tr("999")));
    // model->setItem(1,8,new QStandardItem(tr("105")));
    //    model->setItem(1,9,new QStandardItem(tr("是")));
}

Myticket::~Myticket() { delete ui; }

void Myticket::on_modifyTicketBtn_clicked()
{
    int curRow = ui->ticketsTableView->currentIndex().row();
    QAbstractItemModel *modessl = ui->ticketsTableView->model();

    QDate date = modessl->data(modessl->index(curRow,4)).toDate();
    int totalNum = modessl->data(modessl->index(curRow,8)).toInt();
    int tuiNum = ui->numLineEdit->text().toInt();
    QString trainID = modessl->data(modessl->index(curRow,1)).toString();
    QString usrID = nowaccount->userID;
    QString seatType = modessl->data(modessl->index(curRow,6)).toString();
    QString load = modessl->data(modessl->index(curRow,2)).toString();
    QString unload = modessl->data(modessl->index(curRow,3)).toString();

    frontask::targetTicket targetticket(date,tuiNum,usrID,trainID,seatType,load,unload);

    QString trainInform= "车次：" +
    targetticket.trainID + "\n发站日期：" + date.toString() + "\n发站： " +
            targetticket.loadStation +"\n到站： "
                    +  targetticket.unLoadStation +
                    "\n发车时间：" + modessl->data(modessl->index(curRow,4)).toString()
                    +"\n到站时间： "
                    +modessl->data(modessl->index(curRow,5)).toString()+"\n座位类型：" +
           targetticket.seatType + "\n票价："+ modessl->data(modessl->index(curRow,7)).toString()+"\n退票张数："+ QString::number(targetticket.buyNum,10)+
            "\n原张数： "+QString::number(totalNum,10);
    if (totalNum<tuiNum){
        QMessageBox::warning(this,"退订失败","退票失败,退票张数过多",QMessageBox::Cancel);
    }else {
        QMessageBox::StandardButton qmb =
        QMessageBox::question(this,"确认退票", "您是否要退订以下车票：\n"+ trainInform,QMessageBox::Yes|QMessageBox::No);
        if (qmb == QMessageBox::Yes){
            ///发送frontask::modifyticket
            ///发送targetticket到服务器来买票
            if (true){
                QMessageBox::information(this,"成功","退票成功",QMessageBox::Yes);
                this->close();
            }
            else
            QMessageBox::warning(this,"失败","非常抱歉，退票失败",QMessageBox::Cancel);
        }
    }

}
