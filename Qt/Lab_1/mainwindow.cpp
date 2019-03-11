#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "fstream"
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
    autorize.open("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\autorize.txt", ios::in);

 while (getline(autorize, lpread))
    {
     if(lpread==_lp)
     {
         QMessageBox::information(this, "Успешно", "Вы авторизовались.");
         break;
     }
     else if(autorize.eof())
     {
         QMessageBox::information(this, "Неверно", "Проверьте введенные данные.");
     }
    }
}
