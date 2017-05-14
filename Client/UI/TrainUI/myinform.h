#ifndef MYINFORM_H
#define MYINFORM_H

#include <QDialog>
#include <QRegExpValidator>
#include "mainwindow.h"

namespace Ui {
class Myinform;
}

class Myinform : public QDialog {
    Q_OBJECT

   public:
    explicit Myinform(ttd::shared_ptr<uistructs::nowAccount> _now,
                      QWidget *parent = 0, QString _adminID = "",
                      QString _adminName = "");
    ~Myinform();

   private slots:

    void on_changenameBtn_clicked();

    void on_changepwdButton_clicked();

   private:
    Ui::Myinform *ui;
    // int userType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
    QString adminID, adminName;
    ttd::shared_ptr<QRegExpValidator> pReg;
};

#endif  // MYINFORM_H
