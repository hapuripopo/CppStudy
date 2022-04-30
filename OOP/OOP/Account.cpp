#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <iostream>
#include <cstring>
using namespace std;

Account::Account(int id, int money, const char* name)
	:accId(id), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account*& acc)
	:accId(acc->accId), balance(acc->balance)
{
	cusName = new char[strlen(acc->cusName) + 1];
	strcpy(cusName, acc->cusName);
}

int Account::GetAccId()
{
	return accId;
}

void Account::Deposit(int money)
{
	balance += money;
	cout << "입금완료" << endl;
}

int Account::Withdraw(int money)
{
	int result = 0;
	if (balance < money)
	{
		cout << "잔액이 부족합니다." << endl;
	}
	else
	{
		balance -= money;
		result = money;
		cout << "출금완료" << endl;
	}
	return result;
}

void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << accId << endl;
	cout << "이 름:" << cusName << endl;
	cout << "잔 액:" << balance << endl;
}

Account::~Account()
{
	delete[]cusName;
}