/**
 *    author:  compounding
 *    created: 2024-12-09 16:41:18
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
const int N = 2005;
int n;
int totalsum;
vi a;
vvi cache;
// binary exponentiation
int binpow(int a, int b, int m = (int)1e9 + 7)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
int dp(int idx, int sum)
{
    if (idx == n)
    {
        if (sum == totalsum - sum)
        {
            return 1;
        }
        return 0;
    }
    int &ans = cache[idx][sum];
    if (ans != -1)
    {
        return ans;
    }
    int include = dp(idx + 1, sum + a[idx]);
    int exclude = dp(idx + 1, sum);
    ans = (include + exclude) % mod;
    return ans;
}
void solve()
{
    // TODO: Two Sets II, CSES
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
        totalsum += i;
    }
    if (totalsum % 2)
    {
        cout << 0 << endl;
        return;
    }
    cache.assign(n, vi(totalsum + 1, -1));
    cout << (dp(0, 0) * binpow(2, mod - 2)) % mod << endl;
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