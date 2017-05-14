#ifndef STATIONTOSTATIONSEARCH_H
#define STATIONTOSTATIONSEARCH_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class StationToStationSearch;
}

class StationToStationSearch : public QDialog {
    Q_OBJECT

   public:
    explicit StationToStationSearch(ttd::shared_ptr<uistructs::nowAccount> _now,
                                    QWidget *parent = 0, QString _adminID = "",
                                    QString _adminName = "");
    ~StationToStationSearch();

   private slots:
    void on_searchbotton_clicked();

   private:
    Ui::StationToStationSearch *ui;
    // int userType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
    QString adminID, adminName;
};

#endif  // STATIONTOSTATIONSEARCH_H
