#include "writejournal.h"
#include "driver.h"
#include <QMessageBox>
#include "ui_writejournal.h"

using namespace std;

WriteJournal::WriteJournal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WriteJournal)
{
    ui->setupUi(this);
    DataBase a;
    a.cartovector("car");
    for(int i = 0; i < a.getCarSize(); i++)
        ui->autoo->addItem(QString::fromLocal8Bit(a.getCarModel(i).c_str()));
}

WriteJournal::~WriteJournal()
{
    delete ui;
}

void WriteJournal::on_pushButton_clicked()
{
    DataBase a;
    a.cartovector("car");
    for(int i = 0; i < a.getCarSize(); i++)
    {
        QString j = QString::fromLocal8Bit(a.getCarModel(i).c_str());
        if(ui->autoo->currentText() == j)
            carmodel = j;
    }

    a.usertovector("commondb");
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    date.toString("dd.MM.yyyy");
    time.toString("hh/mm");
    QString Date = date.toString("dd.MM.yyyy");
    QString Time = time.toString("hh/mm");
    Driver driver;
    driver.writejournal(QString::fromLocal8Bit(a.returnID().c_str()), carmodel, QString::fromLocal8Bit(a.SearchNameByID().c_str()), Date, Time);
    QMessageBox::information(this, "Успешно", "Запись в журнал осуществлена. Счастливого пути!");
    close();
    delete this;
}
