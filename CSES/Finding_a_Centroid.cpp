/**
 *    author:  heWhoCooks
 *    created: 2025-01-12 07:22:04
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
// Centroid Decomposition
// int root = decomp(1, 1);
vector<int> tree[N];
int sz[N], lvl[N];
int getsize(int i, int p)
{
    sz[i] = 1;
    for (int j : tree[i])
    {
        // if not parent and not decomposed
        if (j != p && !lvl[j])
        {
            sz[i] += getsize(j, i);
        }
    }
    return sz[i];
}

int centroid(int i, int p, int n)
{
    // int root = centroid(1, -1, getsize(1, -1));
    for (int j : tree[i])
    {
        if (j != p && !lvl[j] && sz[j] > (n / 2))
        {
            return centroid(j, i, n);
        }
    }
    return i;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    int root = centroid(1, -1, getsize(1, -1));
    cout << root << endl;
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