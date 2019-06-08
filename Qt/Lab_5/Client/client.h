#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QString>
#include <QTcpSocket>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

signals:
    void sendCurrentUser(QString);
    void sendSocket(QTcpSocket* );
public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    QTcpSocket* clientSocket;

private:
    Ui::Client *ui;

private slots:
    void readFromServer();
    void disconnect();
    void showBack();
};

#endif // CLIENT_H
