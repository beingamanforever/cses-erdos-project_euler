/**
 *    author:  compounding
 *    created: 2024-10-16 21:58:39
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
vi adj[200005];
int n;
int depth1[200005], depth2[200005]; // from the two nodes
void bfs(int u, int par = -1)
{
    for (auto v : adj[u])
    {
        if (v != par)
        {
            depth1[v] = depth1[u] + 1;
            bfs(v, u);
        }
    }
}
void bfs2(int u, int par = -1)
{
    for (auto v : adj[u])
    {
        if (v != par)
        {
            depth2[v] = depth2[u] + 1;
            bfs2(v, u);
        }
    }
}
void solve()
{
    // basically find the end points of the diameter and the maximum distance from the end points
    // thats the answer
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // first bfs from node 1
    depth1[1] = 0;
    bfs(1);
    int maxe = 0, node = 1;
    for (int i = 1; i <= n; i++)
    {
        if (depth1[i] > maxe)
        {
            maxe = depth1[i];
            node = i;
        }
    }
    // second bfs from node 2
    depth1[node] = 0;
    bfs(node);
    maxe = 0;
    int node2 = node;
    for (int i = 1; i <= n; i++)
    {
        if (depth1[i] > maxe)
        {
            maxe = depth1[i];
            node2 = i;
        }
    }
    // bfs from the node 2
    depth2[node2] = 0;
    bfs2(node2);
    for (int i = 1; i <= n; i++)
    {
        cout << max(depth1[i], depth2[i]) << " ";
    }
    cout << endl;
    return;
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