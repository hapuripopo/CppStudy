#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <iostream>
#include <cstring>
using namespace std;

Employee::Employee(const char* _name)
{
	strcpy(name, _name);
}

void Employee::ShowYourName() const
{
	cout << "name: " << name << endl;
}

int Employee::GetPay() const
{
	return 0;
}

void Employee::ShowSalaryInfo() const
{
	cout << "name: " << name << endl;
}


//정규직
PermanentWorker::PermanentWorker(const char* _name, int _money)
	: Employee(_name), salary(_money)
{
	strcpy(name, _name);
}

int PermanentWorker::GetPay() const
{
	return salary;
}

void PermanentWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "salary: " << GetPay() << endl << endl;
}


//임시직
TemporaryWoker::TemporaryWoker(const char* _name, int _pay)
	:Employee(_name), workTime(0), payPerHour(_pay) { }

void TemporaryWoker::AddWorker(int time)
{
	workTime += time;
}

int TemporaryWoker::GetPay() const
{
	return workTime * payPerHour;
}

void TemporaryWoker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "salary: " << GetPay() << endl << endl;
}


//영업직
SalesWorker::SalesWorker(const char* _name, int _money, double _ratio)
	:PermanentWorker(_name, _money), salesResult(0), bonusRatio(_ratio){ }

void SalesWorker::AddSalesResult(int value)
{
	salesResult += value;
}

int SalesWorker::GetPay() const
{
	return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
}

void SalesWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "salary: " << GetPay() << endl << endl;
}

//해외 영업직 등록
ForeignSaleWorker::ForeignSaleWorker(const char* _name, int _money, double _ratio, int _risk)
	:SalesWorker(_name, _money, _ratio), risk(_risk){ }

int ForeignSaleWorker::GetPay() const
{
	return RiskPay() + SalesWorker::GetPay();
}

int ForeignSaleWorker::RiskPay() const
{
	switch (risk)
	{
	case 0:
		return (int)(SalesWorker::GetPay() * 0.3);
		break;
	case 1:
		return (int)(SalesWorker::GetPay() * 0.2);
		break;
	case 2:
		return (int)(SalesWorker::GetPay() * 0.1);
		break;
	default:
		return 0;
	}
}

void ForeignSaleWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "salary: " << SalesWorker::GetPay() << endl;
	cout << "risk pay: " << RiskPay() << endl;
	cout << "sum: " << GetPay() << endl << endl;
}