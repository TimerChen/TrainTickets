#ifndef TRAINSEARCH_H
#define TRAINSEARCH_H

#include <QDialog>

namespace Ui {
class TrainSearch;
}

class TrainSearch : public QDialog
{
    Q_OBJECT

public:
    explicit TrainSearch(QWidget *parent = 0);
    ~TrainSearch();

private slots:
    void on_searchbotton_clicked();

private:
    Ui::TrainSearch *ui;
};

#endif // TRAINSEARCH_H
