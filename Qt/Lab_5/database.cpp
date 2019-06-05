#include "database.h"

DataBase::DataBase()
{

}

void DataBase::DataBaseConnect()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("std-mysql");
    database.setUserName("std_829");
    database.setPassword("Understand56");
    database.setDatabaseName("std_829");
    database.open();
}

void DataBase::AddUser(QString login, QString password, QString name, QString post)
{
    QSqlQuery database;
    database.prepare("INSERT INTO car_base_users (User, Password, Name, Post) "
                     "VALUES (?, ?, ?, ?)");
    database.addBindValue(login);
    database.addBindValue(password);
    database.addBindValue(name);
    database.addBindValue(post);
    database.exec();
}

bool DataBase::SameUser(QString name)
{
    // QString ;
    QSqlQuery database;
    //qDebug() << database.exec("SELECT User, User FROM car_base_users WHERE User = :login");
    //database.bindValue(":username", User);
    // database.bindValue(":password", password);
    database.exec("SELECT User, User FROM car_base_users");
    while (database.next()) {
        QString name_from_database = database.value(1).toString();
        //while ()
        if (name == name_from_database)
        {
            return 0;
            break;
        }
        else
            return 1;
    }
}
