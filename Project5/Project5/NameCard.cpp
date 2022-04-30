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
	cout << "�̸�: " << name << endl;
	cout << "ȸ��: " << company << endl;
	cout << "��ȭ��ȣ: " << number << endl;
	cout << "����: ";
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
		cout << "���" << endl;
		break;
	case SENIOR:
		cout << "����" << endl;
		break;
	case ASSIST:
		cout << "�븮" << endl;
		break;
	case MANAGER:
		cout << "����" << endl;
		break;
	}
}