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
struct DSU
{
    vi parent, size;
    DSU(int n) : parent(n), size(n, 1)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int x, int y)
    {
        int xr = find(x), yr = find(y);
        if (xr == yr)
        {
            return false; // in same comp
        }
        if (size[xr] < size[yr])
        {
            swap(xr, yr);
        }
        parent[yr] = xr;
        size[xr] += size[yr];
        return true; // not in same comp
    }
    bool islink(int x, int y)
    {
        return find(x) == find(y);
    }
    int getsize(int x)
    {
        return size[find(x)];
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    int maxi = 1, num = n;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (dsu.unite(x, y))
        {
            // merge in x
            num--;
            maxi = max(maxi, dsu.getsize(x));
        }
        cout << num << " " << maxi << endl;
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