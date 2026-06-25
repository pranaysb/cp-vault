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
    ll k;
    cin >> k;
    for (ll x : v)
        cout << x << " ";
    cout << '\n';
    ll l = 0, r = n - 1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (v[mid] == target)
        {
            // found
            break;
        }
        else if (v[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    vector<ll> pref(n + 1, 0);
    for (ll i = 0; i < n; i++)
        pref[i + 1] = pref[i] + v[i];
    for (ll x : v)
        cout << x << " ";
    cout << '\n';
    for (ll i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
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