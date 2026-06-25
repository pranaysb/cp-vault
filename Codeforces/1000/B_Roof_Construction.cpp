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

        // concept of Xor says that when remainder is 0 then N if 1 then 1 and if 2 then N+1 if 3 then 0
        int n;
        cin >> n;
        if (n % 4 == 0)
            cout << n << endl;
        if (n % 4 == 1)
            cout << 1 << endl;
        if (n % 4 == 2)
            cout << n + 1 << endl;
        if (n % 4 == 3)
            cout << 0 << endl;
    }
    return 0;
}