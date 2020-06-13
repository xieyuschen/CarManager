#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<Windows.h>
#include<regex>
#include<map>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<list>
#include"Info.h"
#include"CsvReader.h"
#include"TimeMe.h"
#include<functional>
using namespace std;
using namespace CarManagerCommon;
using namespace CarManagerTypes;
template<typename T>
void func(list<vector<T>> vector) {
	for (const auto piece : vector) {
		for (const auto item : piece) {
			cout << '|' << setiosflags(ios::right) << setw(15) << item;

		}
		cout << endl;
	}
}
typedef CarManagerCommon::CsvReader* (__cdecl* CsvFactory)();
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
	map.insert(make_pair(1, kinds));
	map.insert(make_pair(2, basic));
	map.insert(make_pair(3, rent));
	while (true) {
		cout << "Please Chose the Info you want to : " << endl;
		cout << "1. 车辆分类信息" << endl;
		cout << "2. 车辆基本信息" << endl;
		cout << "3. 租车订单信息" << endl;
		cin >> branch;
		if (branch == -2)break;
		auto temp = map[branch];
		Info info(temp.title, temp.data);

		//x:1,show all table infomation 
		auto showAll = [&temp]()->void {
			cout << endl;
			temp.ShowData();
		};

		//1:2,find the certain car type
		auto findTypeLeft = [&temp, &info]()->void {
			cout << "Input the Car Type you want to book as follows:" << endl;
			string a;
			cin >> a;
			auto t = info.Search(1, a, false);
			func(t);
		};
		//2:2,show the available car
		auto searchAvailable = [&info]()->void {
			string n = "n";
			func(info.Search(6, n, false));
		};
		//2:3,find the car you prefer in 车辆基本信息表.csv and input the
		auto searchWitharg = [&temp, &info, &s]()->void
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
		filter.emplace(12, findTypeLeft);
		filter.emplace(21, showAll);
		filter.emplace(22, searchAvailable);
		filter.emplace(23, searchWitharg);
		filter.emplace(31, showAll);

		cout << "input the following index to refer what you want to do :" << endl;
		cout << "1. Show all infomation: " << endl;
		cout << "2. Find the Available Car: " << endl;
		cout << "3. Find available certain Car: " << endl;
		cin >> help;
		if (help == -2)break;
		filter[10 * branch + help]();
		cout <<"\n\n\n\n";
		cout << "------------------------------------------------" << endl;
		cout << "\n\n\n\n";

	}

}