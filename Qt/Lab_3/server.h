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
};

#endif // SEVER_H
