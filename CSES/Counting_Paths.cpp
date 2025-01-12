/**
 *    author:  heWhoCooks
 *    created: 2025-01-12 17:58:11
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
#define rall(x) (x).rbegin(), (x).rend()
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
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const long long INF = 2e18;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
const int N = 2e5 + 5;
const int L = 18; // binary lifting log2(n) + 1
#ifndef ONLINE_JUDGE
#include "heWhoCooks.cpp"
#else
#define debug(...)
#define debugArr(...)
#define __START__
#define __END__
#endif
int dep[N], par[N][L], cnt[N];
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
    for (int l = L - 1; l >= 0; l--)
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
void dfs2(int i, int p)
{
    for (int j : adj[i])
    {
        if (j != p)
        {
            dfs2(j, i);
            cnt[i] += cnt[j];
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= (n - 1); i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    // paths now
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        int l = lca(u, v);
        cnt[u] += 1;
        cnt[v] += 1;
        cnt[l] -= 1;
        // if it's root then only decrease once
        if (par[l][0] != 0)
        {
            // above lca, it should all be zero
            cnt[par[l][0]]--;
        }
    }
    dfs2(1, 0);
    debug(cnt);
    for (int i = 1; i <= n; i++)
    {
        cout << cnt[i] << " ";
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