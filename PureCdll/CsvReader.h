#pragma once
#ifdef CSVREADER_EXPORT
#define CsvReader_API  __declspec(dllexport)
#else 
#define CsvReader_API __declspec(dllimport)
#endif
#include"Structs.h"
extern "C" {
	CsvReader_API const char** CsvReader(const char* path, unsigned rows);
	CsvReader_API void Test();
}



