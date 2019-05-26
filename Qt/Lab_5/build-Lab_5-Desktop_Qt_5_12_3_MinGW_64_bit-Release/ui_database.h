/********************************************************************************
** Form generated from reading UI file 'database.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_H
#define UI_DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataBase
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DataBase)
    {
        if (DataBase->objectName().isEmpty())
            DataBase->setObjectName(QString::fromUtf8("DataBase"));
        DataBase->resize(400, 300);
        centralWidget = new QWidget(DataBase);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 130, 80, 21));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 200, 113, 21));
        DataBase->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DataBase);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DataBase->setStatusBar(statusBar);

        retranslateUi(DataBase);

        QMetaObject::connectSlotsByName(DataBase);
    } // setupUi

    void retranslateUi(QMainWindow *DataBase)
    {
        DataBase->setWindowTitle(QApplication::translate("DataBase", "DataBase", nullptr));
        pushButton->setText(QApplication::translate("DataBase", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataBase: public Ui_DataBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_H
