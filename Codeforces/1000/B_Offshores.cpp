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
        if (n % i == 0)
            return false;
    return true;
}

void solve()
{
    ll ans = 0;
    ll n;
    ll x;
    cin >> x;
    ll y;
    cin >> y;
    cin >> n >> x >> y;
    vector<ll> v(n);
    int maxi = 0;
    int count = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        count = count + (v[i] / x) * y;
        if (maxi <= (v[i] % x))
        {
            maxi = v[i] % x;
            ans = i;
        }
    }
    int total = count - ((v[ans] / x) * y);
    cout << v[ans] + total << endl;
}

int main()
{
    fastio
        ll t;
    cin >> t;
    while (t--)
    {
        //
        int n, x, y;
        cin >> n >> x >> y;
        ll arr[n];
        ll ans = 0;
        ll diff = 0;
        ll note = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            ans = ans + (arr[i] / x) * y;
        }
        // int barr[n];
        // for (int i = 0; i < n; i++)
        // {

        //     barr[i] = arr[i] % x;
        // }
        // int largest = *std::max_element(barr, barr + n);
        // int *max_ptr = std::max_element(barr, barr + n);
        // int maxi = max_ptr - barr;
        // // cout << maxi << endl;
        // ll rem = (arr[maxi] / x) * y;
        ll remi = 0;
        for (int i = 0; i < n; i++)
        {
            ll now = arr[i] + ans - (arr[i] / x) * y;
            remi = max(remi, now);
        }
        cout << remi << endl;
    }
    return 0;
}