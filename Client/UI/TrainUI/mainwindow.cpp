#include "mainwindow.h"
#include <QMessageBox>
#include "adminwindow.h"
#include "login.h"
#include "myinform.h"
#include "myticket.h"
#include "regist.h"
#include "stationsearch.h"
#include "stationtostationsearch.h"
#include "trainsearch.h"
#include "ui_mainwindow.h"
#include "toserverstructs.h"

#include <QtNetwork>
#include <QDataStream>
#include <QIODevice>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
	  nowaccount(new uistructs::nowAccount),
	  serverSocket(new QTcpSocket(this))
{
    ui->setupUi(this);
    ui->myticketBtn->setEnabled(false);
    ui->myinformBtn->setEnabled(false);
    ui->logoutBtn->setEnabled(false);
    ui->nameLabel->hide();
    ui->welcomeLabel->hide();

	connect(serverSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(dealError(QAbstractSocket::SocketError)));
	//connect(serverSocket,SIGNAL(readyRead()),this,SLOT(getInfo()));

	link();

	serverIn.setDevice(serverSocket);
	serverIn.setVersion(QDataStream::Qt_5_0);



}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::link()
{
	QFile ipconfig("ipconfig.txt");
    ipconfig.open(QIODevice::ReadOnly);

    QTextStream in(&ipconfig);
    in.setCodec("UTF-8");
    QString ip;
    in >> ip;
	serverSocket->abort();
    serverSocket->connectToHost(ip, 12308);
}

void MainWindow::dealError(QAbstractSocket::SocketError socketError)
{
	if(socketError != QAbstractSocket::RemoteHostClosedError)
	QMessageBox::information(this, tr("Error"), tr("An error orcurred."));

	switch (socketError) {
	case QAbstractSocket::RemoteHostClosedError:
		break;
	case QAbstractSocket::HostNotFoundError:
		QMessageBox::information(this, tr("Fortune Client"),
								 tr("The host was not found. Please check the "
									"host name and port settings."));
		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::information(this, tr("Fortune Client"),
								 tr("The connection was refused by the peer. "
									"Make sure the fortune server is running, "
									"and check that the host name and port "
									"settings are correct."));
		break;
	default:
		QMessageBox::information(this, tr("Fortune Client"),
								 tr("The following error occurred: %1.")
								 .arg(serverSocket->errorString()));
	}
	//ui->getText->setText(tr("[Nothing]"));
	//ui->linkButton->setEnabled(true);
}

void MainWindow::on_loginBtn_clicked() {
    Login log(nowaccount, this);
    if (log.exec() == QDialog::Accepted) {
        int userType = nowaccount->userType;
        ui->loginBtn->setEnabled(false);
        ui->regBtn->setEnabled(false);
        ui->myinformBtn->setEnabled(true);
        ui->logoutBtn->setEnabled(true);
        ui->myticketBtn->setEnabled(true);
        ui->welcomeLabel->show();
        ui->nameLabel->show();
        ui->nameLabel->setText(nowaccount->name + "!!");
        if (userType == Ui::admin) {
            AdminWindow adw(nowaccount, this);
            this->hide();
            if(adw.exec() == QDialog::Accepted) this->show();
            else qApp->quit();
            this->on_logoutBtn_clicked();
        }
    }
}

void MainWindow::on_regBtn_clicked() {
    Regist reg(this);
    reg.exec();
}


void MainWindow::on_logoutBtn_clicked() {
    /// send a package to server to log out
    if(!logout_remote())
		return;

    ui->myticketBtn->setEnabled(false);
    ui->myinformBtn->setEnabled(false);
    ui->logoutBtn->setEnabled(false);
    ui->loginBtn->setEnabled(true);
    ui->regBtn->setEnabled(true);
    nowaccount->userType = Ui::annonymous;
    nowaccount->name = "";
    nowaccount->userID = "";
    // nowaccount->IDcard = "";
    ui->nameLabel->hide();
    ui->welcomeLabel->hide();
}

void MainWindow::on_myticketBtn_clicked() {
    Myticket myticket(nowaccount, this);

    myticket.exec();
}

void MainWindow::on_myinformBtn_clicked() {
    Myinform myinform(nowaccount, this);
    myinform.exec();
    ui->nameLabel->setText(nowaccount->name);
}

void MainWindow::on_stationToStationSearchBtn_clicked() {
    StationToStationSearch s(nowaccount, this);

    s.exec();
}

void MainWindow::on_trainSearchBtn_clicked() {
    TrainSearch s(nowaccount, this);

    s.exec();
}

void MainWindow::on_stationSearchBtn_clicked() {
    StationSearch s(nowaccount, this);

    s.exec();
}

int MainWindow::register_remote(const QString &UserId, const QString &pwd)
{
	QByteArray block;
	int serverReturn;
	QDataStream serverOut(&block,QIODevice::WriteOnly);
	serverOut.setVersion(QDataStream::Qt_5_0);
	serverOut << (quint16)(frontask::reg)
				 << frontask::regist(UserId, pwd) ;

	serverSocket->write(block);
	serverSocket->waitForBytesWritten();
	//QMessageBox::information(this,"Info","write_OK");
	while(1)
	{
		serverSocket->waitForReadyRead();
		//QMessageBox::information(this,"Info","ReadReady_OK");
		serverIn.startTransaction();
		serverIn >> serverReturn;
		if(serverIn.commitTransaction())
			break;
	}
	return serverReturn;
}

ttd::pair<int,QString> MainWindow::login_remote(const QString &UserId, const QString &pwd)
{
	QByteArray block;
	ttd::pair<int,QString> serverReturn;
	QDataStream serverOut(&block,QIODevice::WriteOnly);
	serverOut.setVersion(QDataStream::Qt_5_0);

	serverOut << (quint16)frontask::login
				 << frontask::loginAccount(UserId, pwd) ;

	serverSocket->write(block);
	serverSocket->waitForBytesWritten();
	while(1)
	{
		serverSocket->waitForReadyRead();
		//QMessageBox::information(this,"Info","ReadReady_OK");
		serverIn.startTransaction();
		serverIn >> serverReturn;
		if(serverIn.commitTransaction())
			break;
	}
	//QMessageBox::information(this,"Info","Read_OK");
	return serverReturn;
}

ttd::pair<int,QString> MainWindow::aulogin_remote(const QString &UserId, const QString &pwd)
{
    QByteArray block;
    ttd::pair<int,QString> serverReturn;
    QDataStream serverOut(&block,QIODevice::WriteOnly);
    serverOut.setVersion(QDataStream::Qt_5_0);

    serverOut << (quint16)frontask::aulogin
                 << frontask::loginAccount(UserId, pwd) ;

    serverSocket->write(block);
    serverSocket->waitForBytesWritten();
    while(1)
    {
        serverSocket->waitForReadyRead();
        //QMessageBox::information(this,"Info","ReadReady_OK");
        serverIn.startTransaction();
        serverIn >> serverReturn;
        if(serverIn.commitTransaction())
            break;
    }
    //QMessageBox::information(this,"Info","Read_OK");
    return serverReturn;
}

bool MainWindow::logout_remote()
{
	QByteArray block;
	bool serverReturn;
	QDataStream serverOut(&block,QIODevice::WriteOnly);
	serverOut.setVersion(QDataStream::Qt_5_0);

	serverOut << (quint16)frontask::logout;
	serverSocket->write(block);
	serverSocket->waitForBytesWritten();
	//QMessageBox::information(this,"Info","write_OK");
	while(1)
	{
		serverSocket->waitForReadyRead();
		//QMessageBox::information(this,"Info","ReadReady_OK");
		serverIn.startTransaction();
		serverIn >> serverReturn;
		if(serverIn.commitTransaction())
			break;
	}
	return serverReturn;
}


ttd::vector<DataBase_Train::QTrain>
	MainWindow::query_sts_remote
	( const frontask::stationToStationSearch &fask )
{
	QByteArray block;
	ttd::vector<DataBase_Train::QTrain> serverReturn;
	QDataStream serverOut(&block,QIODevice::WriteOnly);
	serverOut.setVersion(QDataStream::Qt_5_0);

	serverOut << (quint16)frontask::stationtostationsearch
			<< fask;
	serverSocket->write(block);
	serverSocket->waitForBytesWritten();
	//QMessageBox::information(this,"Info","write_OK");
	bool no_error;
	while(1)
	{
		serverSocket->waitForReadyRead();
		serverIn.startTransaction();
		serverIn >> no_error;
		if( no_error )
			serverIn >> serverReturn;
		if(serverIn.commitTransaction())
			break;
	}
	if(!no_error) throw(0);
	return serverReturn;
}

ttd::vector<DataBase_Train::TrainRoute>
	MainWindow::query_s_remote
	( const frontask::stationSearch &fask )
{
	QByteArray block;
	ttd::vector<DataBase_Train::TrainRoute> serverReturn;
	QDataStream serverOut(&block,QIODevice::WriteOnly);
	serverOut.setVersion(QDataStream::Qt_5_0);

	serverOut << (quint16)frontask::stationsearch
			<< fask;
	serverSocket->write(block);
	serverSocket->waitForBytesWritten();
	//QMessageBox::information(this,"Info","write_OK");
	bool no_error;
	while(1)
	{
		serverSocket->waitForReadyRead();
		serverIn.startTransaction();
		serverIn >> no_error;
		if( no_error )
			serverIn >> serverReturn;
		if(serverIn.commitTransaction())
			break;
	}
	if(!no_error) throw(0);
	return serverReturn;
}

DataBase_Train::TrainRoute
	MainWindow::query_t_remote
	( const frontask::trainSearch &fask )
{
	QByteArray block;
	DataBase_Train::TrainRoute serverReturn;
	QDataStream serverOut(&block,QIODevice::WriteOnly);
	serverOut.setVersion(QDataStream::Qt_5_0);

	serverOut << (quint16)frontask::trainsearch
			<< fask;
	serverSocket->write(block);
	serverSocket->waitForBytesWritten();
	//QMessageBox::information(this,"Info","write_OK");
	bool no_error;
	while(1)
	{
		serverSocket->waitForReadyRead();
		serverIn.startTransaction();
		serverIn >> no_error;
		if( no_error )
			serverIn >> serverReturn;
		if(serverIn.commitTransaction())
			break;
	}
	if(!no_error) throw(0);
	return serverReturn;
}
