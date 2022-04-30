class Employee
{
private:
	char name[100];
public:
	Employee(const char* _name);
	void ShowYourName() const;
	virtual int GetPay() const;
	virtual void ShowSalaryInfo() const;
};

class PermanentWorker : public Employee
{
private:
	char name[100];
	int salary;
public:
	PermanentWorker(const char* _name, int money);
	virtual int GetPay() const;
	virtual void ShowSalaryInfo() const;
};

class TemporaryWoker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWoker(const char* _name, int _pay);
	void AddWorker(int time);
	virtual int GetPay() const;
	virtual void ShowSalaryInfo() const;
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* _name, int _money, double _ratio);
	virtual void AddSalesResult(int value);
	virtual int GetPay() const;
	virtual void ShowSalaryInfo() const;
};

class ForeignSaleWorker : public SalesWorker
{
private:
	int risk;
public:
	ForeignSaleWorker(const char* _name, int _money, double _ratio, int _risk);
	int RiskPay() const;
	virtual int GetPay() const;
	virtual void ShowSalaryInfo() const;
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler();
	void AddEmployee(Employee* emp);
	void ShowAllSalaryInfo() const;
	void ShowTotalSalary() const;
	~EmployeeHandler();
};

namespace RISK_LEVEL {
	enum {
		RISK_A,
		RISK_B,
		RISK_C
	};
}