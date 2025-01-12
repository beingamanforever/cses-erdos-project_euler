/**
 *    author:  heWhoCooks
 *    created: 2025-01-12 07:46:58
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
const int L = 24; // binary lifting log2(n) + 1
#ifndef ONLINE_JUDGE
#include "heWhoCooks.cpp"
#else
#define debug(...)
#define debugArr(...)
#define __START__
#define __END__
#endif
vi adj[N];
int c[N], ans[N];
set<int> *s[N]; // pointer to set
void solve()
{
    // small to large merging, dsu on tree
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    function<void(int, int)> dfs = [&](int u, int p)
    {
        int maxi = 0, maxnode = -1;
        for (auto v : adj[u])
        {
            if (v != p)
            {
                dfs(v, u);
                // it's a pointer so arrow (->)
                if (s[v]->size() > maxi)
                {
                    maxi = s[v]->size();
                    maxnode = v;
                }
            }
        }
        if (maxnode == -1)
        {
            s[u] = new set<int>();
        }
        else
        {
            s[u] = s[maxnode];
        }
        // now merge smaller to larger
        s[u]->insert(c[u]);
        for (auto &v : adj[u])
        {
            if (v != p && v != maxnode)
            {
                for (auto &color : *s[v]) // dereferenced for access
                {
                    s[u]->insert(color);
                }
            }
        }
        ans[u] = s[u]->size();
    };
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
