/**
 *    author:  compounding
 *    created: 2024-09-24 02:04:58
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
void solve()
{
    int x, n;
    cin >> x >> n;
    set<int> s;      // as points are unique and we want upperbound
    multiset<int> m; // as distances can be repeated
    s.insert(0);
    s.insert(x);
    m.insert(x);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        auto it = s.upper_bound(a);
        auto it1 = it;
        it1--;
        m.erase(m.find(*it - *it1));
        m.insert(a - *it1);
        m.insert(*it - a);
        s.insert(a);
        // m.rbegin() -> last position's iterator
        cout << *m.rbegin() << " ";
    }
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