#include "registration.h"
#include "ui_registration.h"
#include "database.h"
#include <QMessageBox>

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    DataBase user;
    user.DataBaseConnect();
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()
{
    name = ui->name->text();
    login = ui->login->text();
    password = ui->password->text();

    DataBase user;
    user.SameUser(login);
    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked())
        QMessageBox::warning(this, "Ошибка", "Нельзя быть администраторм и водителем одновременно.");

    else if(ui->checkBox->isChecked())
    {
        QString post = "Администратор";
        if(name.size()!=0 && login.size()!=0 && password.size()!=0)
        {
            user.AddUser(login, password, name, post);
        }
        else
            QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
    }

    else if(ui->checkBox_2->isChecked())
    {
        QString post = "Водитель";
        if(name.size()!=0 && login.size()!=0 && password.size()!=0)
        {
            user.AddUser(login, password, name, post);
        }
        else
            QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
    }
}

void registration::on_pushButton_2_clicked()
{
    autorization = new authorization();
    autorization -> show();
    close();
}
