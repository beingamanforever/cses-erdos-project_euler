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
const int N = 2e5 + 5;
int n;
vi a;
vi segtree;

void build(int idx, int s, int e)
{
    if (s == e)
    {
        segtree[idx] = a[s];
        return;
    }
    int mid = s + (e - s) / 2;
    build(2 * idx, s, mid);
    build(2 * idx + 1, mid + 1, e);
    segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
}

void update(int idx, int s, int e, int pos, int val)
{
    if (s == e)
    {
        segtree[idx] = a[pos] = val;
        return;
    }
    int mid = s + (e - s) / 2;
    if (pos <= mid)
    {
        update(2 * idx, s, mid, pos, val);
    }
    else
    {
        update(2 * idx + 1, mid + 1, e, pos, val);
    }
    segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
}

int query(int idx, int s, int e, int qs, int qe)
{
    if (qs <= s && e <= qe)
    {
        return segtree[idx];
    }
    if (e < qs || s > qe)
    {
        return 0;
    }
    int mid = s + (e - s) / 2;
    int left = query(2 * idx, s, mid, qs, qe);
    int right = query(2 * idx + 1, mid + 1, e, qs, qe);
    return left + right;
}

void solve()
{
    cin >> n;
    a.resize(n);
    segtree.resize(4 * n);
    for (auto &i : a)
    {
        cin >> i;
    }
    build(1, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos, val;
            cin >> pos >> val;
            pos--;
            update(1, 0, n - 1, pos, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << query(1, 0, n - 1, l, r) << endl;
        }
    }
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
