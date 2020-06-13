#include"Factory.h"
#include"CsvReader.h"
#include"Info.h"
#include"TimeMe.h"
using namespace std;
CarManagerCommon::CsvReader* CreateCsvReader() {
	return new CarManagerCommon::CsvReader();
}
CarManagerCommon::CsvReader* CreateCsvReader1(string s) {
	return new CarManagerCommon::CsvReader(s);
}
CarManagerCommon::CsvReader* CreateCsvReader2(string s,char c) {
	return new CarManagerCommon::CsvReader(s,c);
}

CarManagerCommon::Info* CreateInfo(const vector<string>& p, const list<vector<string>>& lists) {
	return new CarManagerCommon::Info(p, lists);
}

CarManagerTypes::TimeMe* CreateTimeMe(string year, string month, string day, string hour, string minite, string second) {
	return new CarManagerTypes::TimeMe(year,month,day,hour,minite,second);
}