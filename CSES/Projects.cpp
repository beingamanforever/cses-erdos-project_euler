/**
 *    author:  compounding
 *    created: 2024-12-07 18:04:38
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
void solve()
{
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].f.s >> a[i].f.f >> a[i].s;
    }
    sort(all(a));
    vi dp(n + 1, 0);
    // dp[i] -> maximum sum of the values of the segments ending at i
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        int l = 0, r = i - 1;
        // binary search to find the maximum index such that a[mid].f.f < a[i-1].f.s
        int pos = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (a[mid].f.f < a[i - 1].f.s)
            {
                l = mid + 1;
                pos = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        // pos+1, as pos is 0 based indexing
        dp[i] = max(dp[i], dp[pos + 1] + a[i - 1].s);
    }
    cout << dp[n] << endl;
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