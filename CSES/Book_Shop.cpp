/**
 *    author:  compounding
 *    created: 2024-12-05 17:16:51
 **/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpi;
#define f first
#define s second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
vi price;
vi pages;
vi dp;
void solve()
{
    int n, x;
    cin >> n >> x;
    price.resize(n); // cost to include in knapsack
    pages.resize(n); // value to include in knapsack
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    dp.resize(x + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            if ((j - price[i]) >= 0)
            {
                dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
            }
        }
    }
    cout << dp[x] << endl;
    return;
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}