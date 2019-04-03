#include "changepass.h"
#include "ui_changepass.h"
#include "mainwindow.h"
#include "database.h"
#include "iostream"
#include "string"
#include "fstream"
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

ChangePass::ChangePass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePass)
{
    ui->setupUi(this);
}

ChangePass::~ChangePass()
{
    delete ui;
}

void ChangePass::on_pushButton_2_clicked()
{
    oldpass=ui->oldpass->text();
    newpass=ui->newpass->text();
    newpass2=ui->newpass3->text();
    pass=ui->pass->text();
    oldlogin=ui->oldlogin->text();
    newlogin=ui->newlog->text();

    string _oldpass=oldpass.toUtf8().constData();
    string _newpass=newpass.toUtf8().constData();
    string _newpass2=newpass2.toUtf8().constData();
    string _pass=pass.toUtf8().constData();
    string _oldlogin=oldlogin.toUtf8().constData();
    string _newlogin=newlogin.toUtf8().constData();

    DataBase passsss;
    passsss.usertovector("commondb");
    if (ui->radioButton_2->isChecked())
    {
        if (_oldpass.size()!=0 && _newpass.size()!=0 && _newpass2.size()!=0)
        {
            if (_oldpass==_newpass)
                QMessageBox::warning(this, "Ошибка", "Старый и новый пароли не должны совпадать.");
            else if (passsss.getpass("password")==_oldpass && _newpass==_newpass2)
            {
                passsss.changepass("password", _newpass);
                passsss.vectortouser("commondb");
                QMessageBox::information(this, "Успешно", "Вы сменили пароль.");
                delete this;
            }
            else if (passsss.getpass("password")!=_oldpass)
                QMessageBox::warning(this, "Ошибка", "Старый пароль введен неверно.");
            else
                QMessageBox::warning(this, "Ошибка", "Пароли не совпадают.");
        }
        else
            QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
    }

    if (ui->radioButton->isChecked())
    {
        if (_pass.size()!=0 && _oldlogin.size()!=0 && _newlogin.size()!=0)
        {
            if (_oldlogin==_newlogin)
                QMessageBox::warning(this, "Ошибка", "Старый и новый логины не должны совпадать.");
            else if (passsss.getpass("login")==_oldlogin && _oldlogin!=_newlogin && passsss.getpass("password")==_pass)
            {
                passsss.changepass("login", _newlogin);
                passsss.vectortouser("commondb");
                QMessageBox::information(this, "Успешно", "Вы сменили логин.");
                delete this;
            }
            else if (passsss.getpass("password")!=_pass)
                QMessageBox::information(this, "Ошибка", "Пароль введен неверно.");
            else if (passsss.getpass("login")!=_oldlogin)
                QMessageBox::warning(this, "Ошибка", "Старый логин введен неверно.");
        }
        else
            QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
    }
}

void ChangePass::on_pushButton_clicked()
{
    this->hide();
    delete this;
}

void ChangePass::on_radioButton_2_clicked()
{
    if (ui->radioButton_2->isEnabled())
    {
        ui->pass->setDisabled(1);
        ui->oldlogin->setDisabled(1);
        ui->newlog->setDisabled(1);
        ui->pass->clear();
        ui->oldlogin->clear();
        ui->newlog->clear();
    }
    if (ui->radioButton-isEnabled())
    {
        ui->oldpass->setEnabled(1);
        ui->newpass->setEnabled(1);
        ui->newpass3->setEnabled(1);
    }
}

void ChangePass::on_radioButton_clicked()
{
    if (ui->radioButton->isEnabled())
    {
        ui->oldpass->setDisabled(1);
        ui->newpass->setDisabled(1);
        ui->newpass3->setDisabled(1);
        ui->oldpass->clear();
        ui->newpass->clear();
        ui->newpass3->clear();
    }
    if (ui->radioButton_2->isEnabled())
    {
        ui->pass->setEnabled(1);
        ui->oldlogin->setEnabled(1);
        ui->newlog->setEnabled(1);
    }
}
