#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include "authorization.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::registration *ui;
    authorization *autorization;
    QString login;
    QString password;
    QString name;
    QString post;
};

#endif // REGISTRATION_H
