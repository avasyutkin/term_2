#include "departurejournal.h"
#include "ui_departurejournal.h"

DepartureJournal::DepartureJournal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepartureJournal)
{
    ui->setupUi(this);
}

DepartureJournal::~DepartureJournal()
{
    delete ui;
}
