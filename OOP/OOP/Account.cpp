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
	cout << "�ԱݿϷ�" << endl;
}

int Account::Withdraw(int money)
{
	int result = 0;
	if (balance < money)
	{
		cout << "�ܾ��� �����մϴ�." << endl;
	}
	else
	{
		balance -= money;
		result = money;
		cout << "��ݿϷ�" << endl;
	}
	return result;
}

void Account::ShowAccInfo() const
{
	cout << "����ID: " << accId << endl;
	cout << "�� ��:" << cusName << endl;
	cout << "�� ��:" << balance << endl;
}

Account::~Account()
{
	delete[]cusName;
}