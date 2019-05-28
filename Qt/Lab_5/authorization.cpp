#include "authorization.h"
#include "ui_authorization.h"
#include "registration.h"

authorization::authorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
}

authorization::~authorization()
{
    delete ui;
}

void authorization::on_pushButton_2_clicked()
{
    this->close();
    registration *reg = new registration();
    reg->show();
}
