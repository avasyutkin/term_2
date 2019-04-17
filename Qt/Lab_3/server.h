#ifndef SEVER_H
#define SEVER_H

#include <QWidget>
#include <QTcpSocket>
#include <string>

class QTcpServer;
class QTcpSocket;
class QTextEdit;

using namespace std;

class Server: public QWidget{
    Q_OBJECT

private:
    QTcpServer *_tcpServer;
    QTcpSocket *_clientSocket;

    quint16 _nextBlockSize;

    QTextEdit *_text;
    QMap<int,QTcpSocket *> SClients;

    void sendToClient(QTcpSocket *socket, const QString &str);
    bool stack;

public:
    Server(quint16 port);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();
    void TicTokToe(string ttt);
    char tiktoktoe[3][3] = '-', '-', '-', '-', '-', '-', '-',;
};

#endif // SEVER_H
