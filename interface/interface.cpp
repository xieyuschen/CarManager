#include "interface.h"
#include "ui_interface.h"
#include<QTextStream>
#include<QFileDialog>
interface::interface(Info _info,QWidget *parent)
    :QMainWindow(parent)
    , ui(new Ui::interface)
    ,info(_info)
{
    ui->setupUi(this);
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
        auto text=ui->lineEdit->text();
        ui->text->setPlainText(func(info.Search(1,text,ui->checkBox->isChecked())));
        break;
    }

}

