#ifndef SEVER_H
#define SEVER_H
#include <QWidget>
#include <QTcpSocket>

class QTcpServer;
class QTcpSocket;
class QTextEdit;

class Server: public QWidget{
Q_OBJECT

private:

    QString xo[3][3];

void setArray(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            xo[i][j] = " - ";
        }
    }
}

QTcpServer *_tcpServer;
QTcpSocket *_clientSocket1;
quint16 _nextBlockSize;
QTextEdit *_text;
QMap<qintptr,QTcpSocket *> Clients;
QString symbol1;
QString symbol2;

void sendToClient(QTcpSocket *socket, const QString &str);

public:

Server(quint16 port);

public slots:

virtual void slotNewConnection();
void slotReadClient();

};

#endif // SEVER_H
