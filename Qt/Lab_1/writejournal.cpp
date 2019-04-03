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
    timehour=ui->lineEdit_3->text();
    timeminute=ui->lineEdit_4->text();
    dateday=ui->lineEdit_5->text();
    datemonth=ui->lineEdit_6->text();
    dateyear=ui->lineEdit_7->text();

    Driver driver;
    if (carmodel.size() == 0 || name.size() == 0 || timehour.size() == 0 || timeminute.size() == 0 || dateday.size() == 0|| datemonth.size() == 0 || dateyear.size() == 0)
        QMessageBox::warning(this, "Ошибка", "Заполните все поля.");
    else
    {
        driver.writejournal(carmodel, name, dateday, datemonth, dateyear, timehour, timeminute);
        QMessageBox::information(this, "Успешно", "Запись в журнал осуществлена. Счастливого пути!");
        close();
        delete this;
    }
}
