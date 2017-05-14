#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "include/smartpoint.hpp"
#include "uistructs.h"

namespace Ui {
enum { annonymous, normal, admin, searchusr };
enum { stationToStation, stationSearch, trainSearch };
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget *parent = 0);
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
    // int userType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;
};

#endif  // MAINWINDOW_H
