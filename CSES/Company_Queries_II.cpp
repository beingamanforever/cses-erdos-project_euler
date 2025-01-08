/**
 *    author:  heWhoCooks
 *    created: 2025-01-09 04:04:14
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
typedef pair<int, int> pi;
#define f first
#define s second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define set_bits __builtin_popcountll
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
#define M_PI 3.14159265358979323846264338327950288
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const long long INF = 2e18;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
const int N = 2e5 + 5;
const int L = 27; // binary lifting log2(n) + 1
#ifndef ONLINE_JUDGE
#include "heWhoCooks.cpp"
#else
#define debug(...)
#define debugArr(...)
#define __START__
#define __END__
#endif
// Binary Lifting
// N = 1e5 + 5, L = 20;
int dep[N], par[N][L];
vector<int> adj[N];
void dfs(int i, int p)
{
    dep[i] = dep[p] + 1;
    par[i][0] = p;
    for (int l = 1; l < L; ++l)
    {
        par[i][l] = par[par[i][l - 1]][l - 1];
    }
    for (int j : adj[i])
    {
        if (j != p)
        {
            dfs(j, i);
        }
    }
}

int lca(int a, int b)
{
    if (dep[a] < dep[b])
    {
        swap(a, b);
    }
    for (int l = L - 1; l >= 0; --l)
    {
        if ((dep[a] - dep[b]) >> l)
        {
            a = par[a][l];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int l = L - 1; l >= 0; --l)
    {
        if (par[a][l] != par[b][l])
        {
            a = par[a][l];
            b = par[b][l];
        }
    }
    return par[a][0];
}

// kth ancestor
int kth(int u, int k)
{
    for (int l = 0; l < L; ++l)
    {
        if (k & (1 << l))
        {
            u = par[u][l];
        }
    }
    return u;
}

int dist(int u, int v)
{
    int l = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[l];
}

// kth node from u to v, 0th node is u
int go(int u, int v, int k)
{
    int l = lca(u, v);
    int d = dep[u] + dep[v] - 2 * dep[l];
    if (k <= (dep[u] - dep[l]))
    {
        return kth(u, k);
    }
    k -= dep[u] - dep[l];
    return kth(v, dep[v] - dep[l] - k);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    dfs(1, 0);
    debug(adj);
    debug(dep);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return;
}

signed main()
{
    __START__;
    NeedForSpeed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    __END__;
    return 0;
}