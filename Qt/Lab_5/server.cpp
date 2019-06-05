#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
}

Server::~Server()
{
    delete ui;
}

void Server::startServer()
{
    _tcpServer = new QTcpServer(this);
   if(_tcpServer->listen(QHostAddress::Any, 80))
   {
        qDebug()<<"Listening";
   }
   else
   {
       qDebug()<<"Not listening";
   }
}

void Server::incomingConnection(int socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnection_client()));

    qDebug()<<socketDescriptor<<" Client connected";

    socket->write("You are connect");
    qDebug()<<"Send client status - yes";
}

void Server::socketReady()
{

}

void Server::socketDisconnection_server()
{
    qDebug()<<"Disconnected";
    socket->deleteLater();
}
