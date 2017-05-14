#include <QtNetwork>
#include <QIODevice>
#include <QMessageBox>

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

	currentUser = -1;
	database = new DataBase_Main("12308");
	logs = database->getLog();

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
	QMessageBox::information(this,"Info","disconnect");
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
	case frontask::logout:

		break;
	default:
		//unknown command
		return;
		break;
	}
	if(!in.commitTransaction())
		return;

	//do...
	QByteArray block;
	QDataStream out( &block, QIODevice::WriteOnly );
	out.setVersion( QDataStream::Qt_5_0 );

	switch (oType) {
	case frontask::login:
	{
		ttd::pair<int, QString> tmp
			= database->login( opt_login.userID, opt_login.pwd );
		out << tmp;
		currentUser = tmp.first;
	}
		break;
	case frontask::logout:
	{
		bool tmp
			= database->logout( currentUser );
		out << tmp;
		currentUser = -1;
	}
		break;
	case frontask::reg:
	{
		int tmp
			= database->regist( opt_reg.name, opt_reg.pwd );
		out << tmp;
	}
		break;
	default:
		break;
	}

	currentConnection->write(block);
}

void ServerMainWindow::refreshConsole()
{
	QString content;
	for(size_t i=0; i<5 && i<logs->size(); ++i)
	{
		content = content + (*logs)[i] + "\n";
	}
	ui->console->setText( content );
}
