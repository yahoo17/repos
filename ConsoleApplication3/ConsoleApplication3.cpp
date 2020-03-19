
#include <iostream>
#include "a.h"
using namespace std;
int main()
{
	Date a(1);
	a++;
	int c = a++.data;
	cout << c;
}


