#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <QDialog>
#include "iostream"
#include "fstream"
#include <QFile>
#include <QString>
#include <string>
#include "vector"
#include "string.h"
#include "database.h"

using namespace std;

namespace Ui {
class Verification;
}

class Verification : public QDialog
{
    Q_OBJECT

public:
    explicit Verification(QWidget *parent = nullptr);
    ~Verification();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Verification *ui;
    QString password;
};

#endif // VERIFICATION_H
