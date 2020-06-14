#pragma once
typedef struct CarType {
	char CarType;
	char CarTypeName[20];
	int NumInPros;
};
typedef struct CarDetail {
	int CarNum;
	char CarPlateId[10];
	char CarType;
	char Name[20];
	char GearType[10];
	float Price;
	char State;
};
typedef struct BookingIngo {
	char BookingId[20];
	char IdentityId[20];
	char CustomerName[20];
	char CarId[4];
	char FetchTime[20];
	char ReturnTime[20];
	float Deposit;
	char ActualReturnTime[20];
	float DeservePrice;
	float ActualPrice;
};