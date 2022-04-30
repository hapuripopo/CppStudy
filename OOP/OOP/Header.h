#pragma once
#ifndef __ACCOUNT__
#define __ACCOUNT__

class Account
{
private:
	int accId;		//���¹�ȣ
	int balance;	//��   ��
	char* cusName;		//���̸�

public:
	Account(int id, int money, const char* name);
	Account(const Account* &acc);
	int GetAccId();
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

#endif // !__ACCOUNT__

#ifndef __ACC_HANDLER__
#define __ACC_HANDLER__

class AccountHandler
{
private:
	Account* accArr[100];	//���°� �ִ� �迭
	int accCnt;			//���� �� ���� ��
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
};
#endif // !__ACC_HANDLER__