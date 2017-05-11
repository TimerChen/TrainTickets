#ifndef TRAINSEARCH_H
#define TRAINSEARCH_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class TrainSearch;
}

class TrainSearch : public QDialog
{
    Q_OBJECT

public:
    explicit TrainSearch(QWidget *parent = 0, int user = Ui::annonymous);
    ~TrainSearch();

private slots:
    void on_searchbotton_clicked();

private:
    Ui::TrainSearch *ui;
    int userType;
};

#endif // TRAINSEARCH_H
