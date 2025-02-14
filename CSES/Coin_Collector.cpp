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
    int n, m;
    cin >> n >> m;
    vi value(n + 1);
    vvi adj(n + 1), tadj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        tadj[v].pb(u);
    }
    int numcomp = 0;
    vi vis(n + 1, 0), comp(n + 1, 0);
    stack<int> s;
    function<void(int)> dfs1 = [&](int u)
    {
        vis[u] = 1;
        for (auto &v : adj[u])
        {
            if (!vis[v])
            {
                dfs1(v);
            }
        }
        s.push(u);
    };
    function<void(int)> dfs2 = [&](int u)
    {
        vis[u] = 1;
        comp[u] = numcomp;
        for (auto &v : tadj[u])
        {
            if (!vis[v])
            {
                dfs2(v);
            }
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    fill(all(vis), 0);
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!vis[node])
        {
            numcomp++;
            dfs2(node);
        }
    }
    vi group(numcomp + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        group[comp[i]] += value[i];
    }
    vvi cgraph(numcomp + 1);
    for (int i = 1; i <= n; i++)
    {
        for (auto &j : adj[i])
        {
            if (comp[i] != comp[j])
            {
                // cgraph, i -> j
                cgraph[comp[i]].pb(comp[j]);
            }
        }
    }
    vi cache(numcomp + 1, 0);
    function<int(int)> dp = [&](int i)
    {
        if (cache[i])
        {
            return cache[i];
        }
        cache[i] = group[i];
        for (auto &j : cgraph[i])
        {
            cache[i] = max(cache[i], dp(j) + group[i]);
        }
        return cache[i];
    };
    int ans = 0;
    for (int i = 1; i <= numcomp; i++)
    {
        ans = max(ans, dp(i));
    }
    cout << ans << endl;
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