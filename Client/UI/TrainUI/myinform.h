#ifndef MYINFORM_H
#define MYINFORM_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Myinform;
}

class Myinform : public QDialog
{
    Q_OBJECT

public:
    explicit Myinform(QWidget *parent = 0, int user = Ui::annonymous);
    ~Myinform();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Myinform *ui;
    int userType;
};

#endif // MYINFORM_H
