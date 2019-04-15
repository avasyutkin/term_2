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
#include <QDate>

using namespace std;
registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    QDate date = QDate::currentDate();
    date.toString("yyyy");
    QString Date = date.toString("yyyy");
    int ddate = Date.toInt();
    for(int i = 1950; i < (ddate-18); i++)
    {
        QString j = QString::number(i);
        ui->year->addItem(j);
    }
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()
{
    name=ui->name->text();
    phonenum=ui->phonenum->text();
    bday=ui->day->currentText();
    bmonth=ui->month->currentText();
    login=ui->login->text();
    password=ui->password->text();

    QDate date = QDate::currentDate();
    date.toString("yyyy");
    QString Date = date.toString("yyyy");
    int ddate = Date.toInt();
    for(int i = 1950; i < (ddate-18); i++)
    {
        QString j = QString::number(i);
        if(ui->year->currentText() == j)
            byear = j;
    }

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked())
    {
        QMessageBox::warning(this, "Ошибка", "Нельзя быть администраторм и водителем одновременно.");
    }

    else if(ui->checkBox->isChecked())
    {
        if(name.size()!=0 && login.size()!=0 && password.size()!=0 && phonenum.size()!=0)
        {
            string a;
            int idd = 0;
            ifstream commondb;
            commondb.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\commondb.txt");
            while (getline(commondb, a,'\n'))
                idd++;
            idd = idd+1;
            QString id = QString::number(idd);
            Admin _admin;
            DataBase userr;
            QString ab = login+":"+password;
            string _ab = ab.toLocal8Bit().constData();
            if(!userr.registsamelp(_ab))
            {
                _admin.reg(id, name, bday, bmonth, byear, phonenum, login, password, "21232f297a57a5a743894a0e4a801fc3", "admin");
                Admin usera(string commondb);
                hide();
                QMessageBox::information(this, "Успешно", "Вы зарегистрировались в системе, теперь войдите в свой аккаунт.");
                autorization = new MainWindow(this);
                autorization -> show();
            }
            else
                QMessageBox::warning(this, "Ошибка", "Пользователь с таким логином и паролем уже зарегистрирован в системе.");

        }
        else
        {
            regist.close();
            QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
        }
    }

    else if(ui->checkBox_2->isChecked())
    {
        if(name.size()!=0 && login.size()!=0 && password.size()!=0 &&  bday.size()!=0 && bmonth.size()!=0 && byear.size()!=0 && phonenum.size()!=0)
        {
            string a;
            int idd = 0;
            ifstream commondb;
            commondb.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\commondb.txt");
            while (getline(commondb, a,'\n'))
                idd++;
            idd = idd+1;
            QString id = QString::number(idd);
            Driver _driver;
            DataBase userr;
            QString ab = login+":"+password;
            string _ab = ab.toLocal8Bit().constData();
            if(!userr.registsamelp(_ab))
            {
                _driver.reg(id, name, bday, bmonth, byear, phonenum, login, password, "e2d45d57c7e2941b65c6ccd64af4223e", "driver");
                Driver userd(string driver);
                hide();
                QMessageBox::information(this, "Успешно", "Вы зарегистрировались в системе, теперь войдите в свой аккаунт.");
                autorization = new MainWindow(this);
                autorization -> show();
            }
            else
                QMessageBox::warning(this, "Ошибка", "Пользователь с таким логином и паролем уже зарегистрирован в системе.");
        }
        else
        {
            QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
        }
    }
}
void registration::on_pushButton_2_clicked()
{
    close();
    autorization = new MainWindow(this);
    autorization -> show();
}

void registration::on_checkBox_stateChanged(int arg1)
{

}
