#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
using Matrix = array<array<int, 2>, 2>;
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
Matrix mul(Matrix a, Matrix b)
{
    Matrix res = {{{0, 0}, {0, 0}}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
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
    int n;
    cin >> n;                         // b
    Matrix base = {{{1, 0}, {0, 1}}}; // similar to res
    Matrix m = {{{1, 1}, {1, 0}}};    // a
    while (n > 0)
    {
        if (n & 1)
        {
            base = mul(base, m);
        }
        m = mul(m, m);
        n >>= 1;
    }
    // fn+2, fn+1, fn+1, fn for A^(n+1)
    cout << base[0][1] << endl;
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