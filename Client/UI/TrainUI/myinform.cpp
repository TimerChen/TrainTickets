#include "myinform.h"
#include "ui_myinform.h"
#include <QMessageBox>
#include "uistructs.h"

Myinform::Myinform(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent)
    : QDialog(parent), ui(new Ui::Myinform),
      // userType(user)
      nowaccount(_now) {
    ui->setupUi(this);
    QRegExp rx("^[0-9]+(X?)$");
    QRegExpValidator *pReg =
        new QRegExpValidator(rx, this); /// change to smart point
    ui->idnoLineEdit->setValidator(pReg);
    ui->idnoLineEdit->setMaxLength(18);
    ui->IDlabel->setText("ID:"+nowaccount->userID);
}

Myinform::~Myinform() { delete ui; }

void Myinform::on_pushButton_clicked() {
    if (true) // send ui->nameLineEdit->text(), ui->ageLineEdit->text(),
              // ui->idnoLineEdit->text() to server to change information of
              // account
        accept();
    else {
        QMessageBox::warning(this, "something wrong", "something wrong",
                             QMessageBox::Yes);
    }
}
