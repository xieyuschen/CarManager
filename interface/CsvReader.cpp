#include<string>
#include<vector>
#include<list>
#include"CsvReader.h"
#include<fstream>
#include<QFile>
#include<sstream>
#include <QTextStream>
using namespace std;
CsvReader::CsvReader(QString _filename, QChar split=',')
{
	filename = _filename;
    QString temp;

    QFile file(_filename);
    QTextStream in(&file);

	string line;
	int flag = 0;
    vector<QString> vec;
    while (in.atEnd())
	{
        temp=in.readLine();
		if (!flag++)
		{
            for(auto item:temp.split(split))
            title.push_back(item);
		}
		else
		{
            vec.clear();
            for(auto item:temp.split(split))
                vec.push_back(temp);
			data.push_back(vec);
		}
	}
	column = title.size();
}
CsvReader::CsvReader(QString _filename)
	:CsvReader(_filename,',')
{
	
}
CsvReader::~CsvReader()
{
}
size_t  CsvReader::GetColumnnum() {
	return column;
}
//std::vector<QString> CsvReader::GetTitle() {
//	return title;
//}
//list<vector<QString>> CsvReader::GetData() {
//	return data;
//}


