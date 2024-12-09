/**
 *    author:  compounding
 *    created: 2024-12-09 18:46:50
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
const int N = 505;
int dp[N][N];
void solve()
{
    // TODO: Rectangle Cutting, CSES
    int a, b;
    cin >> a >> b;
    // base case -> dp[i][i] = 0
    // dp state -> dp[i][j] = minimum number of cuts to make a rectangle of size i*j into squares
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            // we have a rectangle of size i*j
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 1e9;
            // length wise cut
            for (int k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            // breadth wise cut
            for (int k = 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
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