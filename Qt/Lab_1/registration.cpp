#include "registration.h"
#include "ui_registration.h"
#include "mainwindow.h"
#include "person.h"
#include "admin.h"
#include "driver.h"
#include "iostream"
#include "string"
#include "fstream"
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

using namespace std;
registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()
{
    name=ui->name->text();
    phonenum=ui->phonenum->text();
    bday=ui->bday->text();
    bmonth=ui->bmonth->text();
    byear=ui->byear->text();
    login=ui->login->text();
    password=ui->password->text();
    string _name = name.toUtf8().constData();
    string _bday = bday.toUtf8().constData();
    string _bmonth = bmonth.toUtf8().constData();
    string _byear = byear.toUtf8().constData();
    string _phonenum = phonenum.toUtf8().constData();
    string _login = login.toUtf8().constData();
    string _password = password.toUtf8().constData();

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked())
    {
         QMessageBox::warning(this, "Ошибка", "Нельзя быть администраторм и водителем одновременно.");
    }

    else if(ui->checkBox->isChecked())
    {
        if(name.size()!=0 && login.size()!=0 && password.size()!=0 && bday.size()!=0 && bmonth.size()!=0 && byear.size()!=0 && phonenum.size()!=0)
        {

            Admin _admin;
            _admin.reg(_name, _bday, _bmonth, _byear, _phonenum, _login, _password, "admin");
            _admin.reg(_name, _bday, _bmonth, _byear, _phonenum, _login, _password, "commondb");
            Admin usera(string commondb);
            hide();
            admin=new WindowAdmin(this);
            admin->show();

        }
        else
        {
            regist.close();
            QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
        }
    }

    else if(ui->checkBox_2->isChecked())
    {
        if(name.size()!=0 && login.size()!=0 && password.size()!=0 && bday.size()!=0 && bmonth.size()!=0 && byear.size()!=0 && phonenum.size()!=0)
        {
            Driver _driver;
            _driver.reg(_name, _bday, _bmonth, _byear, _phonenum, _login, _password, "driver");
            _driver.reg(_name, _bday, _bmonth, _byear, _phonenum, _login, _password, "commondb");
            Driver userd(string driver);
            hide();
            driver=new WindowDriver(this);
            driver->show();
        }
        else
        {
            QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
        }
    }
}
void registration::on_pushButton_2_clicked()
{
    hide();
    autorization = new MainWindow(this);
    autorization -> show();
}

void registration::on_checkBox_stateChanged(int arg1)
{

}
