#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT

private:
    QTcpServer *_server;
    QTcpSocket *_socket;

public:
    //explicit Server(QObject *parent = nullptr);
    Server();

signals:

public slots:
    void slotNewConnection();
    void readClient();
    void closeClientDisconnected();

};

#endif // SERVER_H
