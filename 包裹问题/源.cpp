#include<iostream>
#include<iomanip>
#include<string>
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
    double calculateCost()
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
    c << p.name << ' ' << p.address << ' ' << p.city << ' ' << p.state << ' ' << p.zipc;
    return c;
}

int main() {
    //¼���ռ�����Ϣ 
    Person sender;
    cin >> sender;

    //¼��ȡ������Ϣ
    Person receivePersonipient;
    cin >> receivePersonipient;

    //¼�������͵�λ�����ļ۸�
    double weight;
    double price;
    cin >> weight;
    cin >> price;
    //����Packageʵ��
    Package p(sender, receivePersonipient, weight, price);
    //���weight��price�Ƿ�������
    if (!p.check()) {
        cout << "error" << endl;
        return 0;
    }

    //����TwoDayPackage�Ĺ̶�����
    double flatFee;
    cin >> flatFee;
    //���� TwoDayPackageʵ��
    TwoDayPackage pTwoDay(p, flatFee);

    //����OvernightPackage����ĵ�λ�����շ�
    double addFee;
    cin >> addFee;
    //���� OvernightPackageʵ��
    OvernightPackage pOvernight(p, addFee);

    //��ӡ�����˺��ռ�����Ϣ
    p.print();

    //��ӡ Package �շ�
    cout << fixed << setprecision(3) << p.calculateCost() << endl;

    //��ӡ TwoDayPackage �շ� 
    cout << fixed << setprecision(3) << pTwoDay.calculateCost() << endl;

    //��ӡ OvernightPackage �շ�
    cout << fixed << setprecision(3) << pOvernight.calculateCost() << endl;

    return 0;
}

