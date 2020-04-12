// 1-.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int getCount(int num)
{
    int count = 0;
    while (num>0)
    {
        if (num % 2 == 1)
        {
            count++;
            num /= 2;
        }
        else
        {
            num /= 2;
        }
    }
    return count;
    
}
int main()
{
    int group;
    cin >> group;
    for (int i = 0; i < group; i++)
    {
        int size;
        cin >> size;
        vector<int> vec;
        for (int i = 0; i < size; i++)
        {
            int number;
            cin >> number;
            int count = getCount(number); \
            bool find = false;
            for (auto it = vec.begin(); it != vec.end(); it++)
            {
                if (*it == count)
                {
                    find = true;
                    break;
                }
            }
            if (!find)
                vec.push_back(count);

        }
        cout << vec.size();
        if (i != group - 1)
            cout << " ";



    }
}

