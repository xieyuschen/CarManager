#include "interface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CsvReader reader("E:\\Code\\CarManager\\车辆基本信息表.txt");

    Info info(reader.title,reader.data);
    interface w(info);
    w.show();
    return a.exec();
}
