#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum
	{
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};

	void PrintRank(int rank)
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
}

class NameCard
{
private:
	char* name;
	char* company;
	char* number;
	int rank;

public:
	NameCard(const char* _name, const char* _company, const char* _number, int _rank)
		:rank(_rank)
	{
		name = new char[strlen(_name) + 1];
		company = new char[strlen(_company) + 1];
		number = new char[strlen(_number) + 1];
		strcpy(name, _name);
		strcpy(company, _company);
		strcpy(number, _number);
	}
	void ShowNameCardInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "��ȭ��ȣ: " << number << endl;
		cout << "����: ";
		COMP_POS::PrintRank(rank);
		cout << endl;

	}
	~NameCard()
	{
		delete[]name;
		delete[]company;
		delete[]number;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}