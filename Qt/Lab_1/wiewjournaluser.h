#ifndef WIEWJOURNALUSER_H
#define WIEWJOURNALUSER_H

#include <QDialog>
#include "QStandardItemModel"
#include "QStandardItem"
#include "database.h"

using namespace std;

namespace Ui {
class WiewJournalUser;
}

class WiewJournalUser : public QDialog
{
    Q_OBJECT

public:
    explicit WiewJournalUser(QWidget *parent = nullptr);
    ~WiewJournalUser();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::WiewJournalUser *ui;
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    QStringList horizontalHeader;
    QString person;
};

#endif // WIEWJOURNALUSER_H
