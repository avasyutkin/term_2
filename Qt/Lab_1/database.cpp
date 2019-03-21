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
            cout << token << endl; //токен
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

void DB_Test1::fileToVector()
{
    ifstream streamF("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\"+_tableName+".txt", ios::app);

    if(!streamF){exit(1);
    }

    while(!streamF.eof())
    {
        string str, token;

        getline(streamF, str); //строка
        cout << str << endl;

        Test1 item; //запись таблицы

        int k = 0;
        istringstream streamS(str);

        while(getline(streamS, token, ':')){
            //cout << token << endl; //токен
            if(k == 0) item.id = stoi(token);
            if(k == 1) item.name = token;
            if(k == 2) item.year = stoi(token);
            if(k == 3) item.address = token;
            k++;
        }

        _db.push_back(item);
    }
    //streamF.close();
}

DB_Test1::DB_Test1()
{

}

DB_Test1::DB_Test1(string tableName)
{
    _tableName = tableName;
    fileToVector();
}

void DB_Test1::push_back(Test1 item)
{
    _db.push_back(item);
}

DB_Test1 DB_Test1::search(string k, int v){ //тип значения поля - int
    DB_Test1 select;
    for (unsigned i = 0; i < _db.size(); i++){
        Test1 item = _db.at(i);

        if(k == "id" && item.id == v){
            select.push_back(item);
            cout << item.name << ":" << item.year << endl;
        }

        if(k == "year" && item.year == v){
            select.push_back(item);
            cout << item.name << ":" << item.year << endl;
        }
    }
    return select;
}

DB_Test1 DB_Test1::search(string k, string v){ //тип значения поля - string
    DB_Test1 select;
    for (unsigned i = 0; i < _db.size(); i++){
        Test1 item = _db.at(i);

        if(k == "name" && item.name == v){
            select.push_back(item);
            cout << item.name << ":" << item.year << endl;
        }

        if(k == "address" && item.address == v){
            select.push_back(item);
            cout << item.name << ":" << item.year << endl;
        }
    }
    return select;
}

DB_Test2::DB_Test2(string tableName){
    _tableName = tableName;
    fileToVector();
}

DB_Test2::DB_Test2()
{

}

void DB_Test2::fileToVector(){
    ifstream streamF("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\"+_tableName+".txt", ios::app);

    if(!streamF){exit(1);}

    while(!streamF.eof()){
        string str, token;

        getline(streamF, str); //строка
        cout << str << endl;

        Test2 item; //запись таблицы

        int k = 0;
        istringstream streamS(str);

        while(getline(streamS, token, ':')){
            //cout << token << endl; //токен
            if(k == 0) item.id = stoi(token);
            if(k == 1) item.name = token;
            if(k == 2) item.year = token;
            if(k == 3) item.address = token;
            k++;
        }

        _db.push_back(item);
    }
    //streamF.close();
}

DataBase::~DataBase()
{

}

void DataBase::exit()
{
    user.clear();
}
