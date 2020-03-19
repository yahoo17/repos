#include <iostream>
using std::ostream;
using std::istream;
class Array
{
public:
	//Big three 
	//构造函数 拷贝构造函数 析构函数
	Array(int=100);
	Array(Array& a);
	~Array();
public:
	friend ostream& operator<<( ostream& os, const Array& c1);
	friend istream& operator>>( istream& is, const Array& c1);

	bool operator==(Array& c1);
	//bool 

	int& operator[](int);
	int operator[](int)const;
	int size();
private:
	int m_size;
	static const int maxsize=100;
	int array[maxsize];





};