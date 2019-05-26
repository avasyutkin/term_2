#include "database.h"
#include "registration.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    registration w;
    w.show();

    return a.exec();
}








