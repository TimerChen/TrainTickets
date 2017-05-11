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

private slots:
    void on_searchbotton_clicked();

private:
    Ui::StationSearch *ui;
};

#endif // STATIONSEARCH_H
