#include "windowadmin.h"
#include "ui_windowadmin.h"

WindowAdmin::WindowAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowAdmin)
{
    ui->setupUi(this);
}

WindowAdmin::~WindowAdmin()
{
    delete ui;
}

void WindowAdmin::on_pushButton_clicked()
{

}

void WindowAdmin::on_pushButton_2_clicked()
{
    journol = new DepartureJournal(this);
    journol->show();

}

void WindowAdmin::on_pushButton_5_clicked()
{
    hide();
    DataBase a;
    a.exit();
}
