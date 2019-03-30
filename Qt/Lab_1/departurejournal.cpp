#include "departurejournal.h"
#include "ui_departurejournal.h"
#include "database.h"

DepartureJournal::DepartureJournal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepartureJournal)
{
    ui->setupUi(this);
    DataBase journal;
    journal.journaltovector();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Автомобиль" << "Водитель" << "Дата" << "Время");
    ui->tableWidget->setRowCount(journal.getJournalSize());
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *a = new QTableWidgetItem(QString::fromLocal8Bit(journal.getJournalCar(i).c_str()));
        QTableWidgetItem *b = new QTableWidgetItem(QString::fromLocal8Bit(journal.getJournalDriver(i).c_str()));
        QTableWidgetItem *c = new QTableWidgetItem(QString::fromLocal8Bit(journal.getJournalDate(i).c_str()));
        QTableWidgetItem *d = new QTableWidgetItem(QString::fromLocal8Bit(journal.getJournalTime(i).c_str()));

        ui->tableWidget->setItem(i, 0, a);
        ui->tableWidget->setItem(i, 1, b);
        ui->tableWidget->setItem(i, 2, c);
        ui->tableWidget->setItem(i, 3, d);

    };
}

DepartureJournal::~DepartureJournal()
{
    delete ui;
}


void DepartureJournal::on_pushButton_4_clicked()
{
    this->hide();
}

void DepartureJournal::on_pushButton_2_clicked()
{
    ui->tableWidget->sortByColumn(1, Qt::SortOrder::AscendingOrder);
    ui->tableWidget->horizontalHeader()->setResizeContentsPrecision(0);

}
