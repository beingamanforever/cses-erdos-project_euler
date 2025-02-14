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
    vector<vpi> adj(n + 1);
    vi dis(n + 1, INF), maxi(n + 1, -1), mini(n + 1, INF), cnt(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    priority_queue<pi, vpi, greater<pi>> pq;
    pq.push({0, 1});
    dis[1] = 0, cnt[1] = 1, mini[1] = 0, maxi[1] = 0;
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u]) // outdated
        {
            continue;
        }
        for (auto [v, wt] : adj[u])
        {
            if (dis[v] > d + wt)
            {
                dis[v] = d + wt;
                cnt[v] = cnt[u];       // number of shortest paths
                mini[v] = mini[u] + 1; // minimum paths
                maxi[v] = maxi[u] + 1; // maximum paths
                pq.push({dis[v], v});
            }
            else if (dis[v] == d + wt)
            {
                cnt[v] = (cnt[v] + cnt[u]) % mod1;
                mini[v] = min(mini[v], mini[u] + 1);
                maxi[v] = max(maxi[v], maxi[u] + 1);
            }
        }
    }
    cout << dis[n] << " " << cnt[n] << " " << mini[n] << " " << maxi[n] << endl;
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