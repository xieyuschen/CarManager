#define CSVREADER_EXPORT
#pragma warning(disable:4996)
#include"CsvReader.h"
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
void CsvReader(const char* path, CarDetail detail) {
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

