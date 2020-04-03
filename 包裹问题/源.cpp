//序号1 严灏 201830020446
//通过把calculateCost声明成虚函数实现多态
#include<iostream>
#include<iomanip>
#include<string>
#include <vector>
using namespace std;
class Package;
class Person
{
public:  
    friend istream& operator>>(istream& c, Person& p);
    friend ostream& operator<<(ostream& c, Person p);
private:
    string name;
    string address;
    string city;
    string state;
    int zipc;
public:
    //默认构造函数
    Person() :name(""), address(""), city(""), state(""), zipc(0.0) {}
    //赋值构造函数
    Person(const Person& a)
    {
        name = a.name;
        address = a.address;
        city = a.city;
        state = a.state;
        zipc = a.zipc;
    }
};

class Package
{
protected:
    Person sendPerson, receivePerson;
    double weg, cos;
public:
    //初始化构造函数
    Package(Person a, Person b, double w, double c) :sendPerson(a), receivePerson(b), weg(w), cos(c) {}
    //赋值构造函数,调用初始化构造函数进行赋值
    Package(const Package& p) :Package(p.sendPerson, p.receivePerson, p.weg, p.cos) {}
    virtual double calculateCost()
    {
        return weg * cos;
    }
    void print()
    {
        cout << sendPerson << endl;
        cout << receivePerson << endl;
    }
    bool check() {
        return weg > 0 && cos > 0;
    }
};

class TwoDayPackage : public Package
{
private:
    double ff;
public:
    double calculateCost()
    {
        return weg * cos + ff;
    }
    //调用package的赋值构造函数来初始化,下同
    TwoDayPackage(Package p, double f) : Package(p), ff(f) {}
};

class OvernightPackage :public Package
{
public:
    OvernightPackage(Package p, double f) : Package(p), ff(f) {}
    double calculateCost()
    {
        return weg * (cos + ff);
    }
private:
    double ff;
};

istream& operator>>(istream& c, Person& p)
{
    c >> p.name >> p.address >> p.city >> p.state >> p.zipc;
    return c;
}

ostream& operator<<(ostream& c, Person p)
{
    c <<  p.address << ' ' << p.city << ' ' << p.state << ' ' << p.zipc;
    return c;
}
Package initialize()
{
    //录入收件人信息 
    Person *sender=new Person();
    cin >> *sender;

    //录入取件人信息
    Person *receivePersonipient=new Person();
    cin >> *receivePersonipient;

    //录入重量和单位重量的价格
    double weight;
    double price;
    cin >> weight;
    cin >> price;
    //创建Package实例
    Package *p=new Package(*(sender), *receivePersonipient, weight, price);
    //检测weight和price是否是正数
    if (!(*p).check()) {
        cout << "error" << endl;
        return *p;
    }
    return *p;
}
int main() {
   
    vector<Package*> vec;

    Package p1 = initialize();
    double flatFee;
    cin >> flatFee;  //输入TwoDayPackage的固定费用  
    vec.push_back(new TwoDayPackage (p1, flatFee));  //创建 TwoDayPackage实例

    Package p2 = initialize();   
    double addFee;
    cin >> addFee;//输入OvernightPackage额外的单位重量收费
    vec.push_back(new OvernightPackage (p2, addFee));  //创建 OvernightPackage实例
    double total=0;
    //打印发件人和收件人信息
    for (auto it = vec.begin(); it != vec.end(); it++)

    {
        (*it)->print();
        cout << fixed << setprecision(3) << (*it)->calculateCost() << endl;
        total += (*it)->calculateCost();
    }

   

    //打印 总收费
    cout << fixed << setprecision(3) << total << endl;

    return 0;
}

