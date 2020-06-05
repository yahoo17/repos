#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    map<int, vector<int>> mp;
    bool divisorGame(int N) {
        if (N <= 2)
        {
            return true;
        }
        else if (N == 3)
        {
            return false;
        }
        else
        {
            if (mp.count(N) == 0)
            {
                for (int i = 1; i < N; i++)
                {
                    if (N % i == 0)
                        mp[N].push_back(i);
                }
            }
            
            
                for (auto x : mp[N])
                {
                    if (divisorGame(N - x) == false)
                        return true;
                }

            
        }
        return false;
    }
};
int main()
{
    Solution s;
    s.divisorGame(4);
}