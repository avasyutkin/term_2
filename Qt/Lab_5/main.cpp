#include "database.h"
#include "registration.h"
#include <QApplication>
#include <server.h>
#include <client.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //registration w;
    //w.show();
    Server server;
    server.startServer();
    Client client;
    client.show();
    registration window_reg;
    window_reg.show();

    return a.exec();
}








