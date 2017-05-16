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
	connect(ui->commandButton,SIGNAL(clicked()),this,SLOT(newCommand()));
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

void ServerMainWindow::newCommand()
{
	QStringList qlist = ui->commandEdit->text().split(' ');
	if(qlist.size()==0)return;
	ui->commandButton->setEnabled(false);
	database->addLog("> " + ui->commandEdit->text());
	refreshConsole();
	if( qlist[0] == QString("read") && qlist.size() > 1 )
	{
		if(qlist[1] == QString("train"))
		{
			if(qlist.size() < 3)
				database->loadData_raw_train("onerawdata.csv");
			else
				database->loadData_raw_train(qlist[2]);
		}else if(qlist[2] == QString("buy")){
			if(qlist.size() < 3)
				database->loadData_raw_buy("rawbuy.in");
			else
				database->loadData_raw_buy(qlist[2]);
		}
	}else if(qlist[0] == QString("test")){
		database->query_stationToStation(-1,QDate(2017,3,28),"恩施","宜昌东");
	}
	refreshConsole();
	ui->commandEdit->setText("");
	ui->commandButton->setEnabled(true);
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
	//QMessageBox::information(this,"Info","disconnect");
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

	frontask::stationToStationSearch opt_qsts;
	frontask::stationSearch opt_qs;
	frontask::trainSearch opt_qt;
	frontask::loginAccount opt_login;
	frontask::regist opt_reg;
	frontask::targetTicket opt_tic;
	QString opt_str;
	switch (oType) {
	case frontask::stationtostationsearch:
		in >> opt_qsts;
		break;
	case frontask::stationsearch:
		in >> opt_qs;
		break;
	case frontask::trainsearch:
		in >> opt_qt;
		break;
	case frontask::modifymyticket:
		in >> opt_tic;
		break;
	case frontask::buyTicket:
		in >> opt_tic;
		break;
	case frontask::getmytickets:
		in >> opt_str;
		break;
	case frontask::login:
		in >> opt_login;
		break;
	case frontask::aulogin:
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
	case frontask::stationtostationsearch:
	{
		ttd::vector<DataBase_Train::QTrain> tmp;
		try{
			tmp = database->query_stationToStation
				( currentUser, opt_qsts.time, opt_qsts.fromStation, opt_qsts.toStation);
		}catch(...){
			out << false;
			break;
		}
		out << true;
		out << tmp;
		break;
	}
	case frontask::stationsearch:
	{
		ttd::vector<DataBase_Train::TrainRoute> tmp;
		try{
			//Not used opt_**.time
			tmp = database->query_station( currentUser, opt_qs.station );
		}catch(...){
			out << false;
			break;
		}
		out << true;
		out << tmp;
		break;
	}
	case frontask::trainsearch:
	{
		DataBase_Train::TrainRoute tmp;
		try{
			//Not used opt_**.time
			tmp = database->query_train( currentUser, opt_qt.trainID );
		}catch(...){
			out << false;
			break;
		}
		out << true;
		out << tmp;
		break;
	}
	case frontask::modifymyticket:
	{
		try{
			database->returnTickets( currentUser, opt_tic.usrID, opt_tic.trainID,
									 opt_tic.time, opt_tic.loadStation, opt_tic.unLoadStation,
									 opt_tic.seatType, opt_tic.buyNum);
		}catch(...){
			out << false;
			break;
		}
		out << true;
		break;
	}
	case frontask::buyTicket:
	{
		try{
			database->buyTickets( currentUser, opt_tic.usrID, opt_tic.trainID,
								  opt_tic.time, opt_tic.loadStation, opt_tic.unLoadStation,
								  opt_tic.seatType, opt_tic.buyNum);
		}catch(...){
			out << false;
			break;
		}
		out << true;
		break;
	}
	case frontask::getmytickets:
	{
		ttd::map<DataBase_Account::Ticket,int> tmp;
		try{
			tmp = database->ownedTicket( currentUser, opt_str );
		}catch(...){
			out << false;
			break;
		}
		out << true;
		out << tmp;
		break;
	}
	case frontask::aulogin:
	{
		ttd::pair<int, QString> tmp
			= database->login( opt_login.userID, opt_login.pwd, 1 );
		currentUser = tmp.first;
		if(tmp.first > 0)
			tmp.first = 2;
		out << tmp;
		break;
	}
	case frontask::login:
	{
		ttd::pair<int, QString> tmp
			= database->login( opt_login.userID, opt_login.pwd );
		currentUser = tmp.first;
		if(tmp.first > 0)
			tmp.first = 1;
		out << tmp;
		break;
	}

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