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
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    // vector<int> v(m);
    // for (ll i = 0; i < m; i++)
    // {
    //     if ((i + 1) % a == 0)
    //         v[i]++;
    //     if ((i + 1) % b == 0)
    //         v[i]++;
    //     if ((i + 1) % c == 0)
    //         v[i]++;
    // }
    ll alice = 0;
    ll bob = 0;
    ll car = 0;
    // for (ll i = 0; i < m; i++)
    // {
    //     if ((i + 1) % a == 0)
    //     {
    //         if (v[i] == 1)
    //             alice = alice + 6;
    //         if (v[i] == 2)
    //             alice = alice + 3;
    //         if (v[i] == 3)
    //             alice += 2;
    //     }

    //     if ((i + 1) % b == 0)
    //     {
    //         if (v[i] == 1)
    //             bob += 6;
    //         if (v[i] == 2)
    //             bob += 3;
    //         if (v[i] == 3)
    //             bob += 2;
    //     }
    //     if ((i + 1) % c == 0)
    //     {
    //         if (v[i] == 1)
    //             car += 6;
    //         if (v[i] == 2)
    //             car += 3;
    //         if (v[i] == 3)
    //             car += 2;
    //     }
    // }

    // for (long long i = 1; i <= m; i++)
    // {
    //     int now = 0;

    //     if (i % a == 0)
    //         now++;
    //     if (i % b == 0)
    //         now++;
    //     if (i % c == 0)
    //         now++;

    //     if (i % a == 0)
    //     {
    //         if (now == 1)
    //             alice += 6;
    //         else if (now == 2)
    //             alice += 3;
    //         else if (now == 3)
    //             alice += 2;
    //     }

    //     if (i % b == 0)
    //     {
    //         if (now == 1)
    //             bob += 6;
    //         else if (now == 2)
    //             bob += 3;
    //         else if (now == 3)
    //             bob += 2;
    //     }

    //     if (i % c == 0)
    //     {
    //         if (now == 1)
    //             car += 6;
    //         else if (now == 2)
    //             car += 3;
    //         else if (now == 3)
    //             car += 2;
    //     }
    // }
    ll albob = lcm(a, b);
    ll bobcar = lcm(b, c);
    ll alcar = lcm(a, c);

    ll atot = m / a;
    ll btot = m / b;
    ll ctot = m / c;

    ll albobt = m / albob;
    ll bobcart = m / bobcar;
    ll alcart = m / alcar;

    ll altog = m / (lcm(albob, c));

    ll onlyab = albobt - altog;
    ll onlybc = bobcart - altog;
    ll onlyac = alcart - altog;

    ll onlya = atot - onlyab - onlyac - altog;
    ll onlyb = btot - onlybc - onlyab - altog;
    ll onlyc = ctot - onlybc - onlyac - altog;

    alice = onlya * 6 + (onlyab + onlyac) * 3 + altog * 2;
    bob = onlyb * 6 + (onlyab + onlybc) * 3 + altog * 2;

    car = onlyc * 6 + (onlyac + onlybc) * 3 + altog * 2;

    cout << alice << " " << bob << " " << car << endl;
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