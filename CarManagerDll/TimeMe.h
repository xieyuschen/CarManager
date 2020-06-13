#pragma once
#ifdef TIMEME_EXPORT
#define TimeMe_API __declspec(dllexport)
#else
#define TimeMe_API __declspec(dllimport)
#endif // TIMEME_EXPORT

#include<string>
using namespace std;
namespace CarManagerTypes {

	class TimeMe_API TimeMe
	{
	public:
		TimeMe();
		TimeMe(string dateString);
		TimeMe(string year, string month, string day, string hour, string minite, string second);
		string Show();
		~TimeMe();
		bool operator<(TimeMe);
	private:
		string _year;
		string _month;
		string _day;
		string _hour;
		string _minite;
		string _second;
	};

}
