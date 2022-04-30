#include "Header.h"
#include <iostream>
using namespace std;

AccountHandler::AccountHandler()
	:accCnt(0) { }

void AccountHandler::ShowMenu() const
{
	cout << "-----Menu-----" << endl; //메뉴
	cout << "1. 계좌개설 " << endl;
	cout << "2. 입 금 " << endl;
	cout << "3. 출 금 " << endl;
	cout << "4. 계좌정보 전체 출력 " << endl;
	cout << "5. 프로그램 종료 " << endl;
}
void AccountHandler::MakeAccount()
{
	int id;
	char name[10];
	int money;

	cout << endl << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름:";
	cin >> name;
	cout << "입금액:";
	cin >> money;

	accArr[accCnt++] = new Account(id, money, name);
		
	cout << endl;

}
void AccountHandler::DepositMoney()
{
	int id;
	int money;

	cout << endl << "[입  금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;

	for (int i = 0; i < accCnt; i++)		//입금
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

	cout << endl << "[출  금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;
	
	for (int i = 0; i < accCnt; i++)		//출금
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