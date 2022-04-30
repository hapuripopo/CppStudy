#include "Header.h"
#include <iostream>
using namespace std;

int main(void)
{
	AccountHandler accHandler;
	int menu;	//������

	while (true)
	{
		accHandler.ShowMenu();			//�޴� ���
		cout << "���� : ";
		cin >> menu;
		cout << endl;

		if (menu == 5)					//����
		{
			cout << "���α׷� ����" << endl;
			return 0;
		}

		switch (menu)					//����
		{
		case 1:							//���°���
			accHandler.MakeAccount();
			break;
		case 2:							//�Ա�
			accHandler.DepositMoney();
			break;
		case 3:							//���
			accHandler.WithdrawMoney();
			break;
		case 4:							//���� ���
			accHandler.ShowAllAccInfo();
			break;
		default:
			cout << "1 ~ 5 ���̷� �Է����ּ���." << endl;
			break;
		}
	}
	return 0;
}
