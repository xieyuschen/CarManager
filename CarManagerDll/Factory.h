#pragma once
#include"CsvReader.h"
#include"Info.h"
#include<string>
#include"TimeMe.h"
using namespace std;
extern "C" CsvReader_API CarManagerCommon::CsvReader * __cdecl CreateCsvReader();
extern "C" CsvReader_API CarManagerCommon::CsvReader * __cdecl CreateCsvReader(string, char);
extern "C" CsvReader_API CarManagerCommon::CsvReader * __cdecl CreateCsvReader(string);

extern "C" Info_API CarManagerCommon::Info * __cdecl CreateInfo(const vector<string>&, const list<vector<string>>&);
extern "C" TimeMe_API CarManagerTypes::TimeMe* __cdecl CreateTimeMe(string year, string month, string day, string hour, string minite, string second);

