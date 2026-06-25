using namespace std;
#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <limits>
#include <bitset>
#include <iomanip>
#include <functional>
#include <tuple>
#include <utility>
#include <cassert>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES\n"
#define no cout << "NO\n"

using ll = long long;
using vll = vector<ll>;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    ll ans = 0;
    int n;
    cin >> n;
    int arr[n][n];
    vector<int> car(n * n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            car[arr[i][j]]++;
        }
    }
    int maxi = *max_element(car.begin(), car.end());
    if (maxi <= (n) * (n - 1))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    fastio
        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}