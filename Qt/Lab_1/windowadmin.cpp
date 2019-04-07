#include "windowadmin.h"
#include "ui_windowadmin.h"
#include "database.h"
#include <QMessageBox>
#include <QWidget>
#include <QDialog>

WindowAdmin::WindowAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowAdmin)
{
    ui->setupUi(this);
}

WindowAdmin::~WindowAdmin()
{
    delete ui;
}

void WindowAdmin::on_pushButton_clicked()
{
    jaurnol = new WiewJournalUser(this);
    jaurnol->show();
}

void WindowAdmin::on_pushButton_2_clicked()
{
    journol = new DepartureJournal(this);
    journol->show();

}

void WindowAdmin::on_pushButton_5_clicked()
{
    close();
    DataBase a;
    a.exit();
    delete this;
}

void WindowAdmin::on_pushButton_4_clicked()
{
    windoww=new ChangePass(this);
    windoww->show();
}

void WindowAdmin::on_pushButton_3_clicked()
{
    int button = QMessageBox::question(this,
                                       QString ("Подтверждение увольнения"),
                                       QString ("ВЫ УВЕРЕНЫ, ЧТО ХОТИТЕ УВОЛИТЬ ВСЕХ СОТРУДНИКОВ? ДАННОЕ ДЕЙСТВИЕ НЕЛЬЗЯ ОТМЕНИТЬ.\r\nПодтверждая данное действие вы соглашаетесь с тем, что больше не будете директором данной компании."),
                                       QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes)
    {
        QMessageBox::information(this, "Игра окончена", "Ваша компания скоро обанкротится.");

        QFile fileall("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\commondb.txt");
        fileall.remove();
        QFile fileall1("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\admin.txt");
        fileall1.remove();
        QFile fileall2("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\driver.txt");
        fileall2.remove();
        QFile fileall3("E:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_1\\departurejournal.txt");
        fileall3.remove();
        this->close();

    }
    else
        QMessageBox::information(this, "Поздравляем", "Вы очень умны, Вы не дали обанкротиться Вашей компании.");
}
