#include "person.h"
#include <QCoreApplication>
#include "database.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <QMessageBox>

using namespace std;

Person::Person()
{

}

/*Person::Person(QString info)
{
    QStringList _user = info.split(":", QString::SkipEmptyParts);
    for(int i=0; i<5; i++)
    {
        user.push_back(_user[i].toUtf8().constData());
    }
}*/


/*void Person::usertovector(string _tablename)
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
*/
void Person::reg(string name, string bday, string bmonth, string byear, string phonenum, string login, string password, string dbname)
{
    lp = login+":"+password+"^"+dbname+". "+name+":"+bday+"/"+bmonth+"/"+byear+":"+phonenum+"\n";
    regist.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\autorize.txt", ios::app);
    regist<<lp;
    regist.close();
    lp=login+":"+password+":"+name+":"+bday+"/"+bmonth+"/"+byear+":"+phonenum+"\n";
    regist.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\"+dbname+".txt", ios::app);
    regist<<lp;
    regist.close();
}

/*Person::Person(string tableName)
{
    _tableName=tableName;
    usertovector(_tableName);
}
*/
Person::~Person()
{

}

