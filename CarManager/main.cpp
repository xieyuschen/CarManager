#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include"CsvReader.h"
#include"Info.h"
#include<Windows.h>
#include<regex>
using namespace std;
int main() {
	//这里的序号是子正则式的序号
	string fmt = "$2.$6.$8";
	//这里单斜杠都要写成双斜杠，进行转义
	string phone = "(\\()?(\\d{3})(\\))?([-|. ])?(\\s)?(\\d{3})([-|.])?(\\d{4})";
	regex r(phone);
	string s;
 	
	while (getline(cin, s)) {
		cout << regex_replace(s, r, fmt)<<endl;
	}
	return 0;
}

//string test = "dog hello cat car target";
//regex r("^car");
//smatch results;
//regex_search(test, results, r);
//cout << results.str();


//	string file("1.csv");
//	CsvReader demo(file);
//	Info table(demo.title, demo.data);
//	auto item = table.Search("2019/02/15-12:00", "2019/02/15-14:00");
//	for (auto piece : item) {
//		for (auto a : piece)
//			cout << a << ends;
//		cout << endl;
//
//	}
//
//}