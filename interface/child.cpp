#include "child.h"
#include "ui_child.h"

child::child(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::child)
{
    ui->setupUi(this);
}

child::~child()
{
    delete ui;
}
