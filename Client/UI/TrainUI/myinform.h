#ifndef MYINFORM_H
#define MYINFORM_H

#include <QDialog>

namespace Ui {
class Myinform;
}

class Myinform : public QDialog
{
    Q_OBJECT

public:
    explicit Myinform(QWidget *parent = 0);
    ~Myinform();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Myinform *ui;
};

#endif // MYINFORM_H
