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
	//Ĭ��ʵ�ζ����ڵ�һ�γ��ֵĵط�
	Time(string a,int hour = 0, int minute = 0, int second = 0):m_a(a),m_hour(hour),m_minute(minute),m_second(second)
	{
		cout <<a<<"�Ĺ��캯��"<<'\n';
	}
	~Time()
	{
		cout << m_a << "����������������"<<'\n';
	}
	//��ĳ�Ա����,��ӡ�ö����24Сʱ�Ƶ�ʱ��
	void printTime();
	void printSimpleTime();
	
private:
	int m_hour;
	int m_minute;
	int m_second;
	string m_a;

};