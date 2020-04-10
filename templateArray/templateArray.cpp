#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//
vector<double> result;
void printPercent(int score, vector<int> scoreVector,int size)
{
   
    auto it = find(scoreVector.begin(), scoreVector.end(), score);
    
    if (it == scoreVector.end())
        cout << fixed << setprecision(6) << 100 << endl;
    else
    {
        int index = it - scoreVector.begin();
        double percent = index *100.0/ size;
        result.push_back(percent);

        
    }
        
}
int main()
{
    int size;
    cin >> size;
    vector<int> score;
    int temp;
    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        score.push_back(temp);
    }
    vector<int> sortScore = score;
    sort(sortScore.begin(), sortScore.end());
    int num;
    cin >> num;
    num=num > size ? size : num;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        printPercent(score[temp-1], sortScore,size);
    }
    for (auto x : result)
    {
        cout << fixed << setprecision(6) << x << endl;
    }
}