/**
 *    author:  compounding
 *    created: 2024-10-16 18:01:38
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
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
vi adj[200005];
int subtreesize[200005];
int dp[200005];
int n;
// calculate for node 1
void precompute(int u, int par, int depth = 0)
{
    dp[1] += depth;
    subtreesize[u] = 1;
    for (auto v : adj[u])
    {
        if (v != par)
        {
            precompute(v, u, depth + 1);
            subtreesize[u] += subtreesize[v];
        }
    }
}
// re-rooting
void dfs(int u, int par)
{
    for (auto v : adj[u])
    {
        if (v != par)
        {
            // one part is subtracted and another part is added
            dp[v] = dp[u] - subtreesize[v] + (n - subtreesize[v]);
            dfs(v, u);
        }
    }
}
void solve()
{

    cin >> n;
    for (int i = 1; i <= (n - 1); i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    precompute(1, 0);
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
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