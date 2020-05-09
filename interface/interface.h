#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include"Info.h"

QT_BEGIN_NAMESPACE
namespace Ui { class interface; }
QT_END_NAMESPACE

class interface : public QMainWindow
{
    Q_OBJECT

public:
    interface(Info info,QWidget *parent = nullptr);
    ~interface();

private slots:
    void on_pushButton_clicked();

private:
    Ui::interface *ui;
    Info info;
};
#endif // INTERFACE_H
