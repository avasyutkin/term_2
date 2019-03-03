#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>

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
    if (login == loginin && password == passwordin)
    {
        QMessageBox::information(this, "Успешно", "Вы авторизовались.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Проверьте введнные данные.");
    }
}
