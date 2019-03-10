/********************************************************************************
** Form generated from reading UI file 'windowdriver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWDRIVER_H
#define UI_WINDOWDRIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_WindowDriver
{
public:

    void setupUi(QDialog *WindowDriver)
    {
        if (WindowDriver->objectName().isEmpty())
            WindowDriver->setObjectName(QString::fromUtf8("WindowDriver"));
        WindowDriver->resize(400, 300);

        retranslateUi(WindowDriver);

        QMetaObject::connectSlotsByName(WindowDriver);
    } // setupUi

    void retranslateUi(QDialog *WindowDriver)
    {
        WindowDriver->setWindowTitle(QApplication::translate("WindowDriver", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowDriver: public Ui_WindowDriver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWDRIVER_H
