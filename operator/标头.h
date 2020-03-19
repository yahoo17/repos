class Base
{
private:

	char a;
public:
	Base(char jjj) :a(jjj)
	{


	}
};
class Son
{
public:

	Son(char a, Base ba) :m_char(a), base(ba)
	{

	}
	operator Base() { return base; }
	operator char() { return m_char; }
private:
	Base base;
	char m_char;
};