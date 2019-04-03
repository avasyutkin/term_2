#include "database.h"
#include "iostream"
#include "fstream"
#include <QFile>
#include <QString>
#include <string>
#include "vector"
#include <sstream>
#include <cstdlib>
#include <QTextStream>

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
        string str, token;
        getline(file, str);
        ffile item;

        int k = 0;
        istringstream fileS(str);

        while(getline(fileS, token, ':'))
        {
            if(k == 0) item.login = token;
            if(k == 1) item.password = token;
            if(k == 2) item.position = token;
            if(k == 3) item.name = token;
            if(k == 4) item.date = token;
            if(k == 5) item.numberphone = token;
            k++;
        }
        if(!item.login[0] || !item.password[0] || !item.position[0] || !item.name[0] || !item.date[0] || !item.numberphone[0])
            break;
        else
            user.push_back(item);
    }
    file.close();
}

void DataBase::vectortouser(string _tablename){
    QString dbname = QString::fromLocal8Bit(_tablename.c_str());
    QFile User("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\"+dbname+".txt");
    if (User.open(QIODevice::WriteOnly))
    {
        QTextStream UserS(&User);
        for (unsigned i = 0; i < user.size(); i++)
            UserS << QString::fromLocal8Bit(user.at(i).login.c_str()) << ':' << QString::fromLocal8Bit(user.at(i).password.c_str()) << ':' << QString::fromLocal8Bit(user.at(i).position.c_str()) << ':' << QString::fromLocal8Bit(user.at(i).name.c_str()) << ':' << QString::fromLocal8Bit(user.at(i).date.c_str()) << ':' << QString::fromLocal8Bit(user.at(i).numberphone.c_str()) << "\r\n";
        User.close();
    }
}


void DataBase::journaltovector()
{
    ifstream file;
    file.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\departurejournal.txt", ios::app);
    while(!file.eof())
    {
        string token, str;
        getline(file, str);
        journal item;

        int k = 0;
        istringstream fileS(str);

        while(getline(fileS, token, ':'))
        {
            if(k == 0) item.carmodel = token;
            if(k == 1) item.driver = token;
            if(k == 2) item.date = token;
            if(k == 3) item.time = token;
            k++;
        }
        if(!item.carmodel[0] || !item.driver[0] || !item.date[0] || !item.time[0])
            break;
        else
            journaal.push_back(item);
    }
    file.close();
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

DataBase::~DataBase()
{

}

void DataBase::exit()
{
    user.clear();
}

string DataBase::getJournalSearchName(string v)
{
    for (unsigned i = 0; i < user.size(); i++)
        if(user.at(i).name == v)
            return user.at(i).name;
}

string DataBase::getJournalSearchDate(string v)
{
    for (unsigned i = 0; i < user.size(); i++)
        if(user.at(i).name == v)
            return user.at(i).date;
}

int DataBase::getJouralSearchSize(string v)
{
    int a = 0;
    for (unsigned i = 0; i<user.size(); i++)
    {
        if (user.at(i).name == v)
            a++;
    }
    return a;
}

string DataBase::getJournalSearchNump(string v)
{
    for (unsigned i = 0; i < user.size(); i++)
        if(user.at(i).name == v)
            return user.at(i).numberphone;
}

string DataBase::getDJournalSearchDate(string v, int a)
{
    int _i = -1;
    for (unsigned i = 0; i < journaal.size(); i++){
        if(journaal.at(i).date == v)
            _i++;
        if (a == _i)
            return journaal.at(i).date;
    }
}

string DataBase::getDJournalSearchCar(string v, int a)
{
    int _i = -1;
    for (unsigned i = 0; i < journaal.size(); i++){
        if(journaal.at(i).date == v)
            _i++;
        if (a == _i)
            return journaal.at(i).carmodel;
    }
}

string DataBase::getDJournalSearchName(string v, int a)
{
    int _i = -1;
    for (unsigned i = 0; i < journaal.size(); i++){
        if(journaal.at(i).date == v)
            _i++;
        if (a == _i)
            return journaal.at(i).driver;
    }
}

string DataBase::getDJournalSearchTime(string v, int a)
{
    int _i = -1;
    for (unsigned i = 0; i < journaal.size(); i++){
        if(journaal.at(i).date == v)
            _i++;
        if (a == _i)
            return journaal.at(i).time;
    }
}

int DataBase::getDJouralSearchSize(string v)
{
    int a = 0;
    for (unsigned i = 0; i<journaal.size(); i++)
    {
        if (journaal.at(i).date == v)
            a++;
    }
    return a;
}

int DataBase::getJournalSize()
{
    return journaal.size();
}

string DataBase::getJournalCar(int i)
{
    return journaal.at(i).carmodel;
}

string DataBase::getJournalDriver(int i)
{
    return journaal.at(i).driver;
}

string DataBase::getJournalDate(int i)
{
    return journaal.at(i).date;
}

string DataBase::getJournalTime(int i)
{
    return journaal.at(i).time;
}

int DataBase::getJournalUserSize()
{
    return user.size();
}

string DataBase::getJournalUserName(int i)
{
    return user.at(i).name;
}

string DataBase::getJournalUserDate(int i)
{
    return user.at(i).date;
}

string DataBase::getJournalUserPhonenumber(int i)
{
    return user.at(i).numberphone;
}

string DataBase::logpass;

string DataBase::rlongpass()
{
    return logpass;
}

void DataBase::chlongpass(string _logpass)
{
    logpass = _logpass;
}

string DataBase::getpass(string a)
{
    for(unsigned i=0; i<user.size(); i++)
    {
        if (a == "login" && rlongpass()==(user.at(i).login+":"+user.at(i).password))
            return user.at(i).login;
        if (a == "password" && rlongpass()==(user.at(i).login+":"+user.at(i).password))
            return user.at(i).password;
    }
}

void DataBase::changepass(string a, string newpasss)
{
    for(unsigned i=0; i<user.size(); i++){
        if (a == "login" && rlongpass()==(user.at(i).login+":"+user.at(i).password))
            user.at(i).login=newpasss;
        if (a == "password" && rlongpass()==(user.at(i).login+":"+user.at(i).password))
            user.at(i).password=newpasss;
    }
}
