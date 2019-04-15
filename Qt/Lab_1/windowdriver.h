#ifndef WINDOWDRIVER_H
#define WINDOWDRIVER_H

#include <QDialog>
#include "driver.h"
#include <string>
#include "writejournal.h"
#include "changepass.h"
#include "mydepartures.h"

namespace Ui {
class WindowDriver;
}

class WindowDriver : public QDialog
{
    Q_OBJECT

public:
    explicit WindowDriver(QWidget *parent = nullptr);
    ~WindowDriver();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::WindowDriver *ui;
    WriteJournal *driver;
    ChangePass *windoww;
    MyDepartures *mydepart;
};

#endif // WINDOWDRIVER_H
