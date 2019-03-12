#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "iostream"
#include "fstream"
#include "windowadmin.h"
#include "windowdriver.h"
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

private:
    Ui::MainWindow *ui;
    QString login;
    QString password;
    QString lp;
    string lpread;
    ifstream autorize;
    WindowAdmin *admin;
    WindowDriver *driver;
};


#endif // MAINWINDOW_H
