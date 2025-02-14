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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vpi> adj(n + 1);
    // maintain k shortest path for each city
    vector<priority_queue<int>> bes(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        // adj[v].pb({u, w});
    }
    priority_queue<pi, vpi, greater<pi>> pq;
    pq.push({0, 1});
    bes[1].push(0);
    while (!pq.empty())
    {
        auto [cdist, u] = pq.top();
        pq.pop();
        if (cdist > bes[u].top()) // outdated
        {
            continue;
        }
        for (auto [v, wt] : adj[u])
        {
            int temp = cdist + wt;
            if (bes[v].size() < k) // can include
            {
                bes[v].push(temp);
                pq.push({temp, v});
            }
            else if (temp < bes[v].top()) // remove top
            {
                bes[v].pop();
                bes[v].push(temp);
                pq.push({temp, v});
            }
        }
    }
    vi ans;
    while (!bes[n].empty())
    {
        ans.pb(bes[n].top());
        bes[n].pop();
    }
    reverse(all(ans));
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
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