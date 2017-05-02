#ifndef STATIONSEARCH_H
#define STATIONSEARCH_H

#include <QDialog>

namespace Ui {
class StationSearch;
}

class StationSearch : public QDialog
{
    Q_OBJECT

public:
    explicit StationSearch(QWidget *parent = 0);
    ~StationSearch();

private:
    Ui::StationSearch *ui;
};

#endif // STATIONSEARCH_H
