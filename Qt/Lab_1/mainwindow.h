#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "iostream"
#include "fstream"
#include "windowadmin.h"
#include "windowdriver.h"
#include "database.h"
#include "person.h"
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <string>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString id;
    QString login;
    QString password;
    QString name;
    QString lp;
    string lpread;
    ifstream autorize;
    WindowAdmin *admin;
    WindowDriver *driver;
    DataBase *ID;
    string getID(DataBase *ID);
};

#endif // MAINWINDOW_H
