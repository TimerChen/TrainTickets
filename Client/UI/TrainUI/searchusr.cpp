#include "searchusr.h"
#include "ui_searchusr.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "editsearchusr.h"

searchUsr::searchUsr(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchUsr),
    nowaccount(_now)
{
    ui->setupUi(this);
}

searchUsr::~searchUsr()
{
    delete ui;
}

void searchUsr::on_searchBtn_clicked()
{
    QString usrID = ui->searchUsrIDLineEdit->text();
    /// 发送usrID给服务器
    /// 获得一个用户信息的结构体
    if (true){
        ttd::shared_ptr<uistructs::nowAccount> searchAccount = new uistructs::nowAccount;
        ///searchAccount->name = ;
        searchAccount->userID = usrID;
        searchAccount->userType = Ui::searchusr;
        //test
        searchAccount->name = "mw";

        editSearchUsr ed(searchAccount, this, nowaccount->userID, nowaccount->userID);
        ed.exec();
    }
    else QMessageBox::warning(this, "用户ID不存在", "对不起，您搜索的用户ID不存在", QMessageBox::Cancel);
}
