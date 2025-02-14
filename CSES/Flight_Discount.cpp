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
    int u, v, w;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vpi> adj1(n + 1), adj2(n + 1);
    vi dis1(n + 1, INF), dis2(n + 1, INF);
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj1[u].pb({v, w});
        adj2[v].pb({u, w});
        edges.pb({u, v, w});
    }
    auto djk = [&](int s, vi &dis, vector<vpi> &adj)
    {
        priority_queue<pi, vpi, greater<pi>> pq;
        pq.push({0, s});
        dis[s] = 0;
        while (!pq.empty())
        {
            auto [cdist, u] = pq.top();
            pq.pop();
            if (cdist > dis[u]) // outated
            {
                continue;
            }
            for (auto &[v, w] : adj[u])
            {
                if (dis[v] > cdist + w)
                {
                    dis[v] = cdist + w;
                    pq.push({dis[v], v});
                }
            }
        }
    };
    djk(1, dis1, adj1);
    djk(n, dis2, adj2);
    int ans = INF;
    for (auto &[u, v, w] : edges)
    {
        ans = min(ans, dis1[u] + dis2[v] + w / 2);
    }
    cout << ans << endl;
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

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto &child : adj[node])
    {
        if (!vis[child])
            dfs(child, vis, adj, st);
    }
    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto &child : adj[node])
    {
        if (!vis[child])
            dfs2(child, vis, adj);
    }
}

int kosaraju(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, st);
    }

    vector<int> adji[n];
    for (int i = 0; i < n; i++)
    {
        for (auto &it : adj[i])
            adji[it].push_back(i);
        vis[i] = 0;
    }

    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            dfs2(node, vis, adji);
        }
    }
    return scc;
}