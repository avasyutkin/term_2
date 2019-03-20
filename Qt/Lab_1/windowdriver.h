#ifndef WINDOWDRIVER_H
#define WINDOWDRIVER_H

#include <QDialog>
#include "driver.h"
#include <string>
#include "writejournal.h"

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

private:
    Ui::WindowDriver *ui;
    WriteJournal *driver;
    //registration *win;
};

#endif // WINDOWDRIVER_H
