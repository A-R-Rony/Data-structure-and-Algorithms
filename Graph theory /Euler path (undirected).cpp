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
#define MAXN 420
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
int n, m, edges;
vector<pair<int, int>>g[MAXN];
int deg[MAXN], done[MAXN], vis[MAXN * MAXN];
vector<pair<int, int>>path;

bool hasEulerpath(int n)
{
    int odd = 0;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] & 1) {
            odd++;
        }
    }
    if (odd > 2)
        return false;
    return true;
}
int FindFirstNode(int n)
{
    int nd = 0;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] & 1) return i;
        if (deg[i]) nd = i;
    }
    return nd;
}
void dfs(int nd)
{
    while (done[nd] < g[nd].size())
    {
        auto i = g[nd][done[nd]++];
        if (vis[i.second]) continue;
        vis[i.second] = 1;
        path.pb({nd, i.first});
        dfs(i.first);
    }
}
void setUp(int n)
{
    path.clear();
    edges = 0;
    memset(deg, 0, sizeof(deg));
    memset(vis, 0, sizeof(vis));
    memset(done, 0, sizeof(done));
    for (int i = 1; i <= n; i++)
    {
        for (auto j : g[i])
        {
            deg[j.first]++, deg[i]++, edges++;
        }
    }
}
bool EulerPath()
{
    setUp(n + 1);

    if (!hasEulerpath(n + 1)) {
        return false;
    }

    for (int i = 1; i <= n + 1; i++)
    {
        if (done[i] < g[i].size()) dfs(i);
    }

    if (path.size() != edges / 2 + 1) return false;
    reverse(all(path));
    // for (auto i : path) cout << i << " "; cout << en;
    return true;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n + 1; i++) {deg[i] = 0; g[i].clear();}

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb({y, i});
        g[y].pb({x, i});
        deg[x]++; deg[y]++;
    }
    int sz = m;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] & 1)
        {
            sz++;
            g[i].pb({n + 1, sz});
            g[n + 1].pb({i, sz});
        }
    }
    bool ok = EulerPath();

    // assert(ok);
    vector<int>in(n + 2, 0), out(n + 2, 0);
    for (auto e : path) {
        if (e.first != n + 1 && e.second != n + 1) {
            in[e.second]++; out[e.first]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (in[i] == out[i]);
    cout << ans << en;
    for (auto e : path) if (e.first != n + 1 &&  e.second != n + 1) cout << e.first << ' ' << e.second << '\n';


}
int main()
{
    IOS;
    ll t;
    t = 1;
    cin >> t;

    int c = 0;
    while ( t-- )
    {
        // cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}
