// bits/stdc++.h replacement
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <limits>
using namespace std;

int main()
{

    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, m;
        cin >> n >> m;
        vector<int> ver(n, 0);
        vector<int> hor(m, 0);
        vector<string> matrix(n);
        for (long long int i = 0; i < n; i++)
        {
            cin >> matrix[i];
        }

        long long int no = 0;
        // for (long long int i = 1; i < n; i++)
        // {
        //     for (long long int j = 1; j < m; j++)
        //     {
        //         if (matrix[i][j] == '1')
        //         {
        //             if()
        //             }

        //         }
        //     }
        // }
        int sex[n][m];
        memset(sex, 0, sizeof(sex));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sex[i][j] = matrix[i][j] - '0';
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (sex[i][j] == 1)
                {
                    ver[i]++;
                    hor[j]++;
                    if (ver[i] != j + 1 && hor[j] != i + 1)
                    {
                        no++;
                        break;
                    }
                }
            }
        }

        if (no)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}