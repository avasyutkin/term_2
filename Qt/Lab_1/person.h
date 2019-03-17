#ifndef PERSON_H
#define PERSON_H

#include "iostream"
#include "fstream"
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <string>
#include "vector"

using namespace std;

class Person
{
public:
    Person();
    void reg(string name, string bday, string bmonth, string byear, string phonenum, string login, string password, string dbname);
    /*Person(string login, string password, string name);

        ifstream strinvec("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\autorize.txt");
        if (!strinvec){exit(1);}
        while (!strinvec.eof())
        {
         string str, token;
         getline(strinvec, str);

        }*/

    //~Person();
    void changelp();
private:
    QString login;
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
