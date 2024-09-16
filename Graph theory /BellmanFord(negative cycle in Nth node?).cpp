#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>order_set;
typedef pair<int, int>pr;
#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb     push_back
#define chkbit(mask,bit)  (mask&(1LL << bit))

#define en "\n"
#define MAXN 200010
const ll inf = (1e17 + 5);
const ll ninf = -(1e17 + 5);
const int mod = 1e9 + 7;

struct edge
{
    ll nd1, nd2, cst;
};
ll n, m;
vector<edge>g;
vector<ll>dis;

void BellmanFord()
{
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto e : g)
        {
            if (dis[e.nd1] == inf) continue;
            dis[e.nd2] = min(dis[e.nd1] + e.cst, dis[e.nd2]);
            dis[e.nd2] = max(ninf, dis[e.nd2]);
        }
    }

    for (int i = 1; i < n; i++) {
        for (auto e : g)
        {
            if (dis[e.nd1] == inf) continue;
            dis[e.nd2] = max(ninf, dis[e.nd2]);
            if (dis[e.nd1] + e.cst < dis[e.nd2]) {
                dis[e.nd2] = -inf;
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        edge e;
        cin >> e.nd1 >> e.nd2 >> e.cst;
        e.cst *= -1;
        // cout << e.nd1 << " " << e.nd2 << " " << e.cst << en;
        g.pb(e);
    }
    dis.resize(n + 1);
    for (ll i = 1; i <= n; i++) dis[i] = inf;

    BellmanFord();

    if (n == 1)
    {
        for (auto e : g) {
            if (e.cst == -1) {
                cout << -1 << en; return;
            }
        }
        cout << 0 << en; return;
    }
    if (dis[n] == ninf) {
        cout << -1 << en;
    }
    else {
        cout << -dis[n] << en;
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
// https://cses.fi/problemset/task/1673/
