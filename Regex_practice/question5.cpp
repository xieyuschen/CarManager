#include<regex>
#include<fstream>
#include<string>
#include<map>
using namespace std;
int main() {
	ifstream infile("passingevents.xls");
	ofstream outfile("passingtimes.xls");
	string s;
	map<pair<string, string>, int> dic;
	smatch results;
	string con = "^\\d*\tHuskies\t(Huskies_\\w*)\t(Huskies_\\w*)";
	regex r(con);
	while (getline(infile, s)) {
		regex_search(s, results, r);
		if (!results.empty()) {
			auto& nos = dic[std::make_pair(results[1], results[2])];
			++nos;
		}
	}
	//map<pair<string, string>,int>::iterator can replaced by auto 
	for (map<pair<string, string>,int>::iterator it = dic.begin(); it != dic.end(); ++it) {
		outfile << it->first.first << "\t" << it->first.second << "\t" << it->second << endl;
	}
}