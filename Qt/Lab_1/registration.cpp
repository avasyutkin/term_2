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


    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked())
    {
        QMessageBox::warning(this, "Ошибка", "Нельзя быть администраторм и водителем одновременно.");
    }

    else if(ui->checkBox->isChecked())
    {
        if(name.size()!=0 && login.size()!=0 && password.size()!=0 && bday.size()!=0 && bmonth.size()!=0 && byear.size()!=0 && phonenum.size()!=0)
        {

            Admin _admin;
            _admin.reg(name, bday, bmonth, byear, phonenum, login, password, "21232f297a57a5a743894a0e4a801fc3", "admin");
            Admin usera(string commondb);
            hide();
            QMessageBox::information(this, "Успешно", "Вы зарегистрировались в системе, теперь войдите в свой аккаунт.");
            autorization = new MainWindow(this);
            autorization -> show();

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
            Driver _driver;
            _driver.reg(name, bday, bmonth, byear, phonenum, login, password, "e2d45d57c7e2941b65c6ccd64af4223e", "driver");
            Driver userd(string driver);
            hide();
            QMessageBox::information(this, "Успешно", "Вы зарегистрировались в системе, теперь войдите в свой аккаунт.");
            autorization = new MainWindow(this);
            autorization -> show();
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
