#include "server.h"
#include <QDebug>
#include <QCoreApplication>
//#include <QDateTime>

/*Server::Server(QObject *parent) : QObject(parent)
{

}*/

Server::Server()
{
    _server = new QTcpServer(this);
    connect(_server, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
    if(!_server->listen(QHostAddress::Any, 8080))
    {
        qDebug() << "server is not started";
    }
    else
    {
        qDebug() << "server is started";
    }
}

void Server::slotNewConnection()
{
    _socket = _server->nextPendingConnection(); //на стороне клиента создаем сокет для соединения с клиентом
    _socket->write("Hello!\r\n");
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(slotClientDisconnected()));
}

void Server::readClient()
{
    /*while(_socket->bytesAvailable()>0)
    {
        QByteArray array = _socket->readAll();
        _socket->write(array);
    }
}*/

    QTcpSocket *sk = dynamic_cast<QTcpSocket *>(sender()); //объект, который вызвал данный слот
    if (!sk->canReadLine()) //считываем порции
        return;
    char buf[1024];
    sk->readLine(buf, sizeof(buf));
    _socket->write(buf);
}

void Server::closeClientDisconnected()
{

}
