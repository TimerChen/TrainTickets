#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "include/smartpoint.hpp"
#include "include/utility.hpp"
#include "include/vector.hpp"
#include "include/DataBase_Train.h"
#include "include/DataBase_Account.h"
#include "toserverstructs.h"
#include "uistructs.h"


namespace Ui {
enum { annonymous, normal, admin, searchusr };
enum { stationToStation, stationSearch, trainSearch };
bool Compare_for_qtrains(const DataBase_Train::QTrain &q1,const DataBase_Train::QTrain &q2);

class MainWindow;
}


class MainWindow : public QMainWindow {
    Q_OBJECT


	friend class Login;
	friend class Regist;
	friend class SearchTicket;
	friend class Myticket;
	friend class Myinform;
	friend class sysLog;
	friend class searchUsr;
	friend class modifyPlanOfATrain;
	friend class addplansimple;
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

    void on_styleBtn_clicked();

private:
    Ui::MainWindow *ui;
    // int userType;
    ttd::shared_ptr<uistructs::nowAccount> nowaccount;

	QTcpSocket *serverSocket;
	QDataStream serverIn;

	int register_remote(const QString &UserId, const QString &pwd);
	ttd::pair<int, QString> login_remote(const QString &UserId, const QString &pwd);
    ttd::pair<int,QString> aulogin_remote(const QString &UserId, const QString &pwd);
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
	ttd::map< DataBase_Account::Ticket , int>
		askTickets_remote
		( const QString &fask );

	void changePwd_remote
		( const frontask::changePwd &fask );
	void changeName_remote
		( const frontask::changeUsrName &fask );

	DataBase_Account::Account query_name_remote( const QString &fask );

	void addTrain_remote( const QString &fask );
	void delTrain_remote( const QString &fask );
	void openDate_remote( const QString &Train, const QDate &Date );
	void closeDate_remote( const QString &Train, const QDate &Date );

	QString query_log_remote();
    void changestyle();

};

#endif  // MAINWINDOW_H
