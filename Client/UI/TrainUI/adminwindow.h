#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "include/smartpoint.hpp"
#include "uistructs.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog {
    Q_OBJECT

  public:
    explicit AdminWindow(ttd::shared_ptr<uistructs::nowAccount> _now,
                         QWidget *parent);
    ~AdminWindow();

  private:
    Ui::AdminWindow *ui;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif // ADMINWINDOW_H
