//#include<iostream>
//#include <string.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<vector<vector<int> > > squ(0, vector<vector<int> >(0, vector<int>(0)));
//
//int main()
//{
//    
//    
//
//    int N, M;
//    cin >> N >> M;
//    for (int i = 0; i < N; i++)
//    {
//        vector<int> temp(4);
//        cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
//        int xMax = min(temp[0] + temp[2], 3840);
//        int yMax = min(temp[1] + temp[3], 2160);
//        for (int x = temp[0]; x < xMax; x++)
//        {
//            for (int y = temp[1]; y < yMax; y++)
//            {
//                squ[x][y][i] = 1;
//            }
//        }
//
//
//    }
//
//    for (int i = 0; i < M; i++)
//    {
//        vector<int> temp(2);
//        cin >> temp[0] >> temp[1];
//
//        bool noWindow = true;
//        for (int i = 999; i >= 0; i--)
//        {
//            if (squ[temp[0]][temp[1]][i] == 1)
//            {
//                cout << i << endl;
//                noWindow = false;
//                if (i == N - 1)
//                    ;
//                else
//                {
//                    int temp[3840][2160];
//                    for (int x = 0; x < 3840; x++)
//                    {
//                        for (int y = 0; y < 2160; y++)
//                        {
//                            temp[x][y] = squ[x][y][N - 1];
//                        }
//                    }
//                    for (int x = 0; x < 3840; x++)
//                    {
//                        for (int y = 0; y < 2160; y++)
//                        {
//                            squ[x][y][N - 1] = squ[x][y][i];
//                        }
//                    }
//                    for (int x = 0; x < 3840; x++)
//                    {
//                        for (int y = 0; y < 2160; y++)
//                        {
//                            squ[x][y][i] = temp[x][y];
//                        }
//                    }
//                }
//                continue;
//            }
//            if (noWindow)
//                cout << -1 << endl;;
//        }
//    }
//
//}