#ifndef MYTICKET_H
#define MYTICKET_H

#include <QDialog>

namespace Ui {
class Myticket;
}

class Myticket : public QDialog
{
    Q_OBJECT

public:
    explicit Myticket(QWidget *parent = 0);
    ~Myticket();

private:
    Ui::Myticket *ui;
};

#endif // MYTICKET_H
