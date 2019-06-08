#include <QApplication>
#include "server.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //############

    Server server(8080);
    server.show();

    Client client1("localhost", 8080);
    client1.show();

    Client client2("localhost", 8080);
    client2.show();

    //############

    return a.exec();
}
