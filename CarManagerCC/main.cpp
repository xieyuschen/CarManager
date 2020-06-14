#include<stdio.h>
#pragma warning(disable:4996)

#include <string.h>
#include <stdlib.h>
#include"Structs.h"
#include"CsvReader.h"
int main() {
	CarDetail c;
	const char* str = "../车辆分类信息表.csv";
	const char* str1 = "../租车订单信息表.csv";
	unsigned row = 2;
	auto strs=CsvReader(str1,row);
	for (int i = 0; i < row; i++) {
		printf("%s", strs[i]);
	}
}