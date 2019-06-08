#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>

class Server : public QMainWindow
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);
    ~Server();

public slots:
    void slotNewConnection();
    void slotReadClient();
    void slotClientDisconnected();

private:
    QTcpServer* TcpServer;
    QTcpSocket* TcpSocket;
    QMap <int, QTcpSocket* > SClients;
    int serverStatus;

};

#endif // SERVER_H
