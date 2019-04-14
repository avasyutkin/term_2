#include "mainwindow.h"
#include "registration.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    registration w;
    w.show();

    a.exec();
}
