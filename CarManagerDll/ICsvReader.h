#pragma once
#ifdef CSVREADERDLL_EXPORTS
#define CsvReader_API __declspec(dllexport)
#else
#define CsvReader_API __declspec(dllimport)
#endif // CSVREADERDLL_EXPORT

#include<string>
#include<vector>
#include<list>
#include<iostream>
using namespace std;
namespace CarManagerCommon
{
	class ICsvReader
	{
	public:
		//virtual size_t GetColumnnum()=0;
		////返回vector<string> 的列标题
		//virtual vector<string> GetTitle()=0;
		////返回数据表列数
		//virtual list<vector<string>> GetData()=0;
		//virtual void UpdateFile()=0;
		//virtual void ShowData()=0;
		virtual void TestFunction()=0;
	};

}


