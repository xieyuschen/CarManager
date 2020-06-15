#include"Data.h"
#include<memory>
#include <string.h>
#include<sstream>
#include"pch.h"
#pragma warning(disable:4996)
#define DATA_EXPORT
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
BookingInfo* DeSerilizeBookingInfo(const char* str) {
	BookingInfo* detail = (BookingInfo*)malloc(sizeof(BookingInfo));
	auto s = const_cast<char*>(str);
	const char* tok;
	int j = 0;
	for (tok = strtok(s, "\t"); tok && *tok; j++, tok = strtok(NULL, "\t\n")) {
		switch (j)
		{
		case 0:
			detail->BookingId =const_cast<char*>(tok);
			break;
		case 1:
			detail->IdentityId= const_cast<char*>(tok);
			break;
		case 2:
			detail->CustomerName= const_cast<char*>(tok);
			break;
		case 3:
			detail->Telephone= const_cast<char*>(tok);
			break;
		case 4:
			detail->CarId= const_cast<char*>(tok);
			break;
		case 5:
			detail->FetchTime= const_cast<char*>(tok);
			break;
		case 6:
			detail->ReturnTime= const_cast<char*>(tok);
			break;
		case 7:
			detail->Deposit = strtof(tok, NULL);
			break;
		case 8:
			detail->ActualReturnTime= const_cast<char*>(tok);
			break;
		case 9:
			detail->DeservePrice= strtof(tok, NULL);
			break;
		case 10:
			detail->ActualPrice= strtof(tok, NULL);
			break;
		default:
			break;
		}

	}
	return detail;
}
CarType* DeSerilizeCarType(const char* str) {
	CarType* detail = (CarType*)malloc(sizeof(CarType));
	auto s = const_cast<char*>(str);
	const char* tok;
	int j = 0;
	for (tok = strtok(s, "\t"); tok && *tok; j++, tok = strtok(NULL, "\t\n")) {
		switch (j)
		{
		case 0:
			detail->CarType =*tok;
			break;
		case 1:
			detail->CarTypeName = const_cast<char*>(tok);
			break;
		case 2:
			detail->NumInPros = strtol(tok,NULL,NULL);
		default:
			break;
		}

	}
	return detail;
}
void ReadCarDetail(Node* head, CarDetail* carDetail) {
	Node* temp = head;
	CarNode* elem = (CarNode*)malloc(sizeof(CarNode));
	elem->detail = *carDetail;
	Node* last;
	while (temp!=nullptr)
	{
		//找到标号，标号下已有内容
		if (temp->type == carDetail->CarType) {
			 	auto h = temp->start;
				while (h->next != nullptr)
					h = h->next;
				h->next = elem;
				elem->prir = h;
			return;
		}
		last = temp;
		temp = temp->next;
	}
	
}
void ReadBookingInfo(Node* head, BookingInfo*) {}
