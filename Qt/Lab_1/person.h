#ifndef PERSON_H
#define PERSON_H

#include "iostream"
#include "fstream"
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <string>
#include "vector"
#include <QDialog>
#include "database.h"

using namespace std;

class Person
{
public:
    Person();
    void reg(QString name, QString bday, QString bmonth, QString byear, QString phonenum, QString login, QString password, QString dbname);
    ~Person();
private:
    QString login;
    QString info;
    QString password;
    QString name;
    QString phonenum;
    QString bday;
    QString bmonth;
    QString byear;
    QString lp;
    string lpread;
};



#endif // PERSON_H
