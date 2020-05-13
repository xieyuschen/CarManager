#include "HomePage.h"
#include "ui_mainwindow.h"
#include"interface.h"
#include<memory>
HomePage::HomePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_pushButton_clicked()
{
    this->setVisible(false);
    QString fileName="E:\\Code\\CarManager\\车辆基本信息表.csv";
    CsvReader reader(fileName,'\t');
    Info info(reader.title,reader.data);
    interface* inter=new interface(info,this);
    inter->show();
}
