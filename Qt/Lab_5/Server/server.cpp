#include "server.h"
#include <QDebug>

Server::Server(QWidget *parent)
    : QMainWindow(parent)
{
    TcpServer = new QTcpServer(this);
    connect(TcpServer, &QTcpServer::newConnection, this, &Server::slotNewConnection);
    if(TcpServer -> listen(QHostAddress::Any, 7557))
    {
        serverStatus = 1;
        qDebug() << "Server is working";
    }
}

Server::~Server()
{
    serverStatus = 0;
}

void Server::slotNewConnection()
{
    if(serverStatus == 1)
    {

        QTcpSocket* clientSocket = TcpServer -> nextPendingConnection();
        qDebug() << "New connection!" << clientSocket -> peerAddress();
        int countsock = clientSocket -> socketDescriptor();
        SClients[countsock] = clientSocket;
        connect(SClients[countsock], &QTcpSocket::readyRead, this, &Server::slotReadClient);
        connect(SClients[countsock], &QTcpSocket::disconnected, this, &Server::slotClientDisconnected);
    }
}

void Server::slotReadClient()
{

}

void Server::slotClientDisconnected()
{
    QTcpSocket* clientSocket = (QTcpSocket*) sender();
    qDebug() << "User Disconnected!" << clientSocket -> peerAddress();
    int countsock = clientSocket -> socketDescriptor();
    SClients. remove(countsock);
    clientSocket -> close();
}
