/**
 *    author:  compounding
 *    created: 2024-12-09 16:53:12
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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int n;
int totalsum;
void solve()
{
    cin >> n;
    totalsum = n * (n + 1) / 2;
    if (totalsum % 2)
    {
        cout << "NO" << endl;
        return;
    }
    int req = totalsum / 2;
    vi a, b;
    for (int i = n; i >= 1; i--)
    {
        if (i <= req)
        {
            // include it in set 1
            a.push_back(i);
            req -= i;
        }
        else
        {
            // once if(), happens rest will go to set 2
            b.push_back(i);
        }
    }
    cout << "YES" << endl;
    cout << a.size() << endl;
    for (auto &x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << b.size() << endl;
    for (auto &x : b)
    {
        cout << x << " ";
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