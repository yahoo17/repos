// inheritence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
class B 
{
private:
    void pvB() { printf("pvB\n"); }
protected:
    void ptB() { printf("ptB\n"); }
public:
    void pbB() { printf("pbB\n"); }

};
class D: protected B
{
public:
	
    void func() { ptB(); pbB(); }
protected:

private:

};
class G :public D
{
public:
    void fucG()
    {
        ptB();
    }
};
void function(D& d)
{
    
}

int main()
{
    B b;
    b.pbB();
    D d;
    d.func();
}

