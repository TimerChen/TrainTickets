#include <QtNetwork>
#include <QIODevice>

#include "servermainwindow.h"
#include "ui_servermainwindow.h"

#include "include/database_main.h"

ServerMainWindow::ServerMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ServerMainWindow),
	tcpServer(Q_NULLPTR)
{
	ui->setupUi(this);
	database = new DataBase_Main("12308");
	tcpServer = new QTcpServer(this);
	tcpServer->listen(QHostAddress::Any,12308);
	connect(tcpServer,SIGNAL(newConnection()),this,SLOT(newConnection()));
	//connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(sendInfo()));
	currentConnection = NULL;
	in.setVersion(QDataStream::Qt_5_0);
}

ServerMainWindow::~ServerMainWindow()
{
	delete ui;
}

void ServerMainWindow::newConnection()
{
	QTcpSocket *clientConnection =tcpServer->nextPendingConnection();
	connect(clientConnection, &QAbstractSocket::disconnected,
			clientConnection, &QObject::deleteLater);
	connect(clientConnection, &QAbstractSocket::disconnected,
			this, &ServerMainWindow::disconnet);
	connect(clientConnection, &QAbstractSocket::readyRead,
			this, &ServerMainWindow::newMessage);
	currentConnection = clientConnection;
	in.setDevice(currentConnection);
}
void ServerMainWindow::disconnet()
{

}

void ServerMainWindow::newMessage()
{
	in.startTransaction();
	QString message;
	if(!in.commitTransaction())
		return;


}
void ServerMainWindow::sendBack()
{

}
