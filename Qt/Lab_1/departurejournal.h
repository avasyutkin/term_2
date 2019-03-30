#ifndef DEPARTUREJOURNAL_H
#define DEPARTUREJOURNAL_H

#include <QDialog>
#include "QStandardItemModel"
#include "QStandardItem"
#include "database.h"

using namespace std;

namespace Ui {
class DepartureJournal;
}

class DepartureJournal : public QDialog
{
    Q_OBJECT

public:
    explicit DepartureJournal(QWidget *parent = nullptr);
    ~DepartureJournal();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();

private:
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    QStringList horizontalHeader;
    Ui::DepartureJournal *ui;    
};

#endif // DEPARTUREJOURNAL_H
