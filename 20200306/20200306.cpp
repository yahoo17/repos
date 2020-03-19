
#include <iostream>
#include "Time.h"
using std::cout;


//int main()
//{
//	cout << "嘻嘻嘻";
//   
//
//	Time t0("local对象");
//	static Time b("local static对象");
//	
//	cout << "t0" << sizeof(t0)<<'\n';
//	cout << "b" << sizeof(b)<<'\n';
//
//	
//	
//}

int main()
{
	Time t1("1");
	Time t2("2", 9, 38);
	Time t3("3", 9, 38, 25);
	

		t1.printTime();
		t1 = t3;
		t1.printTime();
		t2.printTime();
		t3.printTime();
}