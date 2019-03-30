#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration.h"
#include "iostream"
#include "fstream"
#include "admin.h"
#include "driver.h"
#include "database.h"
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    login=ui->login->text();
    password=ui->password->text();
    lp = login + ":" + password;
    string _lp = lp.toUtf8().constData();
    autorize.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\autorize.txt");
    while (getline(autorize, lpread))
    {
        if(getline(autorize, lpread, '.'))
        {
            if(lpread==_lp+"^admin")
            {

                hide();
                DataBase user;
                user.chlongpass(_lp);
                admin = new WindowAdmin(this);
                Admin userA("commondb");
                admin -> show();
                autorize.close();
                break;
            }
            if(lpread==_lp+"^driver")
            {
                hide();
                DataBase user;
                user.chlongpass(_lp);
                driver = new WindowDriver(this);
                Driver userD("driver");
                driver -> show();
                autorize.close();
                break;
            }
        }
        else if(autorize.eof())
        {
            hide();
            QMessageBox::warning(this, "Ошибка", "Попробуйте ввести заново Ваш логин и пароль.");
            autorize.close();
            ui->login->clear();
            ui->password->clear();
            this -> show();
        }
    }
}
