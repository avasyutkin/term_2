#ifndef DEPARTUREJOURNAL_H
#define DEPARTUREJOURNAL_H

#include <QDialog>

namespace Ui {
class DepartureJournal;
}

class DepartureJournal : public QDialog
{
    Q_OBJECT

public:
    explicit DepartureJournal(QWidget *parent = nullptr);
    ~DepartureJournal();

private:
    Ui::DepartureJournal *ui;
};

#endif // DEPARTUREJOURNAL_H
