#ifndef SERVERMAINWINDOW_H
#define SERVERMAINWINDOW_H

#include <QMainWindow>
#include <QDataStream>
#include "include/algorithm0.hpp"
#include "include/smartpoint.hpp"
#include "include/vector.hpp"

class QTcpServer;
class QTcpSocket;

class DataBase_Main;
namespace Ui {
class ServerMainWindow;
}

class ServerMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit ServerMainWindow(QWidget *parent = 0);
	~ServerMainWindow();
private slots:
	void newConnection();
	void newMessage();
	void disconnect();
	void refreshConsole();

private:
	Ui::ServerMainWindow *ui;
	QTcpServer *tcpServer;
	QTcpSocket *currentConnection;
	int currentUser;
	QDataStream in;

	ttd::shared_ptr<DataBase_Main>database;
	ttd::normal_ptr<ttd::vector<QString> > logs;

};

#endif // SERVERMAINWINDOW_H
