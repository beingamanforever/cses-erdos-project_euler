/**
 *    author:  compounding
 *    created: 2024-10-31 18:47:52
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
void solve()
{
    int n, m;
    cin >> n >> m;
    vpi adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int ans = 0;
    // prim's algorithm for MST
    vi vis(n + 1, 0), mincost(n + 1, INT_MAX);
    set<pair<int, int>> s;
    mincost[1] = 0;
    // ({weight, vertex})
    s.insert({0, 1});
    vis[1] = 1;
    while (!s.empty())
    {
        auto [w, u] = *s.begin();
        s.erase(s.begin());
        vis[u] = 1;
        ans += w;
        for (auto &[v, weight] : adj[u])
        {
            // we will add the edge only if it leads to an unexplored vertex
            // and the weight of the edge is less than the minimum cost to reach that vertex
            if (!vis[v] && (mincost[v] > weight))
            {
                // erase else it would be O(ElogE)
                s.erase({mincost[v], v});
                mincost[v] = weight;
                // now O(ElogV)
                s.insert({mincost[v], v});
            }
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else
    {
        cout << ans << endl;
        return;
    }
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