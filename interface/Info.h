
#ifndef INFO_H
#define INFO_H

#include<string>
#include<vector>
#include<list>
#include<iostream>
#include"CsvReader.h"
#include<fstream>
#include<sstream>
#include<iomanip>
#include<QApplication>
template <typename T>
QString func(list<vector<T>> vector) {
    QString s{};
    for (const auto piece : vector) {
        for (const auto item : piece) {
            s.append(item);
        }
        s.append('\n');
    }
    return s;
}
class Info
{
public:
    using piece = std::vector<QString>;
public:
	Info(const piece&,const list<piece>&);
	~Info();
	void Add(piece t);
    list<piece>  Search(int ,const QString&, bool);
    //list<piece>  Search(Time,Time);
	void Delete();
	void Create();
private:
	piece title;
	list<piece> data;
};


#endif // INFO_H
