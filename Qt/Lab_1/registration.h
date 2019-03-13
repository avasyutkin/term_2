#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "iostream"
#include "fstream"
#include "mainwindow.h"
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <string>

using namespace std;

namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::registration *ui;
    MainWindow *autorization;
    QString login;
    QString password;
    QString name;
    QString lp;
    string lpread;
    ofstream regist;
    ofstream registadmin;
    ofstream registdriver;
    WindowAdmin *admin;
    WindowDriver *driver;
};

#endif // REGISTRATION_H