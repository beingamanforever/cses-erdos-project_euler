#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;
#define f first
#define s second
#define pb push_back
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int mod1 = 1e9 + 7, mod2 = 998244353, INF = 2e18, N = 5e4 + 15, L = 19, K = 515;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// -----------------------------------------------------------------------------
vi adj[N];
int dp1[N][K], dp2[N][K], n, k;
void dfs1(int u, int p)
{
    dp2[u][0] = 1;
    for (auto &v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs1(v, u);
        for (int x = 1; x < K; x++)
        {
            dp2[u][x] += dp2[v][x - 1];
        }
    }
}
void dfs2(int u, int p)
{
    if (u == 1)
    {
        // root, dp1[u][x] = dp2[u][x]
        for (int x = 0; x < K; x++)
        {
            dp1[u][x] = dp2[u][x];
        }
    }
    else
    {
        for (int x = 0; x < K; x++)
        {
            dp1[u][x] = dp2[u][x] + ((x > 0 ? dp1[p][x - 1] : 0) - (x > 1 ? dp2[u][x - 2] : 0));
        }
    }
    for (auto &v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs2(v, u);
    }
}
void solve()
{
    // dp1(u,x) number nodes at distance of x from u
    // dp2(u,x) number of nodes at distance x from u, in it's subtree
    cin >> n >> k;
    for (int i = 1; i <= (n - 1); i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp1[i][k];
    }
    cout << (ans / 2) << endl;
    return;
}

signed main()
{
    // __START__;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    // __END__;
    return 0;
}