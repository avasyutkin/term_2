#include "database.h"
#include "iostream"
#include "fstream"
#include <QFile>
#include <QString>
#include <string>
#include "vector"
#include <sstream>
#include <cstdlib>

using namespace std;

DataBase::DataBase()
{

}

void DataBase::usertovector(string _tablename)
{
    ifstream file;
    string dbname=_tablename;
    file.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\"+dbname+".txt", ios::app);
    while(!file.eof())
    {
        string token, str;
        getline(file, str);
        ffile item;

        int k = 0;
        istringstream fileS(str);

        while(getline(fileS, token, ':')){
            //cout << token << endl; //токен
            if(k == 0) item.login = token;
            if(k == 1) item.password = token;
            if(k == 2) item.name = token;
            if(k == 3) item.date = token;
            if(k == 4) item.numberphone = token;
            k++;
        }
        user.push_back(item);
    }
    file.close();
}

void DataBase::changepass()
{

}

DataBase::DataBase(string tableName)
{
    _tableName = tableName;
    usertovector(_tableName);
}

void DataBase::push_back(ffile item)
{
    user.push_back(item);
}

DataBase DataBase::search(string k, string v){ //тип значения поля - string
    DataBase select;
    for (unsigned i = 0; i < user.size(); i++){
        ffile item = user.at(i);

        if(k == "name" && item.name == v){
            select.push_back(item);
        }
    }
    return select;
}

DataBase::~DataBase()
{

}

void DataBase::exit()
{
    user.clear();
}
