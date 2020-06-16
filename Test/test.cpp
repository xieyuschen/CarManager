#include"CsvReader.h"
#include<stdio.h>
int main() {
	const char* str = "../车辆分类信息表.csv";
	const char* str1 = "../租车订单信息表.csv";
	const char* str2 = "../车辆基本信息表.csv";
	unsigned row = 3;

	auto strs = CsvReader(str, row);

}