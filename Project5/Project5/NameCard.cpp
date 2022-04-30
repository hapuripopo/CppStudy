#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "head.h"
using namespace std;


NameCard::NameCard(const char* _name, const char* _company, const char* _number, int _rank)
	:rank(_rank)
{
	name = new char[strlen(_name) + 1];
	company = new char[strlen(_company) + 1];
	number = new char[strlen(_number) + 1];
	strcpy(name, _name);
	strcpy(company, _company);
	strcpy(number, _number);
}

NameCard::NameCard(const NameCard& copy)
	:rank(copy.rank)
{
	name = new char[strlen(copy.name) + 1];
	company = new char[strlen(copy.company) + 1];
	number = new char[strlen(copy.number) + 1];
	strcpy(name, copy.name);
	strcpy(company, copy.company);
	strcpy(number, copy.number);
}

void NameCard::ShowNameCardInfo()
{
	cout << "이름: " << name << endl;
	cout << "회사: " << company << endl;
	cout << "전화번호: " << number << endl;
	cout << "직급: ";
	COMP_POS::PrintRank(rank);
	cout << endl;

}

NameCard::~NameCard()
{
	delete[]name;
	delete[]company;
	delete[]number;
}

void COMP_POS::PrintRank(int rank)
{
	switch (rank)
	{
	case CLERK:
		cout << "사원" << endl;
		break;
	case SENIOR:
		cout << "주임" << endl;
		break;
	case ASSIST:
		cout << "대리" << endl;
		break;
	case MANAGER:
		cout << "과장" << endl;
		break;
	}
}