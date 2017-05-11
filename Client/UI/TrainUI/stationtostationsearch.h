#ifndef STATIONTOSTATIONSEARCH_H
#define STATIONTOSTATIONSEARCH_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class StationToStationSearch;
}

class StationToStationSearch : public QDialog
{
    Q_OBJECT

public:
    explicit StationToStationSearch(QWidget *parent = 0, int user = Ui::annonymous);
    ~StationToStationSearch();

private slots:
    void on_searchbotton_clicked();

private:
    Ui::StationToStationSearch *ui;
    int userType;
};

#endif // STATIONTOSTATIONSEARCH_H
