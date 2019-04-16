#include "mydepartures.h"
#include "ui_mydepartures.h"
#include "database.h"
#include <QString>

MyDepartures::MyDepartures(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDepartures)
{
    ui->setupUi(this);
    DataBase journal;
    journal.journaltovector();
    DataBase lourn;
    lourn.usertovector("commondb");

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Автомобиль" << "Дата" << "Время");
    ui->tableWidget->setRowCount(journal.getMyJournalCarSize(lourn.returnID(), lourn.SearchNameByID()));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
   {
        QTableWidgetItem *a = new QTableWidgetItem(QString::fromLocal8Bit(journal.getSearchCarByID(lourn.returnID(), lourn.SearchNameByID(), i).c_str()));
        QTableWidgetItem *b = new QTableWidgetItem(QString::fromLocal8Bit(journal.getSearchCarDateByID(lourn.returnID(), lourn.SearchNameByID(), i).c_str()));
        QTableWidgetItem *c = new QTableWidgetItem(QString::fromLocal8Bit(journal.getSearchCarTimeByID(lourn.returnID(), lourn.SearchNameByID(), i).c_str()));

        ui->tableWidget->setItem(i, 0, a);
        ui->tableWidget->setItem(i, 1, b);
        ui->tableWidget->setItem(i, 2, c);
    }
}

MyDepartures::~MyDepartures()
{
    delete ui;
}

void MyDepartures::on_pushButton_clicked()
{
    this->close();
    delete this;
}
