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

private:
    Ui::StationToStationSearch *ui;
};

#endif // STATIONTOSTATIONSEARCH_H
