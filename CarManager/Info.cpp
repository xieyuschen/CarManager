#include"Info.h"
#include<string>
#include<vector>
#include<list>
#include<iostream>
#include"ColumnName.h"
Info::Info(vector<string>& _t, list<vector<string>>& _d) {
	title = _t;
	data = _d;
}
void Info::Add(vector<string> a) {
	if (a.size() == title.size()) {
		data.push_back(a);
	}
	else {
		throw new exception();
	}
}
void Search();
void Delete();
void Create();
