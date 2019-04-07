#include "windowdriver.h"
#include "ui_windowdriver.h"
#include "driver.h"
#include "writejournal.h"

WindowDriver::WindowDriver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowDriver)
{
    ui->setupUi(this);
}

WindowDriver::~WindowDriver()
{
    delete ui;
}

void WindowDriver::on_pushButton_clicked()
{
    driver = new WriteJournal(this);
    driver->show();
}

void WindowDriver::on_pushButton_3_clicked()
{
    close();
    DataBase a;
    a.exit();
    delete this;
}

void WindowDriver::on_pushButton_2_clicked()
{
    windoww=new ChangePass(this);
    windoww->show();
}
