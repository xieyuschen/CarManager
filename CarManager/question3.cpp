#include<iostream>
#include<fstream>
#include<sstream>
#include<regex>
#include<string>
#include<chrono>
#include<vector>
using namespace std;
using namespace chrono;
int main() {
	auto start = system_clock::now();

	fstream file("fullevent.xls");
	ofstream outfile("1.txt");
	string s;

	getline(file, s);
	smatch result;
	vector<string> vec;
	string line = "^(\\d{1,2})\t(?=Huskies)";
	regex r(line);
	while (getline(file, s))
	{
		regex_search(s, result, r);
		if (!result.empty())
			outfile << s << endl;
	}

	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "»¨·ÑÁË"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "Ãë" << endl; return 0;
}