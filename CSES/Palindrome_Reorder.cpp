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
    string s;
    cin >> s;
    int n = s.size(), odd = 0;
    vi cnt(26, 0);
    for (char c : s)
    {
        cnt[c - 'A']++;
    }
    char c;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] & 1)
        {
            odd++;
            c = i + 'A';
        }
    }
    if ((n & 1) && odd != 1 || (!(n & 1) && odd > 0))
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    // valid cases
    string start = "", end = "", mid = "";
    if (c)
    {
        mid = c;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 0)
        {
            string temp(cnt[i] / 2, i + 'A');
            start = start + temp;
            end = temp + end;
        }
    }
    cout << (start + mid + end);
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