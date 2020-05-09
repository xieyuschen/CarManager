#ifndef DATACONVERT_H
#define DATACONVERT_H

#include<string>
#include<vector>
#include<list>
#include<iostream>
#include<QString>
using namespace std;
class CsvReader
{
public:
    CsvReader(QString,QChar);
    CsvReader(QString);
    CsvReader() :title(NULL), data(NULL),column(0){};
    ~CsvReader();
    CsvReader(CsvReader&& d) noexcept{
        title = std::move(d.title);
        data = std::move(d.data);
        column = std::move(d.column);
    }
    CsvReader(const CsvReader& d) {
        title = d.title;
        column = d.column;
        data = d.data;
    }
    size_t GetColumnnum();
//    vector<QString> GetTitle();
//    list<vector<QString>> GetData();
    vector<QString> title;
    list<vector<QString>> data;

private:
    size_t column;
    QString filename;
};

#endif // DATACONVERT_H

