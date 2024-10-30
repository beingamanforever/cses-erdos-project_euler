/**
 *    author:  compounding
 *    created: 2024-10-31 00:00:36
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
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
struct segmenttree
{
    int n;
    vector<int> st, lazy;
    segmenttree(int _n)
    {
        this->n = _n;
        st.resize(4 * n, LLONG_MIN);
        lazy.resize(4 * n, 0LL);
    }
    int comb(int a, int b)
    { // do changes here
        return (a + b);
    }
    void push(int start, int ending, int node)
    { // do changes here
        st[node] += lazy[node];
        if (start != ending)
        {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    void build(int start, int ending, int node, vector<int> &v)
    {
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }
        int mid = (start + ending) / 2;
        build(start, mid, 2 * node + 1, v);
        build(mid + 1, ending, 2 * node + 2, v);
        st[node] = comb(st[2 * node + 1], st[2 * node + 2]);
    }
    int query(int start, int ending, int l, int r, int node)
    {
        push(start, ending, node);
        if (start > r || ending < l)
        {
            return 0; // default value
        }
        if (start >= l && ending <= r)
        {
            return st[node];
        }
        int mid = (start + ending) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
        return comb(q1, q2);
    }
    void update(int start, int ending, int node, int l, int r, int value)
    {
        push(start, ending, node);
        if (start > r || ending < l)
        {
            return;
        }
        if (start >= l && ending <= r)
        {
            st[node] += value;
            if (start != ending)
            {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }
        int mid = (start + ending) / 2;
        update(start, mid, 2 * node + 1, l, r, value);
        update(mid + 1, ending, 2 * node + 2, l, r, value);
        st[node] = comb(st[2 * node + 1], st[2 * node + 2]);
    }
    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }
    int query(int l, int r)
    {
        if (r == -1)
        {
            return 0;
        }
        return query(0, n - 1, l, r, 0);
    }
    void update(int l, int r, int x)
    {
        update(0, n - 1, 0, l, r, x);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    segmenttree sgt(n);
    sgt.build(a);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int left, right, delta;
            cin >> left >> right >> delta;
            left--;
            right--;
            sgt.update(left, right, delta);
        }
        else
        {
            int pos;
            cin >> pos;
            pos--;
            cout << sgt.query(pos, pos) << endl;
        }
    }
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