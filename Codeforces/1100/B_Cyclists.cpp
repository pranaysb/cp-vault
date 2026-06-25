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
    ll n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int impo = *min_element(arr.begin(), arr.begin() + k);
    if (impo >= m && p > k)
    {
        cout << 0 << endl;
        return;
    }
    int egy = 0;
    p--;
    while (true)
    {
        if (p < k)
        {
            if (egy + arr[p] > m)
                break;
            egy += arr[p];
            ans++;
            ll good = arr[p];
            arr.erase(arr.begin() + p);
            arr.push_back(good);
            p = n - 1;
        }
        else
        {
            int midx = min_element(arr.begin(), arr.begin() + k) - arr.begin();
            if (egy + arr[midx] > m)
                break;
            egy += arr[midx];
            ll rem = arr[midx];
            arr.erase(arr.begin() + midx);
            arr.push_back(rem);
            if (midx < p)
                p--;
        }
    }
    cout << ans << endl;
}
// void solve()
// {
//     ll ans = 0;
//     ll n, k, p, m;
//     cin >> n >> k >> p >> m;
//     vector<int> arr(n);
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     //   int maxi = *max_element(car.begin(), car.end());
//     int impo = *min_element(arr.begin(), arr.begin() + k);
//     if (impo >= m && p > k)
//     {
//         cout << 0 << endl;
//     }
//     else

//     {
//         int egy = 0;
//         if (p <= k)
//         {
//             ll good = arr[p - 1];
//             p = n - 1;
//             arr.erase(arr.begin() + k - 1);
//             arr.push_back(good);
//         }
//         if (p > k)
//         {

//             ll love = arr[p - 1];
//             while (egy <= m)
//             {
//                 ll check = 0;
//                 ll timefor1st = p - k;
//                 for (ll i = 0; i < timefor1st; i++)
//                 {
//                     int midx = min_element(arr.begin(), arr.begin() + k) - arr.begin();
//                     ll rem = arr[midx];
//                     arr.push_back(arr[midx]);
//                     arr.erase(arr.begin() + midx);
//                     egy = egy + rem;
//                     if (egy > m)
//                     {
//                         break;
//                     }
//                     if (i == p - k - 1)
//                     {
//                         check = 1;
//                     }
//                 }

//                 if (check)

//                 {
//                     p = k;
//                     egy = egy + arr[p - 1];
//                     arr.push_back(arr[p - 1]);
//                     arr.erase(arr.begin() + k - 1);
//                     ans++;
//                     p = n;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }
//     }
//     cout << ans << endl;
// }

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