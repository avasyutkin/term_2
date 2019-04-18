#ifndef DRIVER_H
#define DRIVER_H

#include "person.h"
#include "database.h"
#include "iostream"
#include "fstream"
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <string>
#include "vector"

using namespace std;

class Driver : public Person
{
public:
    Driver();
    Driver(string tableName);
    ~Driver();
    void changelp();
    void writejournal(QString _id, QString _carmodel, QString _driver, QString _date, QString _time);

private:
    QString jl;
    string _tableName;
    ofstream journl;
};

#endif // DRIVER_H
