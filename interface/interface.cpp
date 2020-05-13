#include "interface.h"
#include "ui_interface.h"
#include"ui_mainwindow.h"
#include<QTextStream>
#include<QFileDialog>
interface::interface(Info _info,QWidget *parent)
    :QMainWindow(parent)
    , ui(new Ui::interface)
    ,info(_info)
    ,parent(parent)
{
    ui->setupUi(this);
    ui->lineEdit->setVisible(false);
    ui->linelable->setVisible(false);
    ui->checkBox->setVisible(false);
}

interface::~interface()
{
    delete ui;
}


void interface::on_pushButton_clicked()
{
    //QString fileName = QFileDialog::getOpenFileName();
    auto index=ui->comboBox->currentIndex();

    switch (index) {
    case 0:
        ui->text->setPlainText(func(info.Search(6,"n",false)).replace('\t',"sad"));
        break;
    case 1:
        auto linetext=ui->lineEdit->text();
        ui->text->setPlainText(func(info.Search(1,linetext,ui->checkBox->isChecked())));
        break;
    }

}


void interface::on_comboBox_activated(int index)
{
    switch(index){
    case 0:
        ui->lineEdit->setVisible(false);
        ui->linelable->setVisible(false);
        ui->checkBox->setVisible(false);
        break;
    case 1:
        ui->lineEdit->setVisible(true);
        ui->linelable->setVisible(true);
        ui->checkBox->setVisible(true);
        break;
    }
}

void interface::on_pushButton_2_clicked()
{
    setVisible(false);
    parent->setVisible(true);
}
