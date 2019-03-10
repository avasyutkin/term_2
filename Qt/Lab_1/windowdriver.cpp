#include "windowdriver.h"
#include "ui_windowdriver.h"

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
