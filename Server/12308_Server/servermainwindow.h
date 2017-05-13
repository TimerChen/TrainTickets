#ifndef SERVERMAINWINDOW_H
#define SERVERMAINWINDOW_H

#include <QMainWindow>
#include "include/algorithm0.hpp"
#include "include/smartpoint.hpp"

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
	void sendBack();

private:
	Ui::ServerMainWindow *ui;
	QTcpServer *tcpServer;
	QTcpSocket *currentConnection;

	ttd::shared_ptr<DataBase_Main>dataBase;

};

#endif // SERVERMAINWINDOW_H
