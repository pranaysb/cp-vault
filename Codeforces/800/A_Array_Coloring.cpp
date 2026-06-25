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
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i > 1)
            {
                if (arr[i - 2] == arr[i] - 1 || arr[i - 2] == arr[i] + 1)
                    ans = 1;
            }
            else
            {
                if (i == 1)
                {
                    if (arr[i - 1] == arr[i] - 2 || arr[i - 1] == arr[i] + 2)
                        ans = 1;
                }
            }
        }
        if (ans == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}