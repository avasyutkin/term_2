#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnection_client()));
    socket->connectToHost("127.0.0.1", 80);
}

void Client::socketDisconnection_client()
{
    socket->deleteLater();
}

void Client::socketReady()
{
    if(socket->waitForConnected(500))
    {
        socket->waitForReadyRead(500);
        Data = socket->readAll();
        qDebug()<<Data;
    }
}

Client::~Client()
{
    delete ui;
}
