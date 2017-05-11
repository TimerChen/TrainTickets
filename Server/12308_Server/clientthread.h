#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QtNetwork>



class ClientThread : public QThread
{
	Q_OBJECT
	QTcpSocket *socket;
public:
	explicit ClientThread(QObject *parent = NULL, QTcpSocket *Socket = NULL);
	virtual void run();
};

#endif // CLIENTTHREAD_H
