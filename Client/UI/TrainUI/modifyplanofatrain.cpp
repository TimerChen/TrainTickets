#include "modifyplanofatrain.h"
#include "ui_modifyplanofatrain.h"
#include <QMessageBox>
#include "toserverstructs.h"


modifyPlanOfATrain::modifyPlanOfATrain(
    ttd::shared_ptr<uistructs::nowAccount> _now, frontask::targetTicket _targetticket, QString _traininform, QWidget *parent)
    : QDialog(parent), ui(new Ui::modifyPlanOfATrain), nowaccount(_now), targetticket(_targetticket), trainInform(_traininform) {
    ui->setupUi(this);
    ui->accountLabel->setText("您好！"+ nowaccount->name);
    ui->trainLabel->setText("车次信息如下：\n" + trainInform);
}

modifyPlanOfATrain::~modifyPlanOfATrain() { delete ui; }

void modifyPlanOfATrain::on_deleteTrainBtn_clicked()
{
    QString trainInform = "";
    QMessageBox::StandardButton qmb =
    QMessageBox::question(this,"确认删除",trainInform,
    QMessageBox::Yes|QMessageBox::No);
    if (qmb == QMessageBox::Yes){
      if (true){
          ///发送frontask::deletetrain
          ///向服务器发送pair(targetticket.trainID, adminID)
          QMessageBox::information(this,"成功","删除车次成功",QMessageBox::Yes);
      }
      else
      QMessageBox::warning(this,"失败","非常抱歉，删除车次失败",QMessageBox::Cancel);
    }
}

void modifyPlanOfATrain::on_stopSellBtn_clicked()
{
    QString trainInform = "";
    QMessageBox::StandardButton qmb =
    QMessageBox::question(this,tr("确认停止售票"),trainInform,
    QMessageBox::Yes|QMessageBox::No);
    if (qmb == QMessageBox::Yes){
      if (true){
          ///发送frontask::stopsellticket
          ///向服务器发送pair(targetticket.trainID,aminID)
          QMessageBox::information(this,"成功","停售成功",QMessageBox::Yes);
      }
      else
      QMessageBox::warning(this,"失败","非常抱歉，停售失败",QMessageBox::Cancel);
    }
}

void modifyPlanOfATrain::on_startsellBtn_clicked()
{
    QString trainInform = "";
    QMessageBox::StandardButton qmb =
    QMessageBox::question(this,tr("确认开始售票"),trainInform,
    QMessageBox::Yes|QMessageBox::No);
    if (qmb == QMessageBox::Yes){
      if (true){
          ///发送startselltrain
          ///向服务器发送pair(targetticket,adminID)
          QMessageBox::information(this,"成功","发售成功",QMessageBox::Yes);
      }
      else
      QMessageBox::warning(this,"失败","非常抱歉，发售失败",QMessageBox::Cancel);
    }
}