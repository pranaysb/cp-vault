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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        string s;
        // cin >> s;
        // cout << s << endl;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                arr[i] = 1;
            // cout << arr[i];
        }
        // cout << endl;
        int i = 0;
        while (1)
        {
            if (arr[i] == 1)
            {
                for (int j = i + 1; j < i + 1 + k; j++)
                {
                    arr[j] = 1;
                    if (j == n - 1)
                        break;
                }
                if (i + k + 1 >= n)
                    break;
                else
                    i = i + k + 1;
            }
            else
                i = i + 1;
            if (i == n - 1)
                break;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            // if (arr[i] == 0)
            // ans++;
        }
        cout << endl;
        // cout << ans << endl;
    }
    return 0;
}