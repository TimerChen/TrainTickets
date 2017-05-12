#ifndef TRAINSEARCH_H
#define TRAINSEARCH_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class TrainSearch;
}

class TrainSearch : public QDialog {
    Q_OBJECT

  public:
    explicit TrainSearch(ttd::shared_ptr<uistructs::nowAccount> _now,
                         QWidget *parent = 0);
    ~TrainSearch();

  private slots:
    void on_searchbotton_clicked();

  private:
    Ui::TrainSearch *ui;
    // int userType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif // TRAINSEARCH_H
