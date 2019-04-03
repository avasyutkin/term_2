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
#include <sstream>
#include <cstdlib>

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
    autorize.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\commondb.txt");
    while(!autorize.eof())
    {
        string str, token;
        getline(autorize, str);
        ffile item;
        int k = 0;
        istringstream fileS(str);
        while(getline(fileS, token, ':'))
        {
            if(k == 0) item.login = token;
            if(k == 1) item.password = token;
            if(k == 2) item.position = token;
            if(k == 3) item.name = token;
            if(k == 4) item.date = token;
            if(k == 5) item.numberphone = token;
            k++;
            lpread = item.login+':'+item.password+':'+item.position;
        }
        if(lpread==_lp+":21232f297a57a5a743894a0e4a801fc3")
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
        if(lpread==_lp+":e2d45d57c7e2941b65c6ccd64af4223e")
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

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    registration *reg = new registration(this);
    reg->show();
}
