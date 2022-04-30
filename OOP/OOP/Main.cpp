#include "Header.h"
#include <iostream>
using namespace std;

int main(void)
{
	AccountHandler accHandler;
	int menu;	//선택자

	while (true)
	{
		accHandler.ShowMenu();			//메뉴 출력
		cout << "선택 : ";
		cin >> menu;
		cout << endl;

		if (menu == 5)					//종료
		{
			cout << "프로그램 종료" << endl;
			return 0;
		}

		switch (menu)					//선택
		{
		case 1:							//계좌개설
			accHandler.MakeAccount();
			break;
		case 2:							//입금
			accHandler.DepositMoney();
			break;
		case 3:							//출금
			accHandler.WithdrawMoney();
			break;
		case 4:							//정보 출력
			accHandler.ShowAllAccInfo();
			break;
		default:
			cout << "1 ~ 5 사이로 입력해주세요." << endl;
			break;
		}
	}
	return 0;
}
