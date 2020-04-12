// 11111111.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include  <math.h>
#include <vector>
using namespace std;
struct point
{
    int x;
    int y;
    int value;
};
double getDistance(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
vector<int> lengthArray;
int main()
{
    //这题应该只保存有豆子的点
    int group;
    std::cin >> group;
    
    for (int i = 0; i < group; i++)
    {

        int size,length;
        std::cin >> size;
        std::cin >> length;
        vector<vector<point>> total;
        for (int i = 0; i < size; i++)
        {
            vector<point> singleLine;
            for (int j = 0; j < size; j++)
            {
                
                int temp;
                std::cin >> temp;
                if (temp != 0)
                {
                    point tempP;
                    tempP.x = i;
                    tempP.y = j;
                    tempP.value = temp;
                    singleLine.push_back(tempP);
                }
            }
            total.push_back(singleLine);
        }
        //录完了所以豆子

        int locX, locY;
        std::cin >> locX;
        std::cin >> locY;
        point loc;
        loc.x = locX;
        loc.y = locY;
        bool update = true;
        do
        {

            bool changeOrNot = false;
            for (int i = 0; i < size; i++)
            {
            //对每一行
           
                for (auto it=total[i].begin(); it != total[i].end(); it++)
                {
                    double dis = getDistance(loc, *it);
                    if (dis <= length&&it->value!=0)
                    {
                        length += it->value;
                        it->value = 0;                    
                        changeOrNot = true;
                    }
                }

            }
            if (changeOrNot == false)
            {
                update = false;
             }

        } while (update == true);
        lengthArray.push_back(length);
      
    }
    for (auto x : lengthArray)
        cout << x << endl;
}
