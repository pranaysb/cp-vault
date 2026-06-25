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
    // cin >> t;
    // while (t--)
    // {
    int n;
    cin >> n;

    int arr[n];
    int barr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cin >> barr[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == barr[j])
            {
                count++;
            }
        }
    }
    cout << count << endl;
    // }
    return 0;
}