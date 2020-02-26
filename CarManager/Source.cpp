#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include"DataConvert.h"
#include"Info.h"
using namespace std;
int main() {
	string file("1.csv");
	DataConvert demo(file);
	Info table(demo.title, demo.data);
	std::string a("AA");
	auto item = table.Search(1, a, true);
	for (auto piece : item) {
		for (auto a : piece)
			cout << a << ends;
		cout << endl;

	}

}