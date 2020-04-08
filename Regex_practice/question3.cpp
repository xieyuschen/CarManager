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
	ofstream outfile("HuskiesPlayer.xls");
	string s;

	getline(file, s);
	smatch result;
	map<string, set<string>> dic;
	string line = "^(\\d{1,2})\t.*\t(Huskies_\\w\\d{1,2})";
	regex r(line);
	while (getline(file, s))
	{
		regex_search(s, result, r);
		if (!result.empty())
		{
			auto& nos = dic[result[2]];
			nos.insert(result[1]);
		}
	}
	for (auto it = dic.begin(); it != dic.end(); ++it) {
		outfile << it->first << "\t" << it->second.size() << endl;
	}
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "»¨·ÑÁË"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "Ãë" << endl; return 0;
}