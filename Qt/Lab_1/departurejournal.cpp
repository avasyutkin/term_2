#include "departurejournal.h"
#include "ui_departurejournal.h"
#include "database.h"
#include <QMessageBox>
#include <QTextStream>

DepartureJournal::DepartureJournal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepartureJournal)
{
    ui->setupUi(this);
    DataBase journal;
    journal.journaltovector();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Автомобиль" << "Водитель(ID)" << "Дата" << "Время");
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
    this->close();
    delete this;
}

void DepartureJournal::on_pushButton_2_clicked()
{
    ui->tableWidget->sortByColumn(1, Qt::SortOrder::AscendingOrder);
    ui->tableWidget->horizontalHeader()->setResizeContentsPrecision(0);
}

void DepartureJournal::on_pushButton_3_clicked()
{
    ui->tableWidget->clear();
    dt = ui->dateEdit->text();
    DataBase journal;
    journal.journaltovector();
    string _dt=dt.toLocal8Bit().constData();

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Автомобиль" << "Водитель(ID)" << "Дата" << "Время");
    ui->tableWidget->setRowCount(journal.getDJouralSearchSize(_dt));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *a = new QTableWidgetItem(QString::fromLocal8Bit(journal.getDJournalSearchCar(_dt, i).c_str()));
        QTableWidgetItem *b = new QTableWidgetItem(QString::fromLocal8Bit(journal.getDJournalSearchName(_dt, i).c_str()));
        QTableWidgetItem *c = new QTableWidgetItem(QString::fromLocal8Bit(journal.getDJournalSearchDate(_dt, i).c_str()));
        QTableWidgetItem *d = new QTableWidgetItem(QString::fromLocal8Bit(journal.getDJournalSearchTime(_dt, i).c_str()));

        ui->tableWidget->setItem(i, 0, a);
        ui->tableWidget->setItem(i, 1, b);
        ui->tableWidget->setItem(i, 2, c);
        ui->tableWidget->setItem(i, 3, d);
    };
}

void DepartureJournal::on_pushButton_clicked()
{
    string car;
    string name;
    string date;
    string time;
    QString a;
    QFile exp("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\exportDepartJournal.txt");
    exp.open(QIODevice::Append | QIODevice::Truncate);
    QTextStream registS(&exp);

    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        car = ui->tableWidget->item(i, 0)->text().toLocal8Bit().constData();
        name = ui->tableWidget->item(i, 1)->text().toLocal8Bit().constData();
        date = ui->tableWidget->item(i, 2)->text().toLocal8Bit().constData();
        time = ui->tableWidget->item(i, 3)->text().toLocal8Bit().constData();

        QString _car = QString::fromLocal8Bit(car.c_str());
        QString _name = QString::fromLocal8Bit(name.c_str());
        QString _date = QString::fromLocal8Bit(date.c_str());
        QString _time = QString::fromLocal8Bit(time.c_str());

        a = _car+":"+_name+":"+_date+":"+_time+"\n";
        registS << a;
    }
    exp.close();
    QMessageBox::information(this, "Успешно", "Данные экспортированы в файл exportDepartJournal.txt.");
}
