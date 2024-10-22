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

int in[MAXN], low[MAXN], timer, vis[MAXN];
set<int>artculation;
vector<int>g[MAXN];

void dfs(int nd, int p)
{
    vis[nd] = 1;
    in[nd] = low[nd] = ++timer;
    int cn = 0;
    for (auto to : g[nd])
    {
        if (p == to) continue;
        if (vis[to])
        {
            low[nd] = min(low[nd], in[to]); continue;
        }
        dfs(to, nd);
        low[nd] = min(low[nd], low[to]);
        if (low[to] >= in[nd] && p != 0)
        {
            artculation.insert(nd);
        }
        cn++;
    }
    if (p == 0 && cn > 1)
    {
        artculation.insert(nd);
    }
}
void solve()
{
    while (1)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) {
            vis[i] = 0; in[i] = 0;
            g[i].clear();
        }
        timer = 0;

        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        artculation.clear();
        dfs(1, 0);
        cout << artculation.size() << en;
    }
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
// https://www.spoj.com/problems/SUBMERGE/
