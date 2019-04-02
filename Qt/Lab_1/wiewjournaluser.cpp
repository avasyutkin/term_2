#include "wiewjournaluser.h"
#include "ui_wiewjournaluser.h"
#include "database.h"
#include <QString>

WiewJournalUser::WiewJournalUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WiewJournalUser)
{
    ui->setupUi(this);
    string aaa="commondb";
    DataBase user;
    user.usertovector(aaa);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Водитель" << "Дата рождения" << "Номер телефона");
    ui->tableWidget->setRowCount(user.getJournalUserSize());
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *a = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserName(i).c_str()));
        QTableWidgetItem *b = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserDate(i).c_str()));
        QTableWidgetItem *c = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserPhonenumber(i).c_str()));

        ui->tableWidget->setItem(i, 0, a);
        ui->tableWidget->setItem(i, 1, b);
        ui->tableWidget->setItem(i, 2, c);
    };
}

WiewJournalUser::~WiewJournalUser()
{
    delete ui;
}

void WiewJournalUser::on_pushButton_clicked()
{
    ui->tableWidget->clear();
    person=ui->lineEdit->text();
    ui->lineEdit->clear();
    string _person=person.toUtf8().constData();
    string aaa="commondb";
    DataBase user;
    user.usertovector(aaa);
    //user.search(_person);
    ui->pushButton->setDisabled(0);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Водитель" << "Дата рождения" << "Номер телефона");
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *a = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserName(i).c_str()));
        QTableWidgetItem *b = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserDate(i).c_str()));
        QTableWidgetItem *c = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserPhonenumber(i).c_str()));

        ui->tableWidget->setItem(i, 0, a);
        ui->tableWidget->setItem(i, 1, b);
        ui->tableWidget->setItem(i, 2, c);
    };

}

void WiewJournalUser::on_pushButton_2_clicked()
{
    this->hide();
}
