#include<iostream>
#include<fstream>
#include<sstream>
#include<regex>
#include<string>
#include<chrono>
using namespace std;
using namespace chrono;
int main() {
	auto start = system_clock::now();
	
	fstream file("fullevent.xls");
	ofstream outfile("1.txt");
	string s;
	string line = "(\\d{1,2})\tHuskies.*\\t";
	regex r(line);
	smatch result;
//==================================================
	//第一种方法
	while (getline(file, s))
	{
		regex_search(s, result, r);
		if (!result.empty())
			outfile << result.str() << endl;
	}
//==================================================
	//第二种方法
	std::ostringstream tmp;
	tmp << file.rdbuf();
	s = tmp.str();
	for (sregex_iterator it(s.begin(), s.end(), r), end; it != end; ++it) {
		outfile << it->str() << endl;
	}
//==================================================

	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl; return 0;
}