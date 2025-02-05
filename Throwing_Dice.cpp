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
using Matrix = array<array<int, 6>, 6>;
Matrix mul(Matrix a, Matrix b)
{
    Matrix res = {{{0, 0}, {0, 0}}};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod1;
            }
        }
    }
    return res;
}
void solve()
{
    // power
    int b;
    cin >> b;
    // dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + ... + dp[i-6]
    // res
    Matrix res = {{{1, 0, 0, 0, 0, 0},
                   {0, 1, 0, 0, 0, 0},
                   {0, 0, 1, 0, 0, 0},
                   {0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0},
                   {0, 0, 0, 0, 0, 1}}};
    // a
    Matrix a = {{{1, 1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 0, 0},
                 {0, 1, 0, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 1, 0}}};
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    cout << res[0][0] << endl;
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