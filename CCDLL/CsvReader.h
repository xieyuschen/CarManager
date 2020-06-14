//#pragma once
//#ifdef CSVREADER_EXPORT
//#define CsvReader_API __declspec(dllexport)
//#else 
//#define CsvReader_API __declspec(dllimport)
//#endif
//extern "C" {
//
//}
#include"Structs.h"

void CsvReader(const char* path, CarDetail detail);
