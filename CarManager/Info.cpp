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

list<vector<string>> Info::Search(int i, string key, bool cryptic) {
	int j = i;
	list<vector<string>> temp;
	if (cryptic) {
		for (vector<string> piece : data) {
			if (piece[j].find(key) != string::npos) {
				temp.push_back(piece);
			}
		}
	}
	else
	{
		for (vector<string> piece : data) {
			if (piece[j] == key) {
				temp.push_back(piece);
			}
		}
	}
	return temp;
}
list<vector<string>> Info::Search(int i, string) {
	list<vector<string>> a;
	return a;
}
void Info::Delete() {};
void Info::Create() {};
