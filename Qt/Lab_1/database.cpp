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
            if(k == 0) item.id = token;
            if(k == 1) item.login = token;
            if(k == 2) item.password = token;
            if(k == 3) item.position = token;
            if(k == 4) item.name = token;
            if(k == 5) item.date = token;
            if(k == 6) item.numberphone = token;
            k++;
        }
        if(!item.id[0] || !item.login[0] || !item.password[0] || !item.position[0] || !item.name[0] || !item.date[0] || !item.numberphone[0])
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
            UserS <<QString::fromLocal8Bit(user.at(i).id.c_str()) << ":" << QString::fromLocal8Bit(user.at(i).login.c_str()) << ':' << QString::fromLocal8Bit(user.at(i).password.c_str()) << ':' << QString::fromLocal8Bit(user.at(i).position.c_str()) << ':' << QString::fromLocal8Bit(user.at(i).name.c_str()) << ':' << QString::fromLocal8Bit(user.at(i).date.c_str()) << ':' << QString::fromLocal8Bit(user.at(i).numberphone.c_str()) << "\r\n";
        User.close();
    }
}

void DataBase::cartovector(string _tableName)
{
    ifstream file;
    string dbname=_tableName;
    file.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\"+dbname+".txt", ios::app);
    while(!file.eof())
    {
        string str, token;
        getline(file, str);
        car item;

        int k = 0;
        istringstream fileS(str);

        while(getline(fileS, token, ':'))
        {
            if(k == 0) item.autocar = token;
            if(k == 1) item.carnum = token;

            k++;
        }
        if(!item.autocar[0] || !item.carnum[0])
            break;
        else
            carvector.push_back(item);
    }
    file.close();
}

void DataBase::vectortocar(string _tableName)
{
    QString dbname = QString::fromLocal8Bit(_tableName.c_str());
    QFile User("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\"+dbname+".txt");
    if (User.open(QIODevice::WriteOnly))
    {
        QTextStream UserS(&User);
        for (unsigned i = 0; i < carvector.size(); i++)
            UserS <<QString::fromLocal8Bit(carvector.at(i).autocar.c_str()) << ":" << QString::fromLocal8Bit(carvector.at(i).carnum.c_str()) << "\r\n";
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

string DataBase::getJournalSearchID(string v)
{
    for (unsigned i = 0; i < user.size(); i++)
        if(user.at(i).name == v)
            return user.at(i).id;
}

string DataBase::getSearchCarByID(string i, int a)
{
    int _i = -1;
    for (unsigned ii = 0; ii < journaal.size(); ii++)
    {
        if(journaal.at(ii).driver == i)
            _i++;
        if (a == _i)
            return journaal.at(ii).carmodel;
    }
}

string DataBase::getSearchCarDateByID(string i, int a)
{
    int _i = -1;
    for (unsigned ii = 0; ii < journaal.size(); ii++){
        if(journaal.at(ii).driver == i)
            _i++;
        if (a == _i)
            return journaal.at(ii).date;
    }
}

    string DataBase::getSearchCarTimeByID(string i, int a)
    {
        int _i = -1;
        for (unsigned ii = 0; ii < journaal.size(); ii++){
            if(journaal.at(ii).driver == i)
                _i++;
            if (a == _i)
                return journaal.at(ii).date;
        }
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

string DataBase::getCarModel(int i)
{
    return carvector.at(i).autocar;
}

string DataBase::getCarNum(int i)
{
    return carvector.at(i).carnum;
}

int DataBase::getCarSize()
{
    return carvector.size();
}

int DataBase::getMyJournalCarSize(string id)
{
    int a = 0;
    for (unsigned i = 0; i<journaal.size(); i++)
    {
        if (journaal.at(i).driver == user.at(i).name+"("+id+")")
            a++;
    }
    return a;
}

void DataBase::addNewCar(string newcar)
{
    string a;
    int idd = 0;
    ifstream commondb;
    commondb.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\car.txt");
    while (getline(commondb, a,'\n'))
        idd++;
    idd = idd+1;
    QString id = QString::number(idd);
    QString _newcar = QString::fromLocal8Bit(newcar.c_str());
    QString lp = _newcar+":"+id+"\n";
    QFile regist("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\car.txt");
    regist.open(QIODevice::Append);
    QTextStream registS(&regist);
    registS<<lp;
    regist.close();
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

string DataBase::getJournalUserID(int i)
{
    return user.at(i).id;
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

string DataBase::ID;

string DataBase::returnID()
{
    return ID;
}

void DataBase::changeID(string _ID)
{
    ID = _ID;
}

string DataBase::SearchNameByID()
{
    for (unsigned i = 0; i < user.size(); i++)
        if(user.at(i).id == returnID())
            return user.at(i).name;
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
    for(unsigned i=0; i<user.size(); i++)
    {
        if (a == "login" && rlongpass()==(user.at(i).login+":"+user.at(i).password))
            user.at(i).login=newpasss;
        if (a == "password" && rlongpass()==(user.at(i).login+":"+user.at(i).password))
            user.at(i).password=newpasss;
    }
}

bool DataBase::registsamelp(string lp)
{
    for(unsigned i=0; i<user.size(); i++)
    {
        if (lp==(user.at(i).login+":"+user.at(i).password))
            return 1;
        else
            return 0;
    }
}

bool DataBase::Confirm(string password)
{
    DataBase pass;
    pass.usertovector("commondb");
    if (pass.getpass("password")==password)
        return 1;
    else
        return 0;
}
bool DataBase::vrfc;

bool DataBase::returnvrfc()
{
    return vrfc;
}

void DataBase::vrfnnull()
{
    vrfc = 0;
}

void DataBase::changevrfc(bool v)
{
    vrfc = 0;
    if(v == 0)
        vrfc = 1;
    else if (v == 1)
        vrfc = 0;
}
