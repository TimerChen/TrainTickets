#ifndef STATIONSEARCH_H
#define STATIONSEARCH_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class StationSearch;
}

class StationSearch : public QDialog {
    Q_OBJECT

  public:
    explicit StationSearch(ttd::shared_ptr<uistructs::nowAccount> _now,
                           QWidget *parent = 0);
    ~StationSearch();

  private slots:
    void on_searchbotton_clicked();

  private:
    Ui::StationSearch *ui;
    // int userType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif // STATIONSEARCH_H
