#include<iostream>
#include<fstream>
#include<sstream>
#include<regex>
#include<string>
#include<chrono>
#include<vector>
#include<set>
#include<map>
using namespace std;
using namespace chrono;
int main() {
	auto start = system_clock::now();

	fstream file("passingevents.xls");
	ofstream outfile("PlayerOper.xls");
	string s;

	getline(file, s);
	smatch result;
	map<pair<string,string>, int> dic;
	string line = "^(\\w*\t){2}(Huskies_\\w\\d{1,2})\t(\\w*[_|.]?\\w*\t){3}(\\w* \\w*)\t";
	regex r(line);
	while (getline(file, s))
	{
		regex_search(s, result, r);
		if (!result.empty())
		{
			auto& nos = dic[pair<string,string>(result[2],result[4])];
			++nos;
		}
	}
	for (auto it = dic.begin(); it != dic.end(); ++it) {
		outfile << it->first.first << "\t" <<it->first.second<< "\t" << it->second << endl;
	}
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "Time cost: "
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "s" << endl; return 0;
}