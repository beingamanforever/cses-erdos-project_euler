/**
 *    author:  compounding
 *    created: 2024-12-09 19:07:23
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
const int N = 5005;
int n, totalsum;
int a[N];
int cache[N][N];
int dp(int left, int right)
{
    // base case
    if (left > right)
    {
        return 0;
    }
    int &ans = cache[left][right];
    if (ans != -1)
    {
        return ans;
    }
    int turn = n - (right - left + 1);
    // here we intend to maximze our score
    if (turn % 2 == 0)
    {
        ans = max(a[left] + dp(left + 1, right), a[right] + dp(left, right - 1));
    }
    else
    {
        // opponent will minimize our score
        ans = min(dp(left + 1, right), dp(left, right - 1));
    }
    return ans;
}
void solve()
{
    // TODO: Removal Game, CSES
    // perspective is on us, so when Player 2 picks, it lefts us with min of dp(left+1,right) and dp(left,right-1)
    // as he tries to minimize our answer
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        totalsum += a[i];
    }
    // dp state -> dp[i][j] = maximum score achieved by either player using the range [i,j]
    // means 0-i-1, j+1-n have been picked
    memset(cache, -1, sizeof(cache));
    int ans = dp(1, n);
    cout << ans << endl;
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