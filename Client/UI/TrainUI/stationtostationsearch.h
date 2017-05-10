#ifndef STATIONTOSTATIONSEARCH_H
#define STATIONTOSTATIONSEARCH_H

#include <QDialog>

namespace Ui {
class StationToStationSearch;
}

class StationToStationSearch : public QDialog
{
    Q_OBJECT

public:
    explicit StationToStationSearch(QWidget *parent = 0);
    ~StationToStationSearch();

private slots:
    void on_searchbotton_clicked();

private:
    Ui::StationToStationSearch *ui;
};

#endif // STATIONTOSTATIONSEARCH_H
