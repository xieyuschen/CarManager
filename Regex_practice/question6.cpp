#include<regex>
#include<fstream>
#include<string>
using namespace std;
int main() {
	ifstream infile("passingevents.xls");
	ofstream outfile("1.xls");
	string s;
	smatch result;
	string format = "$1$3$5$6";
	string con = "^(\\d{1,2}\tHuskies\t)(Huskies_)(\\w*\t)(Huskies_)(\\w*\t)(.*)";
	regex r(con);
	while (getline(infile, s)) {
		regex_search(s, result, r);
		if (!result.empty()) {
			outfile << regex_replace(s, r, format) << endl;
		}
	}

}