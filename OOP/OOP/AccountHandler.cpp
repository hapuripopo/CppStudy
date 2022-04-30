#include "Header.h"
#include <iostream>
using namespace std;

AccountHandler::AccountHandler()
	:accCnt(0) { }

void AccountHandler::ShowMenu() const
{
	cout << "-----Menu-----" << endl; //�޴�
	cout << "1. ���°��� " << endl;
	cout << "2. �� �� " << endl;
	cout << "3. �� �� " << endl;
	cout << "4. �������� ��ü ��� " << endl;
	cout << "5. ���α׷� ���� " << endl;
}
void AccountHandler::MakeAccount()
{
	int id;
	char name[10];
	int money;

	cout << endl << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��:";
	cin >> name;
	cout << "�Աݾ�:";
	cin >> money;

	accArr[accCnt++] = new Account(id, money, name);
		
	cout << endl;

}
void AccountHandler::DepositMoney()
{
	int id;
	int money;

	cout << endl << "[��  ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;

	for (int i = 0; i < accCnt; i++)		//�Ա�
	{
		if (id == accArr[i]->GetAccId())
		{
			accArr[i]->Deposit(money);
			break;
		}
	}
}
void AccountHandler::WithdrawMoney()
{
	int id;
	int money;

	cout << endl << "[��  ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;
	
	for (int i = 0; i < accCnt; i++)		//���
	{
		if (id == accArr[i]->GetAccId())
		{
			accArr[i]->Withdraw(money);
			break;
		}
	}
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accCnt; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}

AccountHandler::~AccountHandler()
{
	delete[]accArr;
}