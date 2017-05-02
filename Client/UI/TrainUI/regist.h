#ifndef REGIST_H
#define REGIST_H

#include <QDialog>

namespace Ui {
class Regist;
}

class Regist : public QDialog
{
    Q_OBJECT

public:
    explicit Regist(QWidget *parent = 0);
    ~Regist();

private slots:
    void on_loginBtn_clicked();

    void on_backtologinBtn_clicked();

private:
    Ui::Regist *ui;
};

#endif // REGIST_H
