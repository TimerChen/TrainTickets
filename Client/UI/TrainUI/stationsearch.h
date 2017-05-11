#ifndef STATIONSEARCH_H
#define STATIONSEARCH_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class StationSearch;
}

class StationSearch : public QDialog
{
    Q_OBJECT

public:
    explicit StationSearch(QWidget *parent = 0, int user = Ui::annonymous);
    ~StationSearch();

private slots:
    void on_searchbotton_clicked();

private:
    Ui::StationSearch *ui;
    int userType;
};

#endif // STATIONSEARCH_H
