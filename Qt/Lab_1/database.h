#ifndef DATABASE_H
#define DATABASE_H

#include "iostream"
#include "fstream"
#include <QFile>
#include <QString>
#include <string>
#include "vector"

using namespace std;

struct ffile{
    string login; //0
    string password; //2
    string name; //1
    string date; //3
    string numberphone; //4
};

/*struct Test1{
    int id; //0
    int year; //2
    string name; //1
    string address; //3
};

struct Test2{
    int id;
    string year;
    string name;
    string address;
};*/

class DataBase
{
public:
    DataBase();
    void usertovector(string tableName);
    void changepass();
    ~DataBase();
private:
    string _tableName;
    vector <ffile> user;
};
/*
class DB_Test1{
private:
    string _tableName;
    vector<Test1> user;
public:
    DB_Test1(){}
    DB_Test1(string tableName);
    void push_back(Test1 item);
};

class DB_Test2{
private:
    string _tableName;
    vector<Test2> user;
public:
    DB_Test2(){}
    DB_Test2(string tableName);
};
*/
#endif // DATABASE_H
