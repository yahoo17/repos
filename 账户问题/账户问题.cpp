#include<iostream>
#include<iomanip>
#include<string>
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
	 
	inline void credit(double val)
	{
		balance += val;
	}
	inline bool debit(double val)
	{
		if (balance >= val) return (balance -= val, true);
		else return (cout << "Debit amount exceeded account balance.\n", false);
	}
	inline bool check()
	{
		return balance >= 0;
	}
private:
	double balance;
};

class CheckingAccount : public Account
{
private:
	double ff;
public:
	CheckingAccount(double v = 0.0, double f = 0.0) : ff(f) { balance = v; }
	bool credit(double v) {
		if (balance + v - ff >= 0) return (balance += v - ff, true);
		else return (cout << "Operation not permitted.\n", false);
	}
	bool debit(double v) {
		if (balance >= v + ff) return balance -= v + ff, true;
		else return (cout << "Operation not permitted.\n", false);
	}
};

class SavingAccount : public Account
{
private:
	double ra;
public:
	SavingAccount(double v, double r) :ra(r)
	{
		balance = v;
	}
	using Account::credit;
	using Account::debit;
	double calculateInterest()
	{
		return balance * ra / 100;
	}
};

int main() {
	//初始化 
	//输入账户余额 
	double balance;
	cin >> balance;
	//创建一个Account实例 
	Account a(balance);
	//检查输入的balance是否合法 
	if (!a.check())
	{
		a.setBalance(0);
		cout << "Not a valid parameter." << endl;
		return 0;
	}

	//输入利率 
	double rate;
	cin >> rate;
	//创建一个SavingAccount实例 
	SavingAccount aSaving(balance, rate);

	//输入手续费
	double fee;
	cin >> fee;
	//创建一个 CheckingAccount实例 
	CheckingAccount aChecking(balance, fee);

	//模拟业务 
		//输入存取钱数 
	double creditAmount;
	double debitAmount;
	cin >> creditAmount >> debitAmount;
	//测试Acount 
	a.credit(creditAmount); //存钱 
	cout << fixed << setprecision(2) << a.getBalance() << endl;//输出余额 
	if (a.debit(debitAmount)) 
	{ // 取钱 
		cout << fixed << setprecision(2) << a.getBalance() << endl;// 输出余额
	}
	// 测试 CheckingAccount
	if (aChecking.credit(creditAmount)) 
	{
		cout << fixed << setprecision(2) << aChecking.getBalance() << endl;
	}

	if (aChecking.debit(debitAmount)) 
	{
		cout << fixed << setprecision(2) << aChecking.getBalance() << endl;
	}
	//测试 SavingAccount
	double interest = aSaving.calculateInterest();
	aSaving.credit(interest);
	cout << fixed << setprecision(2) << aSaving.getBalance() << endl;

	return 0;
}