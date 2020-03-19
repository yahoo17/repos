#include<iostream>  
#include<iomanip>  
#include"HughInteger.h"  
using namespace std;
int main() 
{
   
    HughInteger a1("1000");
    HughInteger a2("1000");
    HughInteger a3 = a1 + a2;
    HughInteger a4 = a1 * a2;
    a3.output();
    cout << endl;
    a4.output();

}
