#include "verification.h"
#include "ui_verification.h"
#include <QMessageBox>

Verification::Verification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Verification)
{
    ui->setupUi(this);
}

Verification::~Verification()
{
    delete ui;
}

void Verification::on_pushButton_clicked()
{
    password = ui->lineEdit->text();
    DataBase a;
    string _password = password.toLocal8Bit().constData();
    if(a.Confirm(_password))
    {
        bool b = 0;
        a.vrfnnull();
        a.changevrfc(b);
        QMessageBox::information(this, "Успешно", "Действие подтверждено.");
        this->close();
        delete this;
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Попробуйте  заново ввести пароль.");
        ui->lineEdit->clear();
    }
}
