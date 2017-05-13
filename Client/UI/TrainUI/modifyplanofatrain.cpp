#include "modifyplanofatrain.h"
#include "ui_modifyplanofatrain.h"
#include <QMessageBox>


modifyPlanOfATrain::modifyPlanOfATrain(
    ttd::shared_ptr<uistructs::nowAccount> _now,/*add train inform*/ QWidget *parent)
    : QDialog(parent), ui(new Ui::modifyPlanOfATrain), nowaccount(_now) {
    ui->setupUi(this);
    QString trainInform = "";
    ui->accountLabel->setText("您好！"+ nowaccount->name);
    ui->trainLabel->setText("车次信息如下：\n"+trainInform);
}

modifyPlanOfATrain::~modifyPlanOfATrain() { delete ui; }

void modifyPlanOfATrain::on_deleteTrainBtn_clicked()
{
    QString trainInform = "";
    QMessageBox::StandardButton qmb =
    QMessageBox::question(this,"确认删除",trainInform,
    QMessageBox::Yes|QMessageBox::No);
    if (qmb == QMessageBox::Yes){
      if (true){///向服务器发送删除车次
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
      if (true){///向服务器发送删除车次
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
      if (true){///向服务器发送发售车次
          QMessageBox::information(this,"成功","发售成功",QMessageBox::Yes);
      }
      else
      QMessageBox::warning(this,"失败","非常抱歉，发售失败",QMessageBox::Cancel);
    }
}
