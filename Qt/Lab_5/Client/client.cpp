#include "client.h"
#include "ui_client.h"

using namespace std;

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    clientSocket = new QTcpSocket;
    clientSocket -> connectToHost("127.0.0.1", 7557);
    connect(clientSocket, &QTcpSocket::readyRead, this, &Client::readFromServer);
    connect(clientSocket, &QTcpSocket::disconnected, this, &Client::disconnect);
}

Client::~Client()
{
    delete ui;
}

void Client::readFromServer()
{
    QByteArray answer;
    answer = clientSocket -> readAll();
    QByteArray arr;
    arr.append(answer);
    clientSocket -> write(arr);
    /*int position = answer.toStdString().find("true");
    if(position != string::npos)
    {
        string info = answer.toStdString();
        info
    }*/
}

void Client::disconnect()
{
    clientSocket->close();
}

void Client::showBack()
{
   // this->show();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Client::readFromServer);
    connect(clientSocket, &QTcpSocket::disconnected, this, &Client::disconnect);
}
