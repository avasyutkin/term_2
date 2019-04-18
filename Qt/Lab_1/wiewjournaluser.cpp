#include "wiewjournaluser.h"
#include "ui_wiewjournaluser.h"
#include "database.h"
#include <QString>
#include <QMessageBox>
#include <QTextStream>

WiewJournalUser::WiewJournalUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WiewJournalUser)
{
    ui->setupUi(this);
    string aaa="commondb";
    DataBase user;
    user.usertovector(aaa);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Водитель" << "Дата рождения" << "Номер телефона");
    ui->tableWidget->setRowCount(user.getJournalUserSize());
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *a = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserID(i).c_str()));
        QTableWidgetItem *b = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserName(i).c_str()));
        QTableWidgetItem *c = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserDate(i).c_str()));
        QTableWidgetItem *d = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserPhonenumber(i).c_str()));

        ui->tableWidget->setItem(i, 0, a);
        ui->tableWidget->setItem(i, 1, b);
        ui->tableWidget->setItem(i, 2, c);
        ui->tableWidget->setItem(i, 3, d);
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
    string _person=person.toLocal8Bit().constData();
    string aaa="commondb";
    DataBase user;
    user.usertovector(aaa);
    ui->pushButton->setDisabled(0);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Водитель" << "Дата рождения" << "Номер телефона");
    ui->tableWidget->setRowCount(user.getJouralSearchSize(_person));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    if(user.parse(_person))
    {
        if (user.getJouralSearchSize(_person) != 0)
        {
            QTableWidgetItem *a = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalSearchID(_person).c_str()));
            QTableWidgetItem *b = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalSearchName(_person).c_str()));
            QTableWidgetItem *c = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalSearchDate(_person).c_str()));
            QTableWidgetItem *d = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalSearchNump(_person).c_str()));

            ui->tableWidget->setItem(0, 0, a);
            ui->tableWidget->setItem(0, 1, b);
            ui->tableWidget->setItem(0, 2, c);
            ui->tableWidget->setItem(0, 3, d);
        }
        else if (user.getJouralSearchSize(_person) == 0)
        {
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tableWidget->setColumnCount(4);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Водитель" << "Дата рождения" << "Номер телефона");
            ui->tableWidget->setRowCount(user.getJournalUserSize());
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            for(int i=0; i<ui->tableWidget->rowCount(); i++)
            {
                QTableWidgetItem *a = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserID(i).c_str()));
                QTableWidgetItem *b = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserName(i).c_str()));
                QTableWidgetItem *c = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserDate(i).c_str()));
                QTableWidgetItem *d = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserPhonenumber(i).c_str()));

                ui->tableWidget->setItem(i, 0, a);
                ui->tableWidget->setItem(i, 1, b);
                ui->tableWidget->setItem(i, 2, c);
                ui->tableWidget->setItem(i, 3, d);
            };
            QMessageBox::warning(this, "Ошибка", "Пользователя с таким именем не найдено.");
        }
    }
    else
    {
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Водитель" << "Дата рождения" << "Номер телефона");
        ui->tableWidget->setRowCount(user.getJournalUserSize());
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        for(int i=0; i<ui->tableWidget->rowCount(); i++)
        {
            QTableWidgetItem *a = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserID(i).c_str()));
            QTableWidgetItem *b = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserName(i).c_str()));
            QTableWidgetItem *c = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserDate(i).c_str()));
            QTableWidgetItem *d = new QTableWidgetItem(QString::fromLocal8Bit(user.getJournalUserPhonenumber(i).c_str()));

            ui->tableWidget->setItem(i, 0, a);
            ui->tableWidget->setItem(i, 1, b);
            ui->tableWidget->setItem(i, 2, c);
            ui->tableWidget->setItem(i, 3, d);
        };
        QMessageBox::warning(this, "Ошибка", "Введите корректное имя.");
    }
}

void WiewJournalUser::on_pushButton_2_clicked()
{
    this->close();
    delete this;
}

void WiewJournalUser::on_pushButton_3_clicked()
{
    string id;
    string name;
    string date;
    string phonenum;
    QString a;
    QFile exp("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\exportUserJournal.txt");
    exp.open(QIODevice::Append | QIODevice::Truncate);
    QTextStream registS(&exp);

    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        id = ui->tableWidget->item(i, 0)->text().toLocal8Bit().constData();
        name = ui->tableWidget->item(i, 1)->text().toLocal8Bit().constData();
        date = ui->tableWidget->item(i, 2)->text().toLocal8Bit().constData();
        phonenum = ui->tableWidget->item(i, 3)->text().toLocal8Bit().constData();

        QString _id = QString::fromLocal8Bit(id.c_str());
        QString _name = QString::fromLocal8Bit(name.c_str());
        QString _date = QString::fromLocal8Bit(date.c_str());
        QString _phonenum = QString::fromLocal8Bit(phonenum.c_str());

        a = _id+":"+_name+":"+_date+":"+_phonenum+"\n";
        registS << a;
    }
    exp.close();
    QMessageBox::information(this, "Успешно", "Данные экспортированы в файл exportUserJournal.txt.");
}
