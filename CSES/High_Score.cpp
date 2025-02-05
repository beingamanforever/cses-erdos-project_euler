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

struct edge
{
    int a, b, wt;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    vvi adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        edges[i] = {a, b, x};
        adj[a].pb(b);
    }
    vi dist(n + 1, -INF);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto &e : edges)
        {
            if (dist[e.a] > -INF)
            {
                dist[e.b] = max(dist[e.b], dist[e.a] + e.wt);
            }
        }
    }
    vi cycle(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto &e : edges)
        {
            if (dist[e.a] > -INF && dist[e.b] < dist[e.a] + e.wt)
            {
                dist[e.b] = INF;
                cycle[e.b] = 1;
            }
        }
    }
    // if n is reachable from cycle nodes, then -1
    queue<int> q;
    vi vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (cycle[i])
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int next : adj[node])
        {
            if (!vis[next])
            {
                vis[next] = 1;
                q.push(next);
            }
        }
    }
    if (vis[n])
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[n] << endl;
    }
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