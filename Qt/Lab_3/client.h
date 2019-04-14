#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>

class QTextEdit;
class QLineEdit;

class Client: public QWidget
{
    Q_OBJECT

private:
    QTcpSocket *_tcpSocket;

    QTextEdit *_textInfo;
    QLineEdit *_textInput;
    quint16 _nextBlockSize;

public:
    Client(QString strHost, quint16 port);

public slots:
    void slotReadyRead();
    //void slotError(QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotConnected();
};

#endif // CLIENT_H
