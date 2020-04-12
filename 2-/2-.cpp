// 2-.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
void printNum(int height, vector<int> &flood,int size)
{
    
    int count=0;
    bool isin1 = false;
    for (int j = 0; j < size;j++ )
    {
        if (flood[j] > height)
        {
            if (isin1 == false)
            {
                //第一次进来
                count++;

                isin1 = true;
            }                  
              
        }
        else
        {
            //flood[j]=0
            isin1 = false;
        }

    }
    cout<<count<<endl;




}
int main()
{
    int size;
    cin >> size;
    vector<int> array;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        array.push_back(temp);
    }
    // 初始化

    int size2;
    cin >> size2;
    int* flood = new int[size2];
    for (int i = 0; i < size2; i++)
    {
        int temp;
        cin >> temp;
        flood[i]=(temp);
    }
    for (int i = 0; i < size2; i++)
    {
        printNum(flood[i], array,size);
    }

}

