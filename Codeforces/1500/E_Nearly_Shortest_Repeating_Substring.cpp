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
        long long int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 1 or n == 2)
        {
            cout << 1 << "\n";
            continue;
        }
        long long int ans = n;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                long long int len = i;
                long long int f = 1;
                long long int misses = 0;
                long long int cnt = 0, cnt1 = 0;
                for (int j = 0; j <= (n / len) - 1; j++)
                {
                    long long int p1 = 0, p2 = len * j;
                    while (p1 < len)
                    {
                        if (s[p1] == s[p1 + p2])
                        {
                            cnt++;
                        }
                        p1++;
                    }
                }
                for (int j = 0; j <= n / len; j++)
                {
                    long long int p1 = 0, p2 = len * j;
                    while (p1 < len)
                    {
                        if (s[len + p1] == s[p1 + p2])
                        {
                            cnt1++;
                        }
                        p1++;
                    }
                }
                long long int val = n - 1;
                if (cnt >= val or cnt1 >= val)
                {
                    ans = len;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}