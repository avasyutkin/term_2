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

class DataBase
{
public:
    DataBase();
    DataBase(string tableName);
    void usertovector(string tableName);
    void changepass();
    DataBase search(string k, string v);
    void push_back(ffile item);
    ~DataBase();
    void exit();
private:
    string _tableName;
    vector <ffile> user;
};


#endif // DATABASE_H
