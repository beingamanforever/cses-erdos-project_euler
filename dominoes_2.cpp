#include <bits/stdc++.h>
// #include <atcoder/all>
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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod1 = 1e9 + 7, mod2 = 998244353, INF = 2e18, N = 2e5 + 5, L = 19;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// -----------------------------------------------------------------------------

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    vi adj[n + 1];
    vi vis(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v); // u -> v edge
    }
    function<void(int)> dfs = [&](int u)
    {
        vis[u] = 1;
        for (auto &v : adj[u])
        {
            if (!vis[v])
            {
                dfs(v);
            }
        }
    };
    for (int i = 0; i < l; i++)
    {
        int node;
        cin >> node;
        if (!vis[node])
        {
            dfs(node);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return;
}

signed main()
{
    // __START__;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // __END__;
    return 0;
}