#ifndef WINDOWDRIVER_H
#define WINDOWDRIVER_H

#include <QDialog>

namespace Ui {
class WindowDriver;
}

class WindowDriver : public QDialog
{
    Q_OBJECT

public:
    explicit WindowDriver(QWidget *parent = nullptr);
    ~WindowDriver();

private:
    Ui::WindowDriver *ui;
};

#endif // WINDOWDRIVER_H
