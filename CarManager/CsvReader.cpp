#include<string>
#include<vector>
#include<list>
#include"CsvReader.h"
#include<fstream>
#include<sstream>
CsvReader::CsvReader(string _filename)
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
CsvReader::~CsvReader()
{
}
size_t  CsvReader::GetColumnnum() {
	return column;
}
vector<string> CsvReader::GetTitle() {
	return title;
}
list<vector<string>> CsvReader::GetData() {
	return data;
}
void CsvReader::UpdateFile() {
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

