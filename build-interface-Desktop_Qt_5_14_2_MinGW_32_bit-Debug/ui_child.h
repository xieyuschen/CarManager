/********************************************************************************
** Form generated from reading UI file 'child.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILD_H
#define UI_CHILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_child
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *child)
    {
        if (child->objectName().isEmpty())
            child->setObjectName(QString::fromUtf8("child"));
        child->resize(800, 600);
        menubar = new QMenuBar(child);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        child->setMenuBar(menubar);
        centralwidget = new QWidget(child);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        child->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(child);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        child->setStatusBar(statusbar);

        retranslateUi(child);

        QMetaObject::connectSlotsByName(child);
    } // setupUi

    void retranslateUi(QMainWindow *child)
    {
        child->setWindowTitle(QCoreApplication::translate("child", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class child: public Ui_child {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILD_H
