/********************************************************************************
** Form generated from reading UI file 'windowadmin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWADMIN_H
#define UI_WINDOWADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowAdmin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;

    void setupUi(QDialog *WindowAdmin)
    {
        if (WindowAdmin->objectName().isEmpty())
            WindowAdmin->setObjectName(QString::fromUtf8("WindowAdmin"));
        WindowAdmin->resize(372, 193);
        layoutWidget = new QWidget(WindowAdmin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 351, 162));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout_2->addWidget(pushButton_5);


        retranslateUi(WindowAdmin);

        QMetaObject::connectSlotsByName(WindowAdmin);
    } // setupUi

    void retranslateUi(QDialog *WindowAdmin)
    {
        WindowAdmin->setWindowTitle(QApplication::translate("WindowAdmin", "Dialog", nullptr));
        label->setText(QApplication::translate("WindowAdmin", "\320\227\320\264\321\200\320\260\320\262\321\201\321\202\320\262\321\203\320\271\321\202\320\265! \320\222\321\213 \320\264\320\276\320\261\320\270\320\273\320\270\321\201\321\214 \320\274\320\275\320\276\320\263\320\276\320\263\320\276, \320\222\321\213 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200 \320\264\320\260\320\275\320\275\320\276\320\271 \321\204\320\270\321\200\320\274\321\213.", nullptr));
        pushButton->setText(QApplication::translate("WindowAdmin", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \320\262\320\276\320\264\320\270\321\202\320\265\320\273\320\265\320\271", nullptr));
        pushButton_2->setText(QApplication::translate("WindowAdmin", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\266\321\203\321\200\320\275\320\260\320\273 \320\262\321\213\320\265\320\267\320\264\320\260", nullptr));
        pushButton_4->setText(QApplication::translate("WindowAdmin", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\273\320\276\320\263\320\270\320\275 \320\270 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton_3->setText(QApplication::translate("WindowAdmin", "\320\243\320\262\320\276\320\273\320\270\321\202\321\214 \320\262\321\201\320\265\321\205", nullptr));
        pushButton_5->setText(QApplication::translate("WindowAdmin", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowAdmin: public Ui_WindowAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWADMIN_H
