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
const int mod1 = 1e9 + 7, mod2 = 998244353, INF = 2e16, N = 2e5 + 5, L = 19;
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
    // nth iterration -> node = x (is in cycle / connected to a cycle)
    // node x -> node y (which is in cycle for sure), node y -> cycle elements detected
    vi dist(n + 1, 0), p(n + 1, -1);
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.pb({u, v, wt});
    }
    int last;
    for (int i = 0; i < n; i++)
    {
        last = -1;
        for (auto &e : edges)
        {
            int u = e.a, v = e.b, c = e.wt;
            if (dist[u] != INF && dist[v] > (dist[u] + c))
            {
                dist[v] = max(-INF, dist[u] + c); // overflow avoid
                p[v] = u;
                last = v;
            }
        }
    }
    if (last == (-1))
    {
        no;
        return;
    }

    yes;
    vi cycle;
    int y = last;
    // y is at max (n-1) from cycle
    for (int i = 0; i < n; i++)
    {
        y = p[y];
    }
    // y now is in cycle for sure
    for (int cur = y;; cur = p[cur])
    {
        cycle.pb(cur);
        if (cur == y && cycle.size() > 1)
        {
            break;
        }
    }
    reverse(all(cycle));
    for (auto &x : cycle)
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