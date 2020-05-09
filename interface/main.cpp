#include "interface.h"

#include <QApplication>
#include<QFileDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QString fileName = QFileDialog::getOpenFileName();
    QString fileName="E:\\Code\\CarManager\\车辆基本信息表.csv";
    CsvReader reader(fileName,'\t');

    Info info(reader.title,reader.data);
    interface w(info);
    w.show();
    return a.exec();
}
