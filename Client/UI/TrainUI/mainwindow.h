#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
enum{
    annonymous,
    normal,
    admin
};
enum{
    stationToStation,
    stationSearch,
    trainSearch
};
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, int user = Ui::annonymous);
    ~MainWindow();

private slots:
    void on_loginBtn_clicked();

    void on_regBtn_clicked();

    void on_logoutBtn_clicked();

    void on_myticketBtn_clicked();

    void on_myinformBtn_clicked();

    void on_stationToStationSearchBtn_clicked();

    void on_trainSearchBtn_clicked();

    void on_stationSearchBtn_clicked();

private:
    Ui::MainWindow *ui;
    int userType;
};

#endif // MAINWINDOW_H
