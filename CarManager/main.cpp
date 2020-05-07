#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include"CsvReader.h"
#include"Info.h"
#include<Windows.h>
#include<regex>
#include<map>
#include<fstream>
using namespace std;
#include"Time.h"

int main(){
	
	CsvReader kinds("../车辆分类信息表.csv",'\t');
	CsvReader basic("../车辆基本信息表.csv",'\t');
	CsvReader rent("../租车订单信息表.csv", '\t');
	string s;
	cout << "Please Chose the Info you want to : ";
	cin >> s;
	std::map<string, CsvReader> map;
	map.insert(make_pair("1", kinds));
	map.insert(make_pair("2", basic));
	map.insert(make_pair("3", rent));
	auto temp = map[s];
	vector<string> titles=temp.GetTitle();
	cout << "Input the index of the project you want to :" << endl;
	auto beg = titles.begin();
	for (auto it = beg; it != titles.end(); it++) {
		cout << it - beg << ". " << *it << endl;
	}
	cout << "input the following index to refer what you want to do :" << endl;
	cout << "1. Show all infomation: " << endl;
	cout << "2. Find the Available Car: " << endl;
	cout << "3. Find available certain Car: " << endl;
	cin >> s;
	if (s == "1") {
		cout << endl;
		temp.ShowData();
	}
	else if (s == "2") {
		Info info(temp.title,temp.data);
		string n = "n";
		for (auto a : info.Search(6, n, false)) {
			for (auto i : a) {
				cout << i << ends;
			}
			cout << endl;
		}
	}
}