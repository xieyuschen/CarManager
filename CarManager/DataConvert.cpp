#include<string>
#include<vector>
#include<list>
#include"DataConvert.h"
#include<fstream>
#include<sstream>
DataConvert::DataConvert(string _filename)
{
	filename = _filename;
	ifstream fin(_filename);
	string line;
	int flag = 0;
	while (getline(fin,line))
	{
		string temp;
		istringstream sin(line);
		if (!flag++)
		{
			while (getline(sin, temp, ','))
			{
				title.push_back(temp);
			}
		}
		else
		{
			vector<string> vec;
			while (getline(sin, temp, ','))
			{
				vec.push_back(temp);
			}
			data.push_back(vec);
		}
	}
	column = title.size();
}
DataConvert::~DataConvert()
{
}
size_t  DataConvert::GetColumnnum() {
	return column;
}
vector<string> DataConvert::GetTitle() {
	return title;
}
list<vector<string>> DataConvert::GetData() {
	return data;
}
void DataConvert::UpdateFile() {
	ofstream fout(filename);
	for (auto a : title)
		fout << a << ',';
	fout << endl;
	for (auto piece : data) {
		for (auto item : piece) {
			fout << item << ',';
		}
		fout << endl;
	}

}

