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
    string position;
};

struct journal{
    string carmodel;
    string driver;
    string date;
    string time;
};

class DataBase
{
    static string logpass;
public:
    DataBase();
    string rlongpass();
    void chlongpass(string _logpass);
    string getpass();
    DataBase(string tableName);
    void usertovector(string tableName);
    void vectortouser(string tableName);
    void changepass(string newpasss);
    DataBase search(string k, string v);
    DataBase searchJournal(string k, string va);
    void push_back(ffile item);
    ~DataBase();
    void exit();
    void journaltovector();
    void journalUsertovector();
    int getJournalSize();
    string getJournalCar(int i);
    string getJournalDriver(int i);
    string getJournalDate(int i);
    string getJournalTime(int i);
    int getJournalUserSize();
    string getJournalUserName(int i);
    string getJournalUserDate(int i);
    string getJournalUserPhonenumber(int i);
private:
    string _tableName;
    vector <ffile> user;
    vector <journal> journaal;
};


#endif // DATABASE_H
