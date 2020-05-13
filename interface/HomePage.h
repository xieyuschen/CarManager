#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<memory>
#include"interface.h"
namespace Ui {
class MainWindow;
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
