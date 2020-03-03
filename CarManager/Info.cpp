#include"Info.h"
#include<string>
#include<vector>
#include<list>
#include<iostream>
using namespace std;
Info::Info(vector<string>& _t, list<vector<string>>& _d) {
	title = _t;
	data = _d;
}
Info::~Info(){}
void Info::Add(vector<string> a) {
	if (a.size() == title.size()) {
		data.push_back(a);
	}
	else {
		throw new exception();
	}
}

list<vector<string>> Info::Search(int i,const string& key, bool cryptic) 
{

	list<vector<string>> temp;
	if (cryptic) {
		for (vector<string> piece : data) 
		{
			if (piece[i].find(key) != string::npos) 
			{
				temp.push_back(piece);
			}
		}
	}
	else
	{
		for (vector<string> piece : data) {
			if (piece[i] == key) {
				temp.push_back(piece);
			}
		}
	}
	return temp;
}
list<vector<string>> Info::Search(int i,const string& key) {
	list<vector<string>> temp;
	for (vector<string> piece : data) {
		if (piece[i].find(key) != string::npos) {
			temp.push_back(piece);
		}
	}
	return temp;
}
list<vector<string>> Info::Search(const string& starttime,const string& endtime) {
	list<vector<string>> temp;
	if (title[5] == "取车时间") {
		for (auto item : data) {
			if (item[5] > starttime&& item[5] < endtime) {
				temp.push_back(item);
			}
		}
		return temp;
	}
	else {
		throw new exception();
	}
	
}
void Info::Delete() {};
void Info::Create() {};
