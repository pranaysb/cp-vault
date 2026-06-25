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
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    vector<ll> b = v;
    sort(b.begin(), b.end(), greater<ll>());
    for (ll i = 0; i < n; i++)
    {
        if (b[i] != v[i])
        {

            ans = i;
            break;
        }
    }
    // if(ans>0){
    ll idx = max_element(v.begin() + ans, v.end()) - v.begin();
    // cout << idx << endl;
    if (ans != 0)
    {

        for (ll i = 0; i < ans; i++)
        {
            // cout << "pehla loop" << " ";
            cout << v[i] << " ";
        }
    }
    for (ll i = idx; i >= 0 + ans; i--)
    {
        // cout << "pehla2 loop" << " ";
        cout << v[i] << " ";
    }
    if (idx < n)
    {
        for (ll i = idx + 1; i < n - ans; i++)
        {
            // cout << "doosra loop" << " ";
            cout << v[i] << " ";
        }
    }
    // }
    // else{}

    cout << endl;
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