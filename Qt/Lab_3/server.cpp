#include "server.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QDataStream>
#include <QTime>

Server::Server(quint16 port): _nextBlockSize(0){
    _tcpServer = new QTcpServer(this);

    if (!_tcpServer->listen(QHostAddress::Any, port)){
        _tcpServer->close();
        return;
    }

    connect(_tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

    _text = new QTextEdit();
    _text->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel("<H1>Server</H1>"));
    layout->addWidget(_text);
    setLayout(layout);
}

void Server::slotNewConnection()
{
    //QTcpSocket* _clientSocket = new QTcpSocket;
    _clientSocket = _tcpServer->nextPendingConnection();
    int idusersocs=_clientSocket->socketDescriptor();
    SClients[idusersocs]=_clientSocket;
    connect(SClients[idusersocs], SIGNAL(disconnected()), SClients[idusersocs], SLOT(deleteLater()));
    connect(SClients[idusersocs], SIGNAL(readyRead()), this, SLOT(slotReadClient()));

    sendToClient(SClients[idusersocs], "Server response: connected.");
    _clientSocket->write("Server response: connected.\n\r");
}

void Server::slotReadClient()
{
    //Вариант 1
    /*while(_clientSocket->bytesAvailable()>0){
        QByteArray array = _clientSocket->readAll();
        _clientSocket->write(array);
    }


    //Вариант 2
    //QTcpSocket *sckt = dynamic_cast<QTcpSocket *>(sender());
    if (!_clientSocket->canReadLine()) return;

    char buf[1024];
    _clientSocket->readLine(buf, sizeof(buf));
    _clientSocket->write(buf);
    //_text->setText(buf);*/

    //Вариант 3
    foreach(int i,SClients.keys())
    {
        QDataStream in(SClients[i]);
        //in.setVersion(QDataStream::Qt_5_10);

        while(true){
            if (_nextBlockSize == 0)
            {
                if (SClients[i]->bytesAvailable() < static_cast<int>(sizeof(quint16)))
                    break;
                in >> _nextBlockSize;
            }
            if (SClients[i]->bytesAvailable() < _nextBlockSize)
                break;

            QTime time;
            QString str;
            in >> time >> str;

            if(str.size() == 0)
            {
                QString message = time.toString() + " " + "Locked.";
                _text -> append(message);
            }
            else
            {
                QString message = time.toString() +  " " + "Unlocked. Client has sent - " + str + ".";
                _text->append(message);
            }

            //        QString message = time.toString() + " " + "Client has sent - " + str + ".";
            //        _text->append(message);

            _nextBlockSize = 0;

            sendToClient(SClients[i], "Server response: received \"" + str + "\".");
        }
    }
}

void Server::sendToClient(QTcpSocket* socket, const QString &str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_5_10);

    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - static_cast<int>(sizeof(quint16)));

    socket->write(arrBlock);
}

