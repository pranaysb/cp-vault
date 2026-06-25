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
    int j = 0;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int count = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                count = 0;
            else
            {
                count++;
            }

            if (count == m)
            {
                ans++;
                count = 0;
                i = i - 1 + k;
            }
        }
        cout << ans << endl;
    }
    return 0;
}