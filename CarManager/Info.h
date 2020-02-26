
#ifndef INFO_H
#define INFO_H

#include<string>
#include<vector>
#include<list>
#include<iostream>
#include"DataConvert.h"
//我先假定用户输入的不可能有错误
class Info
{
public:
	Info(vector<string>&,list<vector<string>>&);
	~Info();
	void Add(vector<string> t);
	list<vector<string>>  Search(int num,string);
	list<vector<string>>  Search(int num, string key, bool cryptic);
	void Delete();
	void Create();
private:
	vector<string> title;
	list<vector<string>> data;
};


#endif // INFO_H
