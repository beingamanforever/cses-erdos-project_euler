/**
 *    author:  compounding
 *    created: 2024-12-09 18:55:30
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
const int N = 1005;
int n;
int grid[N][N];
int dp[N][N];
void solve()
{
    // TODO: Grid Paths, CSES
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            grid[i][j] = s[j - 1];
        }
    }
    // dp state -> dp[i][j] = number of ways to reach (i,j) from (1,1)
    if (grid[1][1] == '*' || grid[n][n] == '*')
    {
        cout << 0 << endl;
        return;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
            {
                // calculated above
                continue;
            }
            if (grid[i][j] == '*')
            {
                // can't be reached
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[n][n] << endl;
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