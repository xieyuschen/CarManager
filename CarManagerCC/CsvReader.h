#pragma once
#ifdef CSVREADER_EXPORT
#define CsvReader_API __declspec(dllexport)
#else 
#define CsvReader_API __declspec(dllimport)
#endif
#include"Structs.h"
extern "C" {
	void CsvReader(char* path, CarDetail detail);

}
