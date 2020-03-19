#include <iomanip>
#include <iostream>
#include <string>
using std::cout;
using std::setw;
using std::setfill;
using std::string;
class Time
{
public:
	//默认实参定义在第一次出现的地方
	Time(string a,int hour = 0, int minute = 0, int second = 0):m_a(a),m_hour(hour),m_minute(minute),m_second(second)
	{
		cout <<a<<"的构造函数"<<'\n';
	}
	~Time()
	{
		cout << m_a << "的析构函数被调用"<<'\n';
	}
	//类的成员函数,打印该对象的24小时制的时间
	void printTime();
	void printSimpleTime();
	
private:
	int m_hour;
	int m_minute;
	int m_second;
	string m_a;

};