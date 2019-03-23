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

Person::~Person()
{

}

