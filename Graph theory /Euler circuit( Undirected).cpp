#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb     push_back
#define chkbit(mask,bit)  (mask&(1LL << bit))
#define en "\n"
#define MAXN 200010
#define inf 1e6+5
const int mod = 1e9 + 7;

/*
all the edges should be in the same connected component
#undirected graph: euler path: all degrees are even or exactly two of them are odd.
#undirected graph: euler circuit: all degrees are even

**euler path in an undirected graph
**it also finds circuit if it exists
*/

//** Euler circuit finding problem
int n, m;
vector<pair<int, int>>g[MAXN];
int deg[MAXN], done[MAXN], vis[MAXN];
vector<int>path;

bool hasEulerpath()
{
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] & 1) {
            cout << "IMPOSSIBLE\n"; return false;
        }
    }
    return true;
}
void dfs(int nd)
{
    while (done[nd] < g[nd].size())
    {
        auto i = g[nd][done[nd]++];
        if (vis[i.second]) continue;
        vis[i.second] = 1;
        dfs(i.first);
    }
    path.pb(nd);
}
void EulerPath()
{
    if (!hasEulerpath()) return;
    dfs(1);
    // for (auto i : path) cout << i << " "; cout << en;

    if (path.size() != (m + 1)) {
        cout << "IMPOSSIBLE\n"; return;
    }
    reverse(all(path));
    for (auto i : path) cout << i << " "; cout << en;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb({y, i});
        g[y].pb({x, i});
        deg[x]++; deg[y]++;
    }

    EulerPath();

}
int main()
{
    IOS;
    ll t;
    t = 1;
    // cin >> t;

    int c = 0;
    while ( t-- )
    {
        // cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}
// https://cses.fi/problemset/task/1691/
