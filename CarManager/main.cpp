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
#include<iomanip>
#include<sstream>
#include<fstream>
using namespace std;
#include"Time.h"
#include<functional>
template<typename T>
void func(list<vector<T>> vector) {
	for (const auto piece : vector) {
		for (const auto item : piece) {
			cout << '|' << setiosflags(ios::right) << setw(15) << item;

		}
		cout << endl;
	}
}
int main(){
	CsvReader kinds("../车辆分类信息表.csv",'\t');
	CsvReader basic("../车辆基本信息表.csv",'\t');
	CsvReader rent("../租车订单信息表.csv", '\t');


	string s;
	int branch;
	int help;
	std::map<int , CsvReader> map;
	stringstream ss;
	auto f = []()->void {};
	std::map<int, std::function<void()> > filter;


	cout << "Please Chose the Info you want to : ";
	cin >> branch;
	map.insert(make_pair(1, kinds));
	map.insert(make_pair(2, basic));
	map.insert(make_pair(3, rent));

	auto temp = map[branch];
	Info info(temp.title, temp.data);
	//vector<string> titles=temp.GetTitle();


	auto showAll = [&temp]()->void {
		cout << endl;
		temp.ShowData();
	};

	//show the available car
	auto searchAvailable = [&info]()->void{
		string n = "n";
		func(info.Search(6, n, false));
	};
	//find the car you prefer in 车辆基本信息表.csv and input the
	auto searchWith = [&temp, &info, &s]()->void
	{
		cout << "Input the car you want to: ,if you want to query many,input index with space,end with -1" << endl;
		for (auto it = temp.title.begin(); it != temp.title.end(); it++) {
			cout << it - temp.title.begin() << ". " << *it << endl;
		}

		//choose the column you want to query
		vector<int> mul;
		int a;
		while (cin >> a && a != -1) {
			mul.push_back(a);
		}

		cout << "Please input the info you want to query like this: " << endl;
		for (auto item : mul) {
			auto t = temp.GetData().front();
			cout << t[item] << ends;
		}
		cout << endl;

		//input the query info
		cin >> s;
		cout << "Result:---------------------------------" << endl;
		func(info.Search(mul[0], s, false));

	};

	filter.emplace(11, showAll);
	filter.emplace(21, showAll);
	filter.emplace(31, showAll);
	filter.emplace(32, searchAvailable);
	

	cout << "input the following index to refer what you want to do :" << endl;
	cout << "1. Show all infomation: " << endl;
	cout << "2. Find the Available Car: " << endl;
	cout << "3. Find available certain Car: " << endl;
	cin >> help;
	filter[10 * branch + help]();
}