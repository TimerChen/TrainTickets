#include <QtNetwork>
#include <QIODevice>
#include <QMessageBox>
#include <QScrollBar>

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

	database->addLog( "Server opened." );
	refreshConsole();
}

ServerMainWindow::~ServerMainWindow()
{
	database->addLog( "Server closed." );
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
	in.setVersion(QDataStream::Qt_5_0);

	database->newConnection( currentConnection->peerAddress().toString() );
	refreshConsole();
}
void ServerMainWindow::disconnect()
{
	QMessageBox::information(this,"Info","disconnect");
	database->disconnect(currentUser);
	database->logout(currentUser);
	currentUser = -1;
	refreshConsole();
}

void ServerMainWindow::newMessage()
{
	in.startTransaction();

	database->addLog( "Ready read." );
	refreshConsole();

	quint16 oType;
	in >> oType;

	database->addLog( "New opearte " + QString::number(oType) );
	refreshConsole();

	frontask::loginAccount opt_login;
	frontask::regist opt_reg;
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
	{
		database->addLog( "No enough Data." );
		refreshConsole();
		return;
	}
	database->addLog( "Return infomation." );
	//do...
	QByteArray block;
	QDataStream out( &block, QIODevice::WriteOnly );
	out.setVersion( QDataStream::Qt_5_0 );

	switch (oType) {
	case frontask::login:
	{
		ttd::pair<int, QString> tmp
			= database->login( opt_login.userID, opt_login.pwd );
		currentUser = tmp.first;
		if(tmp.first > 0)
			tmp.first = 1;
		out << tmp;
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
			= database->regist( opt_reg.userID, opt_reg.pwd );
		out << tmp;
	}
		break;
	default:
		break;
	}

	currentConnection->write(block);
	currentConnection->waitForBytesWritten();

	database->addLog( "Written back Ok." );

	refreshConsole();
}

void ServerMainWindow::refreshConsole()
{
	QString content;
	for(size_t i=ttd::max((size_t)0,logs->size()-20); i<logs->size(); ++i)
	{
		content = content + (*logs)[i] + "\n";
	}
	ui->console->setText( content );
	QScrollBar *scrollbar = ui->console->verticalScrollBar();
	if (scrollbar)
		scrollbar->setSliderPosition(scrollbar->maximum());
}
