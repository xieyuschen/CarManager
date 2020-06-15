#pragma once
#define DllExport __declspec(dllexport)
typedef struct CarType {
	char CarType;
	char* CarTypeName;
	int NumInPros;
};
typedef struct CarDetail {
	int CarNum;
	char* CarPlateId;
	char CarType;
	char* Name;
	char* GearType;
	float Price;
	char State;
};
typedef struct BookingInfo {
	char* BookingId;
	char* IdentityId;
	char* CustomerName;
	char* CarId;
	char* FetchTime;
	char* ReturnTime;
	float Deposit;
	char* ActualReturnTime;
	float DeservePrice;
	float ActualPrice;
	char* Telephone;
};
typedef struct CarNode {
	BookingInfo info;
	CarDetail detail;
	CarNode* next;
	CarNode* prir;
};
typedef struct Node {
	CarNode* start;
	Node* next;
	char type;
};