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
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interface
{
public:
    QWidget *centralwidget;
    QTextBrowser *text;
    QToolBox *toolBox;
    QWidget *page_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QCheckBox *checkBox;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QWidget *page_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *interface)
    {
        if (interface->objectName().isEmpty())
            interface->setObjectName(QString::fromUtf8("interface"));
        interface->resize(800, 600);
        centralwidget = new QWidget(interface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        text = new QTextBrowser(centralwidget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(400, 100, 256, 192));
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(60, 90, 301, 371));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 301, 313));
        pushButton = new QPushButton(page_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 210, 93, 28));
        lineEdit = new QLineEdit(page_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(110, 120, 113, 21));
        label = new QLabel(page_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 72, 15));
        checkBox = new QCheckBox(page_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(110, 170, 91, 19));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 120, 72, 15));
        comboBox = new QComboBox(page_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 50, 87, 22));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 50, 71, 21));
        toolBox->addItem(page_3, QString::fromUtf8("Page 1"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 301, 313));
        toolBox->addItem(page_4, QString::fromUtf8("Page 2"));
        interface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(interface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        interface->setMenuBar(menubar);
        statusbar = new QStatusBar(interface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        interface->setStatusBar(statusbar);

        retranslateUi(interface);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(interface);
    } // setupUi

    void retranslateUi(QMainWindow *interface)
    {
        interface->setWindowTitle(QCoreApplication::translate("interface", "interface", nullptr));
        pushButton->setText(QCoreApplication::translate("interface", "Find", nullptr));
        label->setText(QCoreApplication::translate("interface", "Project:", nullptr));
        checkBox->setText(QCoreApplication::translate("interface", "Crystic", nullptr));
        label_2->setText(QCoreApplication::translate("interface", "Keyword", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("interface", "\346\237\245\350\257\242", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("interface", "\345\217\257\347\224\250\350\275\246\350\276\206", nullptr));

        label_3->setText(QCoreApplication::translate("interface", "\346\237\245\350\257\242\351\200\211\351\241\271", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("interface", "Page 1", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("interface", "Page 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interface: public Ui_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
