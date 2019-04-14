#ifndef WRITEJOURNAL_H
#define WRITEJOURNAL_H

#include <QDialog>
#include "driver.h"
#include <string>
#include <QDate>

namespace Ui {
class WriteJournal;
}

class WriteJournal : public QDialog
{
    Q_OBJECT

public:
    explicit WriteJournal(QWidget *parent = nullptr);
    ~WriteJournal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WriteJournal *ui;
    QString carmodel;
    QString date;
    QString name;
    QString id;
    QTime time;
};

#endif // WRITEJOURNAL_H
