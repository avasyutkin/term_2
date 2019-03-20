#ifndef WINDOWADMIN_H
#define WINDOWADMIN_H

#include <QDialog>
#include "database.h"
#include "person.h"

namespace Ui {
class WindowAdmin;
}

class WindowAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit WindowAdmin(QWidget *parent = nullptr);
    ~WindowAdmin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::WindowAdmin *ui;
    //registration *windows;
};

#endif // WINDOWADMIN_H
