#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    QTcpServer *_tcpServer;
    QTcpSocket* socket;
    QByteArray Data;
    explicit Server(QWidget *parent = nullptr);
    ~Server();

public slots:
    void startServer();
    void incomingConnection(int socketDescriptor);
    void socketReady();
    void socketDisconnection_server();



private:
    Ui::Server *ui;
};

#endif // SERVER_H
