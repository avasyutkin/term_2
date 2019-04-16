#ifndef DATABASE_H
#define DATABASE_H

#include "iostream"
#include "fstream"
#include <QFile>
#include <QString>
#include <string>
#include "vector"
#include "string.h"

using namespace std;

struct ffile
{
    string id;
    string login;
    string password;
    string name;
    string date;
    string numberphone;
    string position;
};

struct journal
{
    string carmodel;
    string driver;
    string date;
    string time;
};

struct car
{
    string autocar;
    string carnum;
};

class DataBase
{
    static string logpass;
    static string ID;
    static bool vrfc;

public:
    DataBase();
    string rlongpass();
    void chlongpass(string _logpass);
    string getpass(string a);
    DataBase(string tableName);
    void usertovector(string tableName);
    void vectortouser(string tableName);
    void cartovector(string tableName);
    void vectortocar(string tableName);
    void changepass(string a, string newpasss);
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
    string getJournalSearchName(string v);
    string getJournalSearchDate(string v);
    string getJournalSearchNump(string v);
    string getJournalSearchID(string v);
    string getJournalUserID(int i);
    int getJouralSearchSize(string v);
    string getDJournalSearchDate(string v, int a);
    string getDJournalSearchCar(string v, int a);
    string getDJournalSearchName(string v, int a);
    string getDJournalSearchTime(string v, int a);
    int getDJouralSearchSize(string v);
    string returnID();
    string SearchNameByID();
    void changeID(string _ID);
    string getCarModel(int i);
    string getCarNum(int i);
    int getCarSize();
    void addNewCar(string newcar);
    bool Confirm(string password);
    bool returnvrfc();
    void changevrfc(bool v);
    void vrfnnull();
    bool registsamelp(string lp);
    string getSearchCarByID(string i, string name, int a);
    string getSearchCarTimeByID(string i, string name, int a);
    string getSearchCarDateByID(string i, string name, int a);
    int getMyJournalCarSize(string id, string name);
    bool parseNameToInt(string i);

private:
    string _tableName;
    vector <ffile> user;
    vector <journal> journaal;
    vector <car> carvector;
};

#endif // DATABASE_H
