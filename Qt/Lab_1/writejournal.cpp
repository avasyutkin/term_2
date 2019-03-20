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
    string _carmodel = carmodel.toUtf8().constData();
    string _name = name.toUtf8().constData();
    string _dateday = dateday.toUtf8().constData();
    string _datemonth = datemonth.toUtf8().constData();
    string _dateyear = dateyear.toUtf8().constData();
    string _timeminute = timeminute.toUtf8().constData();
    string _timehour = timehour.toUtf8().constData();


    Driver driver;
    driver.writejournal(_carmodel, _name, _dateday, _datemonth, _dateyear, _timehour, _timeminute);
    QMessageBox::information(this, "Успешно", "Запись в журнал осуществлена. Счастливого пути!");
    hide();
}
