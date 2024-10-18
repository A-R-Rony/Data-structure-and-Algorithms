#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

typedef long long int ll;
#define all(i)     i.begin() , i.end()
#define chkbit(mask,bit)  (mask&(1LL << bit))
#define pb     push_back
#define en "\n"
#define MAXN 100010
const int mod = 1e9 + 7;

int n, m, vis[705], in[705], low[705];
vector<int>g[705];
int timer;
vector<pair<int, int>>bridge;

void SetUp(int n)
{
    timer = 0;
    for (int i = 1; i <= n; i++) vis[i] = 0, in[i] = 0, low[i] = 0, g[i].clear();
    bridge.clear();
}
void dfs(int nd, int p)
{
    vis[nd] = 1;
    in[nd] = low[nd] = ++timer;
    for (auto i : g[nd])
    {
        if (i == p) continue;
        if (vis[i])
        {
            low[nd] = min(low[nd], in[i]);
            continue;
        }
        dfs(i, nd);
        low[nd] = min(low[nd], low[i]);
        if (in[nd] < low[i])
        {
            // cout << "ed : " << nd << " " << i << en;
            if (nd < i)
                bridge.pb({nd, i});
            else bridge.pb({i, nd});
        }

    }
}
void solve()
{
    cin >> n >> m;
    SetUp(n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1, 0);
    sort(all(bridge));
    if (bridge.size() == 0)
    {
        cout << "Sin bloqueos\n"; return;
    }
    cout << bridge.size() << en;
    for (auto i : bridge) cout << i.first << " " << i.second << en;

}
int main()
{
    IOS;
    int t;
    cin >> t;
    // t = 1;
    int cn = 0;
    while (t--)
    {
        cout << "Caso #" << ++cn << en;
        solve();
    }
    return 0;
}
// https://www.spoj.com/problems/EC_P/
