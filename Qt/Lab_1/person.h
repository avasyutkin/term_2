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

/*struct ffile{
    string login; //0
    string password; //2
    string name; //1
    string date; //3
    string numberphone; //4
};*/

class Person
{
public:
    Person();
    //Person(string tableName);
    //Person(QString info);
    ///void usertovector(string _tableName);
    void reg(string name, string bday, string bmonth, string byear, string phonenum, string login, string password, string dbname);
    //void changelp();
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
   /// string _tableName;
  ////  vector <ffile> user;

};



#endif // PERSON_H
