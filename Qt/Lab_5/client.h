#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>
#include <qDebug>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    QTcpSocket *socket;
    QByteArray Data;

public slots:
    void socketReady();
    void socketDisconnection_client();

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
