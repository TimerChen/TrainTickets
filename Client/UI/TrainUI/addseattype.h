#ifndef ADDSEATTYPE_H
#define ADDSEATTYPE_H

#include <QDialog>

namespace Ui {
class addSeatType;
}

class addSeatType : public QDialog
{
    Q_OBJECT

public:
    explicit addSeatType(QWidget *parent = 0);
    ~addSeatType();

private:
    Ui::addSeatType *ui;
};

#endif // ADDSEATTYPE_H
