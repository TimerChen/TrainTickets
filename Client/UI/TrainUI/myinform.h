#ifndef MYINFORM_H
#define MYINFORM_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Myinform;
}

class Myinform : public QDialog {
    Q_OBJECT

  public:
    explicit Myinform(ttd::shared_ptr<uistructs::nowAccount> _now,
                      QWidget *parent = 0);
    ~Myinform();

  private slots:
    void on_pushButton_clicked();

  private:
    Ui::Myinform *ui;
    // int userType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif // MYINFORM_H
