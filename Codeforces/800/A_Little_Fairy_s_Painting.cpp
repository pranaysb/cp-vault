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
        vector<int> arr;
        vector<int> count(1001, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
            count[x] = 1;
        }
        int sum = 0;
        for (int i = 0; i < 1001; i++)
        {
            sum = sum + count[i];
        }
        int maxi = sum;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= maxi)
            {

                ans = min(arr[i], ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}