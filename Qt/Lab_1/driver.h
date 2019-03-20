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
    void writejournal(string _carmodel, string _name, string _dateday, string _datemonth, string _dateyear, string _timehour, string _timeminute);
private:
    /*
    string carmodel;
    string date;
    string time;*/
    string jl;
    string _tableName;
    ofstream journl;
};

#endif // DRIVER_H
