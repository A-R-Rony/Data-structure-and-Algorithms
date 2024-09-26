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
#define totalone(mask)  __builtin_popcount(mask)
#define chkbit(mask,bit)  (mask&(1LL << bit))

// debug section start
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// debug section closed

#define en "\n"
#define sum(n) ((1LL*(n)*(n+1))/ 2LL)
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)

#define MAXN 200010
#define inf 1e16+5
const int mod = 1e9 + 7;

struct edge {
    ll to, cs;
};
ll n, m;
vector<edge>g[MAXN];

void dijkstra()
{
    vector<vector<ll>>dis(n + 1, vector<ll>(2, inf));
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>pq;
    pq.push({0, 1, 1});
    dis[1][1] = 0;
    while (!pq.empty())
    {
        auto t = pq.top(); pq.pop();
        ll nd = t[1];
        ll dist = t[0];
        ll st = t[2];
        if (dist > dis[nd][st]) continue;

        for (auto i : g[nd])
        {
            if (st == 1)
            {
                if (dis[i.to][1] > dist + i.cs) {
                    dis[i.to][1] = dist + i.cs;
                    pq.push({dis[i.to][1], i.to, 1});
                }
                if (dis[i.to][0] > dist + i.cs / 2) {
                    dis[i.to][0] = dist + i.cs / 2;
                    pq.push({dis[i.to][0], i.to, 0});
                }
            }
            else {
                if (dis[i.to][0] > dist + i.cs) {
                    dis[i.to][0] = dist + i.cs;
                    pq.push({dis[i.to][0], i.to, 0});
                }
            }
        }
    }
    cout << min(dis[n][0], dis[n][1]) << en;
}
void solve()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        edge e;
        ll nd;
        cin >> nd >> e.to >> e.cs;
        g[nd].pb(e);
    }

    dijkstra();
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
// https://cses.fi/problemset/task/1195
