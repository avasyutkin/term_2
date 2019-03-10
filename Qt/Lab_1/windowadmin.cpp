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
