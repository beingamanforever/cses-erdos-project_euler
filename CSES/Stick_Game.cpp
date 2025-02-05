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
    int n, k;
    cin >> n >> k;
    vi remove(k);
    for (int i = 0; i < k; i++)
    {
        cin >> remove[i];
    }
    vi nimber(n + 1);
    for (int i = 1; i <= n; i++)
    {
        vector<bool> reachable(k + 1, false);
        for (auto &x : remove)
        {
            if (i >= x)
            {
                reachable[nimber[i - x]] = true;
            }
        }
        for (int j = 0; j <= k; j++)
        {
            if (!reachable[j])
            {
                nimber[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (nimber[i] == 0 ? 'L' : 'W');
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