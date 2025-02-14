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
    vvi adj(n + 1);
    vi outdegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
        outdegree[u]++;
    }
    if (m == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        return;
    }
    vi topo;
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (!outdegree[i])
        {
            pq.push(i);
        }
    }
    // topological labeling
    while (!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        topo.pb(node);
        for (auto &child : adj[node])
        {
            if (--outdegree[child] == 0)
            {
                pq.push(child);
            }
        }
    }
    reverse(all(topo));
    for (auto &x : topo)
    {
        cout << x << " ";
    }
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