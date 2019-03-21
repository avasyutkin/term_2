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
    void reg(string name, string bday, string bmonth, string byear, string phonenum, string login, string password, string dbname);
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
    string lp;
    string lpread;
    ofstream regist;
};



#endif // PERSON_H
