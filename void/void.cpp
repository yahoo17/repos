// void.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<iomanip>
using namespace std;
//class A
//{
//public:
//    static void (*__malloc_alloc_oom_handler)();
//public:
//    static void *(set_malloc_hander(void (*f)()))()
//    {
//        void (*old)() = __malloc_alloc_oom_handler;
//        __malloc_alloc_oom_handler = f;
//        return (old);
//    }
//};
int main()
{
    /*char ch[] = "hello h222\n hello2";
    cout << ch << endl << endl;
    cout << &ch << endl;
    cout << *ch << endl;
    char* p = &ch[0];
    cout << static_cast<void*>(p) << endl << endl;*/

    /*cout << p << endl << endl;*/
   /* cout.put('A');
    cout.put(65);*/
    //cout << "Enter a list intergers:" << endl;
    //int currVal = 0;
    //int  val = 0;
    //int cnt = 0;
    //if (cin >> currVal)
    //{
    //    cnt = 1;
    //    //
    //    while (cin >> val)
    //    {
    //        if (currVal == val)
    //        {
    //            ++cnt;
    //        }
    //        else
    //        {
    //            cout << currVal << " occurs" << cnt << "  times" << endl;
    //            currVal = val;
    //            cnt = 1;
    //        }
    //       
    //    }
    //    /*cout << currVal << " occurs" << cnt << "times. " << endl;*/
    //}
    //return 0;
    //const int SIZE = 100;
    //char buffer[SIZE];
    //cin.read(buffer, 20);
    //
    //cout.write(buffer, cin.gcount());
    /*cout << hex << 16;
    cout << dec<<16;*/
    //cout << setbase(16) << 100;
    //cout << 100;
    /*char sentence[10];
    int val = 5;
    while (cin>>sentence)
    {
        cout.width(val++);
        cout << sentence;
        cin.width(5);

    }*/
    cout<<cin.rdstate()<<endl;
    
    cout << cin.good()<<endl;
    cout << cin.bad() << endl;
    cout << cin.fail() << endl;
    cout << cin.eof()<<endl;

    int a;
    cin >> a;
    cout << cin.rdstate() << endl;
    cout << cin.good() << endl;
    cout << cin.bad() << endl;
    cout << cin.fail() << endl;
    cout << cin.eof() << endl;
}

