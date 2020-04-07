#include<iostream>
#include<fstream>
#include<sstream>
#include<regex>
#include<string>
#include<chrono>
#include<map>
using namespace std;
using namespace chrono;
int main() {
	auto start = system_clock::now();

	fstream file("fullevent.xls");
	ofstream outfile("1.txt");
	string s;
	smatch result;
	string line = "^(\\d{1,2})\t(?!Huskies)(\\w+)\\t";
	regex r(line);
	map<string, vector<string>> dic;
	getline(file, s);

	int i = 0;
	while (getline(file, s)&&i<10) {
		regex_search(s, result, r);
		if (!result.empty()) {
			auto& nos = dic[result[2]];
			nos.push_back(s);
		}
		i++;
	}

	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "time cost: "
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "s" << endl; return 0;
}