// 序号  1 严灏 201830020446
#include<iostream>
#include<iomanip>
#include<string>
#include <vector>
using namespace std;

class Account
{
public:
	explicit  Account(double v = 0.0) :balance(v)
	{}

public:
	inline void setBalance(double v)
	{
		balance = v;
	}
	inline double getBalance()
	{
		return balance;
	}
	 
	 virtual bool credit(double val)
	{
		balance += val;
		return true;
	}
	 virtual bool debit(double val)
	{
		if (balance >= val) 
			return (balance -= val, true);
		else 
			return (cout << "Debit amount exceeded account balance.\n", false);
	}
	inline bool check()
	{
		return balance >= 0;
	}
protected:
	double balance;
};

class CheckingAccount : public Account
{
private:
	double ff;
public:
	CheckingAccount(double v = 0.0, double f = 0.0) : ff(f) ,Account(v)
	{ 
		
	}
	bool credit(double v) 
	{
		if (balance + v - ff >= 0)
		{
			balance += v;
			balance -= ff;
			return  true;
		}
		
		else 
			return (cout << "Operation not permitted.\n", false);
	}
	bool debit(double v)
	{
		if (balance >= v + ff)
		{
			balance -= v;
			balance -= ff;
		}
			
		else 
			return (cout << "Operation not permitted.\n", false);
	}
};

class SavingAccount : public Account
{
public:
	double ra;
public:
	friend void addInterest(SavingAccount& sa);
	SavingAccount(double v=0.0, double r=0.0) :ra(r), Account(v)
	{
		double interest =balance * (ra / 100);
		balance += interest;
		
	}
	
	
};
void addInterest(SavingAccount& sa)
{
	
}
void create(vector<Account>& vec)
{
	double type,rate,credit,debit;
	cin >> type;
	cin >> rate;
	cin >> credit;
	cin >> debit;
	if (type)
	{
		Account* a1 = new CheckingAccount(10000, rate);
		
		a1->credit(credit);
		a1->debit(debit);
		vec.push_back(*a1);
	}
	else
	{
		Account* a2 = new SavingAccount(10000,rate);
		
		a2->credit(credit);
		a2->debit(debit);
		vec.push_back(*a2);
	}
	
}
int main() {
	int number;
	cin >> number;
	vector<Account> vec;
	for (int i = 0; i < number; i++)
	{
		create(vec);
	}

	
	
	for(auto it =vec.begin();it!=vec.end();it++)

		cout << fixed << setprecision(3) << (*it).getBalance() << endl;

	return 0;
}