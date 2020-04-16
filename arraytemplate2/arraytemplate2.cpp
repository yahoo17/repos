//学号201830020446 严灏 序号1
#include<iostream>
#include<iomanip>
using namespace std;
template<class T>
void Swap(T& t1, T& t2)
{
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template<class T>
class Array
{
private:
    T* val;
    int size;
public:
    Array(int s = 10);
    ~Array();
    T getsum();
    T& operator[](int sub);
    Array& operator=(const Array& x);
};

template<class T>
Array<T>::Array(int s) : size(s)
{
    val = new T[s];
}

template<class T>
Array<T>::~Array()
{
    delete[] val;
}

template<class T>
T Array<T>::getsum()
{
    T res = 0;
    for (int i = 0; i < size; i++) res += val[i];
    return res;
}

template<class T>
T& Array<T>::operator[](int sub)
{
    return val[sub];
}

//重载=运算符
template<class T>
Array<T>& Array<T>::operator=(const Array<T>& x)
{
    size = x.size;
    delete[] val;
    val = new T[size];
    for (int i = 0; i < size; i++) val[i] = x.val[i];
    return *this;
}

int main()
{
    Array<int> a;
    a = Array<int>(100);
    int i, n, m;
    cin >> n >> m;
    Array<int> a1(n), a2(m);

    for (i = 0; i < n; i++) cin >> a1[i];
    for (i = 0; i < m; i++) cin >> a2[i];

    Swap(a1, a2);
    for (i = 0; i < m; i++) cout << a1[i] << ' ';
    cout << endl;
    for (i = 0; i < n; i++) cout << a2[i] << ' ';

}

