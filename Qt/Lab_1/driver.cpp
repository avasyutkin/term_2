#include "driver.h"
#include "departurejournal.h"
#include "iostream"
#include "fstream"
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <string>
#include "vector"
#include <QTextStream>

using namespace std;

Driver::Driver()
{

}

Driver::Driver(string tableName)
{
    _tableName=tableName;
    DataBase a;
    a.usertovector(_tableName);
}

Driver::~Driver()
{

}

void Driver::writejournal(QString _id, QString _carmodel, QString _driver, QString _date, QString _time)
{
    jl = _carmodel+":"+_driver+"("+_id+")"+":"+_date+":"+_time+"\n";
    QFile journal("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\departurejournal.txt");
    journal.open(QIODevice::Append);
    QTextStream registS(&journal);
    registS<<jl;
    journal.close();

}
