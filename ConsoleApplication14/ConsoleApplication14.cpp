﻿// ConsoleApplication14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
class LRUCache {
public:
    queue<int> que;
    map<int, int> mp;
    int limit;


    LRUCache(int capacity) :limit(capacity) {


    }

    int get(int key) {
        auto it = find(que.front(),que.back(), key);
        if(it==que.)

    }

    void put(int key, int value) {
        mp.insert(make_pair(key, value));
        que.push(key);
        if (que.size() > limit)
            que.pop();


    }
};

int main()
{   
   
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
