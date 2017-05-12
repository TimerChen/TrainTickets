#include "clientthread.h"

ClientThread::ClientThread(QObject *parent, QTcpSocket *Socket)
	:QThread( parent ), socket(Socket)
{

}
