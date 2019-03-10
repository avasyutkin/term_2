#ifndef WINDOWADMIN_H
#define WINDOWADMIN_H

#include <QDialog>

namespace Ui {
class WindowAdmin;
}

class WindowAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit WindowAdmin(QWidget *parent = nullptr);
    ~WindowAdmin();

private:
    Ui::WindowAdmin *ui;
};

#endif // WINDOWADMIN_H
