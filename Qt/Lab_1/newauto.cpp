#include "newauto.h"
#include "ui_newauto.h"
#include "database.h"
#include <QString>
#include <QMessageBox>

NewAuto::NewAuto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAuto)
{
    ui->setupUi(this);
    string aaa="car";
    DataBase car;
    car.cartovector(aaa);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Модель автомобиля" << "Регистрационный номер");
    ui->tableWidget->setRowCount(car.getCarSize());
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *a = new QTableWidgetItem(QString::fromLocal8Bit(car.getCarModel(i).c_str()));
        QTableWidgetItem *b = new QTableWidgetItem(QString::fromLocal8Bit(car.getCarNum(i).c_str()));

        ui->tableWidget->setItem(i, 0, a);
        ui->tableWidget->setItem(i, 1, b);
    };
}

NewAuto::~NewAuto()
{
    delete ui;
}

void NewAuto::on_pushButton_2_clicked()
{
    this->close();
    delete this;
}

void NewAuto::on_pushButton_clicked()
{
    newcar = ui->lineEdit->text();
    DataBase car;
    verific = new Verification(this);
    verific->show();
    string _newcar = newcar.toLocal8Bit().constData();;
    if(_newcar.size()==0)
    {
        QMessageBox::warning(this, "Ошибка", "Введите марку машины.");
        return;
    }
    if (_newcar.size()!=0)
    {
        if (car.returnvrfc())
        {
            car.addNewCar(_newcar);
        }
    }
}