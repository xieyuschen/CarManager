#pragma once
#ifdef INFODLL_EXPORT
#define Info_API __declspec(dllexport)
#else
#define Info_API __declspec(dllimport)
#endif 


#include<string>
#include<vector>
#include<list>
#include<iostream>
#include"CsvReader.h"
#include<fstream>
#include"Time.h"
using namespace CarManagerTypes;
namespace CarManagerCommon{
	class Info
	{
	public:
		using piece = std::vector<string>;
	public:
		Info(const piece&, const list<piece>&);
		~Info();
		void Add(piece t);
		//list<piece>  Search(int,const string&);
		list<piece>  Search(int, const string&, bool);
		//查询发生在时间范围内的记录
		list<piece>  Search(Time, Time);
		void Delete();
		void Create();
	private:
		piece title;
		list<piece> data;
	};

}



