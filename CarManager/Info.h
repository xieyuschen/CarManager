
#ifndef INFO_H
#define INFO_H

#include<string>
#include<vector>
#include<list>
#include<iostream>
#include"CsvReader.h"
#include<fstream>

class Info
{
public:
	using piece = std::vector<string>;
public:
	Info(piece&,list<piece>&);
	~Info();
	void Add(piece t);
	list<piece>  Search(int,const string&);
	list<piece>  Search(int ,const string&, bool);
	//查询发生在时间范围内的记录
	list<piece> Search(const string& starttime,const string& endtime);
	void Delete(); 
	void Create();
private:
	piece title;
	list<piece> data;
};


#endif // INFO_H
