#include <QtNetwork>
#include <QIODevice>

#include "servermainwindow.h"
#include "ui_servermainwindow.h"
#include "toserverstructs.h"

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
			this, &ServerMainWindow::disconnect);
	connect(clientConnection, &QAbstractSocket::readyRead,
			this, &ServerMainWindow::newMessage);
	currentConnection = clientConnection;
	in.setDevice(currentConnection);
}
void ServerMainWindow::disconnect()
{

}

void ServerMainWindow::newMessage()
{
	in.startTransaction();
	QString message;
	quint16 oType;
	in >> oType;

	if(!in.commitTransaction())
		return;
	frontask::loginAccount opt_login;
	frontask::regist opt_reg;
	in << opt_login;
	switch (oType) {
	case frontask::login:
		in >> opt_login;
		break;
	case frontask::reg:
		in >> opt_reg;
		break;
	default:
		break;
	}
	if(!in.commitTransaction())
		return;

	//do...
	switch (oType) {
	case frontask::login:
		database->login( opt_login.userID, opt_login.pwd );
		break;
	case frontask::reg:
		database->regist( opt_reg.name, opt_reg.pwd );
		break;
	default:
		break;
	}
}
