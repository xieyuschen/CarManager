#ifndef TIME_H
#define TIME_H
#include<string>
using namespace std;
namespace CarManagerTypes {

	class Time
	{
	public:
		Time();
		Time(string dateString);
		Time(string year, string month, string day, string hour, string minite, string second);
		string Show();
		~Time();

	private:
		string _year;
		string _month;
		string _day;
		string _hour;
		string _minite;
		string _second;
	};

}

#endif