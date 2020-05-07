#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include"CsvReader.h"
#include"Info.h"
#include<Windows.h>
#include<regex>
#include<fstream>
using namespace std;
#include"Time.h"

int main(){
	
	CarManagerTypes::Time t("2019/02/15-12:00");
	cout << t.Show();
	/*string line;
	ifstream in;
	in.open("E:\\Code\\CarManager\\CarManager\\1.txt");
	in >> line;*/
	//string file("1.csv");
	//CsvReader demo(file);
	//Info table(demo.title, demo.data);
	//auto item = table.Search("2019/02/15-12:00", "2019/02/15-14:00");
	//for (auto piece : item) {
	//	for (auto a : piece)
	//		cout << a << ends;
	//	cout << endl;

	//}

}