/**
 *    author:  compounding
 *    created: 2024-10-31 15:10:24
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
vector<string> graycode(int n)
{
    // base case
    if (n == 1)
    {
        return {"0", "1"};
    }
    vector<string> prevans = graycode(n - 1);
    vector<string> temp = prevans;
    reverse(all(temp));
    // add 0 to the first half in front and 1 to the second half in front
    for (int i = 0; i < prevans.size(); i++)
    {
        prevans[i] = "0" + prevans[i];
        temp[i] = "1" + temp[i];
    }
    prevans.insert(prevans.end(), all(temp));
    return prevans;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> ans = graycode(n);
    for (auto x : ans)
    {
        cout << x << endl;
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
vector<int> dijkstra(int source)
{
    vi dist(n + 1, LLONG_MAX);
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
    while (!s.empty())
    {
        auto [cur_dist, cur_node] = *s.begin();
        s.erase(s.begin());
        for (auto [node_here, edge_wt] : adj[cur_node])
        {
            if (dist[node_here] > cur_dist + edge_wt)
            {
                s.erase({dist[node_here], node_here});
                dist[node_here] = cur_dist + edge_wt;
                s.insert({dist[node_here], node_here});
            }
        }
    }
    return dist;
}