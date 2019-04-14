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
}

WriteJournal::~WriteJournal()
{
    delete ui;
}

void WriteJournal::on_pushButton_clicked()
{
    carmodel=ui->lineEdit->text();
    DataBase a;
    a.usertovector("commondb");
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    date.toString("dd.MM.yyyy");
    time.toString("hh/mm");
    QString Date = date.toString("dd.MM.yyyy");
    QString Time = time.toString("hh/mm");

    Driver driver;
    if (carmodel.size() == 0)
        QMessageBox::warning(this, "Ошибка", "Введите марку автомобиля, на котором хотите отправиться в рейс.");
    else
    {
        driver.writejournal(QString::fromLocal8Bit(a.returnID().c_str()), carmodel, QString::fromLocal8Bit(a.SearchNameByID().c_str()), Date, Time);
        QMessageBox::information(this, "Успешно", "Запись в журнал осуществлена. Счастливого пути!");
        close();
        delete this;
    }
}
