#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0, int user = Ui::annonymous);
    int getUserType();

    ~Login();

private slots:

    void on_loginBtn_clicked();

    void on_auloginBtn_clicked();

    void on_registBtn_clicked();

private:
    Ui::Login *ui;
    int userType;
};

#endif // LOGIN_H
