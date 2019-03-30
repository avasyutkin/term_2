#include "person.h"
#include <QCoreApplication>
#include "database.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

using namespace std;

Person::Person()
{

}

void Person::reg(QString name, QString bday, QString bmonth, QString byear, QString phonenum, QString login, QString password, QString dbname)
{
    lp = login+":"+password+"^"+dbname+". "+name+":"+bday+"/"+bmonth+"/"+byear+":"+phonenum+"\n";
    QFile regist("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\autorize.txt");
    regist.open(QIODevice::Append);
    QTextStream registS(&regist);
    registS<<lp;
    regist.close();
    lp=login+":"+password+":"+name+":"+bday+"/"+bmonth+"/"+byear+":"+phonenum+"\n";
    QFile registall("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\"+dbname+".txt");
    registall.open(QIODevice::Append);
    QTextStream registallS(&registall);
    registallS<<lp;
    registall.close();
}

Person::~Person()
{

}

