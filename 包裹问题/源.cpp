//���1 ��� 201830020446
//ͨ����calculateCost�������麯��ʵ�ֶ�̬
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
    //Ĭ�Ϲ��캯��
    Person() :name(""), address(""), city(""), state(""), zipc(0.0) {}
    //��ֵ���캯��
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
    //��ʼ�����캯��
    Package(Person a, Person b, double w, double c) :sendPerson(a), receivePerson(b), weg(w), cos(c) {}
    //��ֵ���캯��,���ó�ʼ�����캯�����и�ֵ
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
    //����package�ĸ�ֵ���캯������ʼ��,��ͬ
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
    //¼���ռ�����Ϣ 
    Person *sender=new Person();
    cin >> *sender;

    //¼��ȡ������Ϣ
    Person *receivePersonipient=new Person();
    cin >> *receivePersonipient;

    //¼�������͵�λ�����ļ۸�
    double weight;
    double price;
    cin >> weight;
    cin >> price;
    //����Packageʵ��
    Package *p=new Package(*(sender), *receivePersonipient, weight, price);
    //���weight��price�Ƿ�������
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
    cin >> flatFee;  //����TwoDayPackage�Ĺ̶�����  
    vec.push_back(new TwoDayPackage (p1, flatFee));  //���� TwoDayPackageʵ��

    Package p2 = initialize();   
    double addFee;
    cin >> addFee;//����OvernightPackage����ĵ�λ�����շ�
    vec.push_back(new OvernightPackage (p2, addFee));  //���� OvernightPackageʵ��
    double total=0;
    //��ӡ�����˺��ռ�����Ϣ
    for (auto it = vec.begin(); it != vec.end(); it++)

    {
        (*it)->print();
        cout << fixed << setprecision(3) << (*it)->calculateCost() << endl;
        total += (*it)->calculateCost();
    }

   

    //��ӡ ���շ�
    cout << fixed << setprecision(3) << total << endl;

    return 0;
}

