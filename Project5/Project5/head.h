#ifndef __COMP__
#define __COMP__

namespace COMP_POS
{
	enum
	{
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};

	void PrintRank(int rank);
}

class NameCard
{
private:
	char* name;
	char* company;
	char* number;
	int rank;

public:
	NameCard(const char* _name, const char* _company, const char* _number, int _rank);
	NameCard(const NameCard& copy);
	void ShowNameCardInfo();
	~NameCard();
};
#endif // !1