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
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WindowDriver
{
public:
    QLabel *label;

    void setupUi(QDialog *WindowDriver)
    {
        if (WindowDriver->objectName().isEmpty())
            WindowDriver->setObjectName(QString::fromUtf8("WindowDriver"));
        WindowDriver->resize(400, 300);
        label = new QLabel(WindowDriver);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 140, 47, 13));

        retranslateUi(WindowDriver);

        QMetaObject::connectSlotsByName(WindowDriver);
    } // setupUi

    void retranslateUi(QDialog *WindowDriver)
    {
        WindowDriver->setWindowTitle(QApplication::translate("WindowDriver", "Dialog", nullptr));
        label->setText(QApplication::translate("WindowDriver", "\320\277\321\200\320\270\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowDriver: public Ui_WindowDriver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWDRIVER_H
