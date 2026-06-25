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
#include <limits>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int maxi = 0;
        int negmini = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] >= 0)
            {
                if (arr[i] >= maxi)
                {
                    maxi = arr[i];
                }
            }
            if (arr[i] < 0)
            {
                if (arr[i] < negmini)
                    negmini = arr[i];
            }
        }
        vector<int> dar(maxi + 1, 0);
        for (int i = 0; i < maxi + 1; i++)
        {
            if (arr[i] >= 0)
            {

                dar[arr[i]]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dar[i] == 0)
            {

                ans = i;
                break;
            }
        }
        // int c = 0;
        // while (ans != 0)
        // {
        //     if (dar[c] == 0)
        //     {
        //         ans = c + 1;
        //     }
        //     c++;
        // }
        cout << ans - negmini << endl;
    }
    return 0;
}