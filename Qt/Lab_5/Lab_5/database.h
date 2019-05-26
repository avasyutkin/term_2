#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QString>


struct user
{
    QString login;
    QString password;
    QString name;
    QString post;
};


class DataBase
{
public:
    DataBase();
    void DataBaseConnect();
    void AddUser(QString login, QString password, QString name, QString post);

private:
};

#endif // DATABASE_H
