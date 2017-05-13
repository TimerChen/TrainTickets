#ifndef LOGIN_H
#define LOGIN_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog {
    Q_OBJECT

  public:
    explicit Login(ttd::shared_ptr<uistructs::nowAccount> _now, QWidget *parent = 0);
    void setAuloginEnable(bool flag);

    ~Login();

  private slots:

    void on_loginBtn_clicked();

    void on_auloginBtn_clicked();

    void on_registBtn_clicked();

  private:
    Ui::Login *ui;
    // int userType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif // LOGIN_H
