/**
 *    author:  compounding
 *    created: 2024-11-12 01:15:00
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
// binary exponentiation
int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}
void solve()
{
    // find smallest multiple of x to a^b
    // guraanteed that a^b is less than 10^9
    int a, b, x;
    cin >> a >> b >> x;
    int power = binpow(a, b);
    // if b is negative, then smallest multiple of x to a^b is 0
    if (b < 0)
    {
        if (x == 1 && a == 1)
        {
            cout << 1 << endl;
            return;
        }
        cout << 0 << endl;
        return;
    }
    int ans = power / x;
    int case1 = ans * x;
    int case2 = (ans + 1) * x;
    // check which is closer to power
    if (abs(power - case1) <= abs(power - case2))
    {
        cout << case1 << endl;
    }
    else
    {
        cout << case2 << endl;
    }
    return;
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}