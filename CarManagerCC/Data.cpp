#include"Data.h"
#include<memory>
#include <string.h>
#include<sstream>
#pragma warning(disable:4996)
CarDetail* DeSerilizeCarDeail(const char* str) {
	std::stringstream strValue;
	int j = 0;
	const char* tok;
	
	CarDetail* detail = (CarDetail*)malloc(sizeof(CarDetail));
	auto s = const_cast<char*>(str);
	for (tok = strtok(s, "\t"); tok && *tok; j++, tok = strtok(NULL, "\t\n"))
	{
		switch (j)
		{
		case 0:
			strValue << tok;
			int t;
			strValue >> t;
			detail->CarNum = t;
			break;
		case 1:
			detail->CarPlateId =const_cast<char*>(tok);
			break;
		case 2:
			detail->CarType = *const_cast<char*>(tok);
			break;
		case 3:
			detail->Name = const_cast<char*>(tok);
			break;
		case 4:
			detail->GearType = const_cast<char*>(tok);
			break;
		case 5:
			detail->Price = strtof(tok,NULL);
			break;
		case 6:
			detail->State = *tok;
		default:
			break;
		}
	}
	return detail;
}
