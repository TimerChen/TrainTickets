#ifndef ADDPLANSIMPLE_H
#define ADDPLANSIMPLE_H

#include <QDialog>

namespace Ui {
class addplansimple;
}

class addplansimple : public QDialog
{
    Q_OBJECT

public:
    explicit addplansimple(QWidget *parent = 0);
    ~addplansimple();

private:
    Ui::addplansimple *ui;
};

#endif // ADDPLANSIMPLE_H
