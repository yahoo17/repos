// 11111111.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include  <math.h>
#include <vector>
using namespace std;
class ssset
{
public:
    
    vector<int> setArray;
   

};
void func1(vector<ssset>);
void func2(vector<ssset>);
void func3(vector<ssset>, vector <int>* output);
int main()
{
    vector <int> output;
    int group;
    cin >> group;
    for (int i = 0; i < group; i++)
    {
        
        vector<ssset> setlist;
        int zzsgs, size;
        cin >> zzsgs;
        cin >> size;
        for (int i = 1; i <= zzsgs; i++)
        {
            ssset temp;
            temp.setArray.push_back(i);
            setlist.push_back(temp);
        }
        for (int i = 0; i < size; i++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                func1(setlist);
            }
            else if (temp == 2)
            {
                func2(setlist);
            }
            else
            {
                func3(setlist, &output);
            }
        }

       





      }
    for (auto x : output)
        cout << x << endl;
 }
void func1(vector<ssset> setlist)
{
    int x, y;
    cin >> x >> y;
    bool findA = false;
    bool findB = false;
    vector<ssset>::iterator ptrx;
    vector<ssset>::iterator ptry;
    for (auto it = setlist.begin(); it != setlist.end(); it++)
    {
        for (auto i = it->setArray.begin(); i != it->setArray.end(); i++)
        {
            if (*i == x)
            {
                findA = true;
                
                ptrx = it;
            }

        }
    }
    for (auto it = setlist.begin(); it != setlist.end(); it++)
    {
        for (auto i = it->setArray.begin(); i != it->setArray.end(); i++)
        {
            if (*i == y)
            {
                findB = true;
                ptry = it;
            }

        }
    }
    if (ptrx != ptry)
    {
        ssset temp;
        for (auto it = ptrx->setArray.begin(); it != ptrx->setArray.end(); it++)
        {
            temp.setArray.push_back(*it);
        }
        for (auto it = ptry->setArray.begin(); it != ptry->setArray.end(); it++)
        {
            temp.setArray.push_back(*it);
        }
        setlist.erase(ptrx);
        setlist.erase(ptry);
        setlist.push_back(temp);
    }


}
void func2(vector<ssset> setlist)
{
    int X;
    cin >> X;
    bool find = false;
    for (auto it = setlist.begin(); it != setlist.end(); it++)
    {
        for (auto i = it->setArray.begin(); i != it->setArray.end(); i++)
        {
            if (*i == X)
            {
                find = true;
                it->setArray.erase(i);
            }

         }
    }
    if (find==false)
    {
        ssset tempset;
        tempset.setArray.push_back(X);
        setlist.push_back(tempset);
    }
   

}
void func3(vector<ssset> setlist, vector <int>*output)
{
    int X;
    cin >> X;
    bool find = false;
    for (auto it = setlist.begin(); it != setlist.end(); it++)
    {
        for (auto i = it->setArray.begin(); i != it->setArray.end(); i++)
        {
            if (*i == X)
            {
                find = true;
                int temp= it->setArray.size();
                output->push_back(temp);
            }

        }
    }
  
}