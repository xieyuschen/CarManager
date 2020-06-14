#include<stdio.h>
#pragma warning(disable:4996)

#include <string.h>
#include <stdlib.h>
#include"Structs.h"
void CsvReader(const char* path) {
	FILE* file;
	file = fopen(path, "r");
	int row = 1;
	int i = 0;
	char line[4098];
	while (fgets(line, 4098, file) && (i < row))
	{
		// double row[ssParams->nreal + 1];
		char* tmp = strdup(line);
		printf("%s", tmp);
		//int j = 0;
		//const char* tok;
		//for (tok = strtok(line, "\t"); tok && *tok; j++, tok = strtok(NULL, "\t\n"))
		//{
		//	printf("%s\t", tok);
		//}
		//printf("\n");
		free(tmp);
		i++;
	}
}

int main() {
	CarDetail c;
	const char* str = "../车辆分类信息表.csv";
	CsvReader(str);
}