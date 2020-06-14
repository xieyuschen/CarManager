#include<stdio.h>
#pragma warning(disable:4996)

#include <string.h>
#include <stdlib.h>
#include"Structs.h"
#include"CsvReader.h"
#include"Data.h"
int main() {
	CarDetail c;
	const char* str = "../车辆分类信息表.csv";
	const char* str1 = "../租车订单信息表.csv";
	const char* str2 = "../车辆基本信息表.csv";
	unsigned row = 2;
	auto strs=CsvReader(str2,row);
	auto re = DeSerilizeCarDeail(strs[1]);
	
}