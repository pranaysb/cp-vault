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

// ll minVal = *min_element(v.begin(), v.end());
// ll maxVal = *max_element(v.begin(), v.end());
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Create a frequency array for the k independent groups
    vll count1(k, 0);

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            count1[i % k]++;
        }
    }

    // If any group has an odd number of '1's, it's impossible
    for (ll i = 0; i < k; i++)
    {
        if (count1[i] % 2 != 0)
        {
            no;
            return;
        }
    }

    yes;
}
int main()
{
    fastio;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}