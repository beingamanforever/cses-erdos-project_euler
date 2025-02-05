/**
 *    author:  heWhoCooks
 *    created: 2025-01-09 12:11:16
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
const int L = 30; // binary lifting log2(n) + 1
#ifndef ONLINE_JUDGE
#include "heWhoCooks.cpp"
#else
#define debug(...)
#define debugArr(...)
#define __START__
#define __END__
#endif
int par[N][L];
int kth(int u, int k)
{
    for (int i = 0; i < L; i++)
    {
        if (k & (1LL << i))
        {
            u = par[u][i];
        }
    }
    return u;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> par[i][0];
    }
    for (int i = 1; i < L; i++)
    {
        for (int node; node <= n; node++)
        {
            par[node][i] = par[par[node][i - 1]][i - 1];
        }
    }
    while (q--)
    {
        int u, v; // u -> v
        cin >> u >> v;
        if (u == v)
        {
            cout << 0 << endl;
        }
        // if it's one of the parents of u
        int ans = -1;
        for (int i = 1; i < L; i++)
        {
            if (kth(u, i) == v)
            {
                cout << i << endl;
                ans = i;
                break;
            }
        }
        if (ans == (-1))
        {
            // means it's not it's parent, but in path there shouldn't be (u -> v) & (v -> u)
        }
    }
    return;
}

signed main()
{
    __START__;
    NeedForSpeed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    __END__;
    return 0;
}