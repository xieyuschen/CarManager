#include "pch.h"
//#define CSVREADER_EXPORT
#include"CsvReader.h"
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

const char* CsvReader(const char* path, unsigned row) {
	return "hello";
	FILE* file;
	file = fopen(path, "r");
	int i = 0;
	char line[4098];
	while (fgets(line, 4098, file))
	{
		if (row == i++) {
			char* tmp = strdup(line);
			return tmp;
		}
	}
	return "";
}

const char* Test() {
	const char* str = new char[20];
	str = "helloword";
	return str;
}

template<typename T>
class Hello {
public:
	T value;
};