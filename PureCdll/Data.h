#pragma once
#ifdef DATA_EXPORT
#define Data_API __declspec(dllexport)
#else
#define Data_API __declspec(dllimport)
#endif // DATA_EXPORT

#include"Structs.h"
extern "C" {
	Data_API CarDetail* DeSerilizeCarDeail(const char*);
	Data_API BookingInfo* DeSerilizeBookingInfo(const char*);
	Data_API CarType* DeSerilizeCarType(const char*);
	Data_API void ReadCarDetail(Node* head, CarDetail*);
	Data_API void ReadBookingInfo(Node* head, BookingInfo*);
}

