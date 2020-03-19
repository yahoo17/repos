#include "Time.h"
class Employee
{
public:
	Employee(Time t1, Time t2):birthTime(t1),hireTime(t2)
	{
		
	}
private:
	const Time birthTime;
	const Time hireTime;

};