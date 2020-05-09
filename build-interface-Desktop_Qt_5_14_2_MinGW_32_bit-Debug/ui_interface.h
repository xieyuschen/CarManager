/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interface
{
public:
    QWidget *centralwidget;
    QTextBrowser *text;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *interface)
    {
        if (interface->objectName().isEmpty())
            interface->setObjectName(QString::fromUtf8("interface"));
        interface->resize(1059, 600);
        centralwidget = new QWidget(interface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        text = new QTextBrowser(centralwidget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(310, 100, 691, 351));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(130, 160, 161, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 160, 60, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 120, 72, 15));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 210, 56, 21));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(130, 210, 161, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 320, 93, 28));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(130, 260, 91, 19));
        interface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(interface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1059, 26));
        interface->setMenuBar(menubar);
        statusbar = new QStatusBar(interface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        interface->setStatusBar(statusbar);

        retranslateUi(interface);

        QMetaObject::connectSlotsByName(interface);
    } // setupUi

    void retranslateUi(QMainWindow *interface)
    {
        interface->setWindowTitle(QCoreApplication::translate("interface", "interface", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("interface", "\346\237\245\350\257\242", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("interface", "\345\217\257\347\224\250\350\275\246\350\276\206", nullptr));

        label_3->setText(QCoreApplication::translate("interface", "\346\237\245\350\257\242\351\200\211\351\241\271", nullptr));
        label->setText(QCoreApplication::translate("interface", "Project:", nullptr));
        label_2->setText(QCoreApplication::translate("interface", "Keyword", nullptr));
        pushButton->setText(QCoreApplication::translate("interface", "Find", nullptr));
        checkBox->setText(QCoreApplication::translate("interface", "Crystic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interface: public Ui_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
