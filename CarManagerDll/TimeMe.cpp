#define TIMEME_EXPORT
#include"TimeMe.h"
#include<sstream>
#include<regex>
namespace CarManagerTypes {
	TimeMe::TimeMe()
	{
	}
	TimeMe::TimeMe(string year, string month, string day, string hour, string minite, string second) {
		_year = year;
		_month = month;
		_day = day;
		_hour = hour;
		_minite = minite;
		_second = second;
	}
	TimeMe::TimeMe(string dateString) {
		string format = "$1 $2 $3 $4 $5";
		regex r("^(\\d{4})/(\\d{2})/(\\d{2})-(\\d{2}):(\\d{1,2}).*");
		string temp;
		smatch result;
		vector<string> time;
		//regex_search(dateString, result, r);
		stringstream ss(regex_replace(dateString, r, format));
		while (ss) {
			ss >> temp;
			time.push_back(temp);
		}
		_year = time[0];
		_month = time[1];
		_day = time[2];
		_hour = time[3];
		_minite = time[4];
		_second = time[5];
	}
	TimeMe::~TimeMe()
	{
	}

	string TimeMe::Show() {
		return _year + "/" + _month + "/" + _day + "-" + _hour + ":" + _minite;
	}
	bool TimeMe::operator<(TimeMe r) {
		return Show() < r.Show();
	}
}
