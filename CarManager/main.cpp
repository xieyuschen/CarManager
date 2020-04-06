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
	string test = "dog hello cat car target";
	regex r("^car");
	smatch results;
	regex_search(test, results, r);
	cout << results.str();
}


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