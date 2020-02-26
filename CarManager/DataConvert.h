#ifndef DATACONVERT_H
#define DATACONVERT_H

#include<string>
#include<vector>
#include<list>
#include<iostream>
using namespace std;
//===========================================
//此类用于处理.csv文件
//接受string文件名，将csv文件中数据处理为一个对象
//对象中存储了此csv表中的列表，以及每行的内容
class DataConvert
{
public:
	DataConvert(string);
	DataConvert() :title(NULL), data(NULL),column(0){};
	~DataConvert();
	DataConvert(DataConvert&& d) noexcept{
		title = std::move(d.title);
		data = std::move(d.data);
		column = std::move(d.column);
	}
	DataConvert(const DataConvert& d) {
		title = d.title;
		column = d.column;
		data = d.data;
	}
	size_t GetColumnnum();
	//返回vector<string> 的列标题
	vector<string> GetTitle();	
	//返回数据表列数
	list<vector<string>> GetData();
	void UpdateFile();

	vector<string> title;
	list<vector<string>> data;
private:

	size_t column;
	string filename;
};

#endif // DATACONVERT_H

