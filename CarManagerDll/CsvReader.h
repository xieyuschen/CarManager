#pragma once
#ifdef CSVREADERDLL_EXPORT
#define CsvReader_API __declspec(dllexport)
#else
#define CsvReader_API __declspec(dllimport)
#endif // CSVREADERDLL_EXPORT

#include<string>
#include<vector>
#include<list>
#include<iostream>
using namespace std;
//===========================================
//此类用于处理.csv文件
//接受string文件名，将csv文件中数据处理为一个对象
//对象中存储了此csv表中的列表，以及每行的内容
namespace CarManagerCommon 
{
	class CsvReader
	{
	public:
		CsvReader(string, char);
		CsvReader(string);
		CsvReader() :title(NULL), data(NULL), column(0) {};
		~CsvReader();
		CsvReader(CsvReader&& d) noexcept {
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
		//返回vector<string> 的列标题
		vector<string> GetTitle();
		//返回数据表列数
		list<vector<string>> GetData();
		void UpdateFile();
		void ShowData();
		vector<string> title;
		list<vector<string>> data;

		static void TestFunction();
	private:

		size_t column;
		string filename;
	};

}


