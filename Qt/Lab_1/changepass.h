#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include <QDialog>
#include "iostream"
#include "fstream"
#include <QFile>
#include <QString>
#include <string>
#include "vector"

using namespace std;

namespace Ui {
class ChangePass;
}

class ChangePass : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePass(QWidget *parent = nullptr);
    ~ChangePass();
    string getpass(string pass);
    //void changepass(string );

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChangePass *ui;
    QString oldpass;
    QString newpass;
    QString newpass2;
};

#endif // CHANGEPASS_H
