#ifndef REGIST_H
#define REGIST_H

#include <QDialog>
#include "include/smartpoint.hpp"
#include <QRegExpValidator>

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

    //void on_backtologinBtn_clicked();

    void on_registBtn_clicked();

private:
    Ui::Regist *ui;
    ttd::shared_ptr<QRegExpValidator> pReg;
};

#endif // REGIST_H
