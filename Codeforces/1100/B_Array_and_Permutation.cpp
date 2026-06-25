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
    // ll ans = 0;
    // ll n;
    // cin >> n;
    // int v[n];
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    // }
    // int a[n];
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // for (ll i = 0; i < n; i++)
    // {

    //     if (i == 0)
    //     {
    //         if (v[0] != a[0])
    //         {
    //             if (v[1] != a[0])
    //             {
    //                 ans = -1;
    //             }
    //         }
    //     }
    //     if (i == n - 1)
    //     {
    //         if (v[n - 1] != a[n - 1])
    //         {
    //             if (v[n - 2] != a[n - 1])
    //             {
    //                 ans = -1;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         if (v[i] != a[i])

    //         {
    //             if (v[i - 1] != a[i] && v[i + 1] != a[i])
    //             {
    //                 ans = -1;
    //                 break;
    //             }

    //             else
    //             {
    //                 if (v[i - 1] == a[i])
    //                 {
    //                     v[i] = a[i];
    //                 }
    //                 if (v[i + 1] == a[i])
    //                 {
    //                     v[i] = a[i];
    //                 }
    //             }
    //         }
    //     }
    // }

    // if (ans == -1)
    // {
    //     cout << "NO" << endl;
    // }
    // else
    // {
    //     cout << "YES" << endl;
    // }
    // a from 1 to n
    // so
    ll n;
    cin >> n;
    int v[n], a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int see1[n + 1];
    for (ll i = 0; i <= n; i++)
    {
        see1[i] = -1;
    }
    int seen[n + 1];
    for (ll i = 0; i <= n; i++)
    {
        seen[i] = -1;
    }
    for (ll i = 0; i < n; i++)
    {
        if (see1[a[i]] == -1)
        {
            see1[a[i]] = i;
        }
        seen[a[i]] = i;
    }
    int place[n + 1];
    for (ll i = 0; i < n; i++)
    {
        place[v[i]] = i;
    }
    for (ll i = 0 + 1; i < n + 1; i++)
    {
        if (see1[i] == -1)
            continue;

        {
            for (ll j = see1[i]; j <= seen[i]; j++)
            {
                if (a[j] != i)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        // if (place[i] < see1[i] || place[i] > seen[i])
        // {
        //     cout << "NO" << endl;
        //     return;
        // }
    }
    cout << "YES\n";
}

void check()
{
    ll n;
    ll ans = 0;
    cin >> n;
    int v[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        int j = i - 1, k = i + 1;
        int now = i;
        if (v[i] != a[i])
        {

            while (j >= 0 && v[j] != a[i])
            {
                j--;
                if (j >= 0)
                {
                    // if (v[j] == a[i])
                    {
                        // if (j < i)
                        // {
                        for (ll m = i; m > j; m--)
                        {
                            v[m] = v[j];
                        }
                        // }
                        break;
                    }
                }
            }
            while (k < n && v[k] != a[i])
            {
                k++;
                if (k < n)
                {
                    // if (v[k] == a[i])
                    {
                        // else if (j > i)
                        // {

                        for (ll m = i; m < k; m++)
                        {
                            v[m] = v[k];
                        }
                        // }
                        break;
                    }
                }
            }

            // while ((j >= 0) && (k <= n - 1))

            // {
            //     int doj = 1;
            //     int dok = 1;
            //     if (j-- != -1)
            //     {
            //         j--;
            //     }
            //     else
            //     {
            //         doj = 0;
            //         break;
            //     }
            //     if (k++ != n)
            //     {

            //         k++;
            //     }
            //     else
            //     {
            //         dok = 0;
            //         break;
            //     }

            //     if (doj)
            //     {
            //         j++;
            //         if (v[j] == a[i])
            //         {
            //             // if (j < i)
            //             // {
            //             for (ll m = i; m > j; m--)
            //             {
            //                 v[m] = v[j];
            //             }
            //             // }
            //             break;
            //         }
            //     }
            //     if (dok)
            //     {
            //         k--;
            //         if (v[k] == a[i])
            //         {
            //             // else if (j > i)
            //             // {

            //             for (ll m = i; m < j; m++)
            //             {
            //                 v[m] = v[k];
            //             }
            //             // }
            //             break;
            //         }
            //     }
            // }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (a[i] != v[i])
        {
            ans = -1;
        }
    }
    if (ans == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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