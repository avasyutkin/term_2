#ifndef NEWAUTO_H
#define NEWAUTO_H

#include <QDialog>

namespace Ui {
class NewAuto;
}

class NewAuto : public QDialog
{
    Q_OBJECT

public:
    explicit NewAuto(QWidget *parent = nullptr);
    ~NewAuto();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::NewAuto *ui;
    QString newcar;
        QString password;
};

#endif // NEWAUTO_H
