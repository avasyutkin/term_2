#ifndef MYDEPARTURES_H
#define MYDEPARTURES_H

#include <QDialog>

namespace Ui {
class MyDepartures;
}

class MyDepartures : public QDialog
{
    Q_OBJECT

public:
    explicit MyDepartures(QWidget *parent = nullptr);
    ~MyDepartures();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyDepartures *ui;
};

#endif // MYDEPARTURES_H
