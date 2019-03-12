#include "registration.h"
#include "ui_registration.h"
#include "mainwindow.h"
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
    login=ui->login->text();
    password=ui->password->text();
    regist.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\autorize.txt", ios::app);

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked())
    {
         QMessageBox::warning(this, "Ошибка", "Нельзя быть администраторм и водителем одновременно.");
    }

    else if(ui->checkBox->isChecked())
    {
        if(name.size()!=0 && login.size()!=0 && password.size()!=0)
        {
            lp=login+":"+password+"^admin. "+name+"\n";
            string _lp = lp.toUtf8().constData();
            regist<<_lp;
            regist.close();
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
        if(name.size()!=0 && login.size()!=0 && password.size()!=0)
        {
            lp=login+":"+password+"^admin. "+name+"\n";
            string _lp = lp.toUtf8().constData();
            regist<<_lp;
            regist.close();
            hide();
            driver=new WindowDriver(this);
            driver->show();
        }
        else
        {
            regist.close();
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
