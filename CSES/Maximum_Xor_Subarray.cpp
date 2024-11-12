/**
 *    author:  compounding
 *    created: 2024-11-12 19:32:58
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
struct trie
{
    trie *links[2];
    int cnt[2];
    trie()
    {
        links[0] = nullptr;
        links[1] = nullptr;
        cnt[0] = 0;
        cnt[1] = 0;
    }
};

void insert(trie *root, int num, int c)
{
    // c = 1 -> remove
    trie *temp = root;
    for (int i = 29; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        if (c == 1)
        {
            temp->cnt[bit]--;
        }
        else if (temp->links[bit] == nullptr)
        {
            trie *node = new trie();
            temp->links[bit] = node;
        }
        if (c == 0)
        {
            temp->cnt[bit]++;
        }
        temp = temp->links[bit];
    }
}

int minmaxxor(trie *root, int x, int y)
{
    // y = 0 -> min xor
    trie *temp = root;
    int ans = 0;
    for (int i = 29; i >= 0; i--)
    {
        int bit = (x >> i) & 1;
        if (y)
        {
            bit = 1 - bit;
        }
        if (temp->cnt[bit] == 0)
        {
            temp = temp->links[1 - bit];
            ans += (1 - y) << i;
        }
        else
        {
            temp = temp->links[bit];
            ans += (y) << i;
        }
    }
    return ans;
    // make a trie* root  = new trie() in main and then directly use functions
}
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    int maxixor = 0, prexor = 0;
    trie *root = new trie();
    insert(root, 0, 0); // insert 0 in the trie
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        prexor ^= v[i];
        int getmaxi = minmaxxor(root, prexor, 1);
        maxixor = max(maxixor, getmaxi);
        insert(root, prexor, 0);
    }
    cout << maxixor << endl;
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