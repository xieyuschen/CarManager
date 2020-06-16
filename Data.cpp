#include"Data.h"
#include<memory>
#include <string.h>
#include<sstream>
#include"Structs.h"
#pragma warning(disable:4996)
//#define DATA_EXPORT
extern "C" {
#pragma once
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
	__declspec(dllexport) CarDetail* DeSerilizeCarDeail(const char* str) {
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
				detail->CarPlateId = const_cast<char*>(tok);
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
				detail->Price = strtof(tok, NULL);
				break;
			case 6:
				detail->State = *tok;
			default:
				break;
			}
		}
		return detail;
	}
	__declspec(dllexport) BookingInfo* DeSerilizeBookingInfo(const char* str) {
		BookingInfo* detail = (BookingInfo*)malloc(sizeof(BookingInfo));
		auto s = const_cast<char*>(str);
		const char* tok;
		int j = 0;
		for (tok = strtok(s, "\t"); tok && *tok; j++, tok = strtok(NULL, "\t\n")) {
			switch (j)
			{
			case 0:
				detail->BookingId = const_cast<char*>(tok);
				break;
			case 1:
				detail->IdentityId = const_cast<char*>(tok);
				break;
			case 2:
				detail->CustomerName = const_cast<char*>(tok);
				break;
			case 3:
				detail->Telephone = const_cast<char*>(tok);
				break;
			case 4:
				detail->CarId = const_cast<char*>(tok);
				break;
			case 5:
				detail->FetchTime = const_cast<char*>(tok);
				break;
			case 6:
				detail->ReturnTime = const_cast<char*>(tok);
				break;
			case 7:
				detail->Deposit = strtof(tok, NULL);
				break;
			case 8:
				detail->ActualReturnTime = const_cast<char*>(tok);
				break;
			case 9:
				detail->DeservePrice = strtof(tok, NULL);
				break;
			case 10:
				detail->ActualPrice = strtof(tok, NULL);
				break;
			default:
				break;
			}

		}
		return detail;
	}
	__declspec(dllexport) CarType* DeSerilizeCarType(const char* str) {
		CarType* detail = (CarType*)malloc(sizeof(CarType));
		auto s = const_cast<char*>(str);
		const char* tok;
		int j = 0;
		for (tok = strtok(s, "\t"); tok && *tok; j++, tok = strtok(NULL, "\t\n")) {
			switch (j)
			{
			case 0:
				detail->CarType = *tok;
				break;
			case 1:
				detail->CarTypeName = const_cast<char*>(tok);
				break;
			case 2:
				detail->NumInPros = strtol(tok, NULL, NULL);
			default:
				break;
			}

		}
		return detail;
	}

	__declspec(dllexport) void ReadCarDetail(Node* head, CarDetail* carDetail) {
		Node* temp = head;
		CarNode* elem = (CarNode*)malloc(sizeof(CarNode));
		elem->detail = *carDetail;
		Node* last;
		while (temp != nullptr)
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

}
//void ReadBookingInfo(Node* head, BookingInfo*);
