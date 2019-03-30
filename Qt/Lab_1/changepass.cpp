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

void ChangePass::on_pushButton_clicked()
{
    oldpass=ui->oldpass->text();
    newpass=ui->newpass->text();
    newpass2=ui->newpass3->text();

    string _oldpass=oldpass.toUtf8().constData();
    string _newpass=newpass.toUtf8().constData();
    string _newpass2=newpass2.toUtf8().constData();

    DataBase passsss;
    passsss.usertovector("commondb");
    if (_oldpass.size()!=0 && _newpass.size()!=0 && _newpass2.size()!=0)
    {
        if (_oldpass==_newpass)
            QMessageBox::warning(this, "Ошибка", "Старый и новый пароли не должны совпадать.");
        else if(passsss.getpass()==_oldpass && _newpass==_newpass2)
        {
            passsss.changepass(_newpass);
            passsss.vectortouser("commondb");
            QMessageBox::information(this, "Успешно", "Вы сменили пароль.");
        }
        else if (passsss.getpass()!=_oldpass)
            QMessageBox::warning(this, "Ошибка", "Старый пароль введен неверно.");
        else
            QMessageBox::warning(this, "Ошибка", "Пароли не совпадают.");
    }
    else
        QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
}

void ChangePass::on_pushButton_2_clicked()
{
    this->hide();
}
