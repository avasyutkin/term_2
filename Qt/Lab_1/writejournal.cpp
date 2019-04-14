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
    name=ui->lineEdit_2->text();
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    date.toString("dd.MM.yyyy");
    time.toString("hh/mm");
    QString Date = date.toString("dd.MM.yyyy");
    QString Time = time.toString("hh/mm");

    Driver driver;
    if (carmodel.size() == 0 || name.size() == 0 || Time.size() == 0 || Date.size() == 0)
        QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
    else
    {
        driver.writejournal(id, carmodel, name, Date, Time);
        QMessageBox::information(this, "Успешно", "Запись в журнал осуществлена. Счастливого пути!");
        close();
        delete this;
    }
}
