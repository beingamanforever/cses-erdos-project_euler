/**
 *    author:  compounding
 *    created: 2024-12-09 18:03:27
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
int n, sum;
vi a;
vb possible;
vvi cache;
int dp(int idx, int s)
{
    if (idx == n)
    {
        // s should be between 1 and sum
        if (s > 0 && s <= sum)
        {
            possible[s] = true;
            return 1;
        }
        return 0;
    }
    int &ans = cache[idx][s];
    if (ans != -1)
    {
        return ans;
    }
    int exclude = dp(idx + 1, s);
    int include = 0;
    if (s + a[idx] <= sum)
    {
        include = dp(idx + 1, s + a[idx]);
    }
    if (include || exclude)
    {
        possible[s] = true;
    }
    ans = include | exclude;
    return ans;
}

void solve()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    possible.assign(sum + 1, false);
    cache.assign(n + 1, vi(sum + 1, -1));
    dp(0, 0);
    vi res;
    for (int i = 1; i <= sum; i++)
    {
        if (possible[i])
        {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (auto &x : res)
    {
        cout << x << " ";
    }
    cout << endl;
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
