#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "include/smartpoint.hpp"
#include "include/utility.hpp"
#include "include/vector.hpp"
#include "include/DataBase_Train.h"
#include "toserverstructs.h"
#include "uistructs.h"

#include "include/DataBase_Train.h"

namespace Ui {
enum { annonymous, normal, admin, searchusr };
enum { stationToStation, stationSearch, trainSearch };
class MainWindow;
}


class MainWindow : public QMainWindow {
    Q_OBJECT


	friend class Login;
	friend class Regist;
	friend class SearchTicket;
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

	void link();
	void dealError(QAbstractSocket::SocketError socketError);

   private:
    Ui::MainWindow *ui;
    // int userType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;

	QTcpSocket *serverSocket;
	QDataStream serverIn;

	int register_remote(const QString &UserId, const QString &pwd);
	ttd::pair<int, QString> login_remote(const QString &UserId, const QString &pwd);
	bool logout_remote();
	ttd::vector<DataBase_Train::QTrain> query_stationToStation();
	ttd::vector<DataBase_Train::TrainRoute> query_station();
	DataBase_Train::TrainRoute query_train();

	ttd::vector<DataBase_Train::QTrain>
		query_sts_remote
		( const frontask::stationToStationSearch &fask );
	ttd::vector<DataBase_Train::TrainRoute>
		query_s_remote
		( const frontask::stationSearch &fask );
	DataBase_Train::TrainRoute
		query_t_remote
		( const frontask::trainSearch &fask );

	void returnTickets_remote
		( const frontask::targetTicket &fask);
	void buyTickets_remote
		( const frontask::targetTicket &fask);
	ttd::map<DataBase_Account::Ticket,int> askTickets_remote
		( const QString &fask );


};

#endif  // MAINWINDOW_H
