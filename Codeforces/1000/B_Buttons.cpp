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
    long long int n;
    cin >> n;
    int ans = n;
    for (int i = 1; i < n; i++)
    {
        ans = ans + (n - i - 1) + (i) * (n - i - 1) + 1;
    }
    cout << ans;
    // }
    return 0;
}