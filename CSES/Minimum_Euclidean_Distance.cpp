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
    int n;
    cin >> n;
    vpi points;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.pb({x, y});
    }
    sort(all(points));
    // keep points (x-d, x) and in set sorted acc to y
    set<pi> s;
    int j = 0, maxi = INF;
    for (int i = 0; i < n; i++)
    {
        int d = (sqrtl(maxi));
        while ((j < i) && (points[i].f - points[j].f) >= d)
        {
            s.erase({points[j].s, points[i].f});
            j++;
        }
        auto it1 = s.lower_bound({points[i].s - d, -INF});
        auto it2 = s.upper_bound({points[i].s + d, INF});
        for (auto it = it1; it != it2; it++)
        {
            int dx = points[i].f - it->second, dy = points[i].s - it->first;
            maxi = min(maxi, 1LL * dx * dx + 1LL * dy * dy);
        }
        s.insert({points[i].s, points[i].f});
    }
    cout << maxi << endl;
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