#pragma once
#ifndef __ACCOUNT__
#define __ACCOUNT__

class Account
{
private:
	int accId;		//계좌번호
	int balance;	//잔   액
	char* cusName;		//고객이름

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
	Account* accArr[100];	//계좌가 있는 배열
	int accCnt;			//개설 된 계좌 수
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