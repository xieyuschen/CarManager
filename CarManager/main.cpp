#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include"CsvReader.h"
#include"Info.h"
#include<Windows.h>
#include<regex>
#include<fstream>
using namespace std;
#include"Time.h"

int main(){
	
	CsvReader kinds("../车辆分类信息表.csv",'\t');
	CsvReader basic("../车辆基本信息表.csv");
	CsvReader rent("../租车订单信息表.csv");
	string s;
	cout << "Please Chose the Info you want to : ";
	cin >> s;
	if (s == "1") {
		vector<string> titles(kinds.GetTitle());
		cout << "Input the index of the project you want to :"<< endl;
		auto beg = titles.begin();
		for(auto it = beg; it != titles.end(); it++) {
			cout << it - beg << ". " << *it << endl;
		}
	}
	while (cin >> s) {

	}
	

}