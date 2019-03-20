#include "driver.h"
#include "departurejournal.h"
#include "iostream"
#include "fstream"
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <string>
#include "vector"

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

void Driver::writejournal(string _carmodel, string _name, string _dateday, string _datemonth, string _dateyear, string _timehour, string _timeminute)
{
    jl = _carmodel+":"+_name+":"+_dateday+"/"+_datemonth+"/"+_dateyear+":"+_timehour+"/"+_timeminute+"\n";
    journl.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\departurejournal.txt", ios::app);
    journl<<jl;
    journl.close();

}
