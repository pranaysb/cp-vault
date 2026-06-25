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
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        // int del = max_element(v.begin(), v.end()) - v.begin();
        //
        int sum = 0;
        int ans = 0;
        int delo = 0;
        for (int i = 1; i < n; i++)
        {
            int z;
            z = abs(v[i] - v[i + 1]) + abs(v[i] - v[i - 1]);

            if (z > sum)
            {
                sum = z;
                delo = i;
            }
        }
        v.erase(v.begin() + delo);
        for (int i = 1; i < n - 1; i++)
        {
            ans = ans + abs(v[i] - v[i - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}