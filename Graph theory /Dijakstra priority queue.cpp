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

#define MAXN 100010
#define inf 1e6+5
const int mod = 1e9 + 7;

int n, m, k;
vector<pair<int, int>>g[MAXN];
int dis[MAXN], vis[MAXN], sum[MAXN];

void dijkstra()
{
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        dis[i] = 1e9;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    q.push({0, 1});
    dis[1] = 0;
    while (!q.empty())
    {
        auto x = q.top();
        q.pop();
        int nd = x.second;
        int w = x.first;
        if (vis[nd] == 1) continue;
        vis[nd] = 1;

        for (auto i : g[nd]) {

            if (dis[i.first] == dis[nd] + i.second) {
                sum[i.first]++;
            }
            if (dis[i.first] > dis[nd] + i.second) {
                dis[i.first] = dis[nd] + i.second;
                sum[i.first] = 1;
                q.push({dis[i.first], i.first});
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }

    vector<int>b(k + 1), c(k + 1);

    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        g[1].pb({x, y});
        g[x].pb({1, y});
        b[i] = x, c[i] = y;
    }

    dijkstra();

    // for (int i = 1; i <= n; i++) cout << dis[i] << " "; cout << en;
    // for (int i = 1; i <= n; i++) cout << sum[i] << " "; cout << en;
    int an = 0;

    for (int i = 1; i <= k; i++)
    {
        if (dis[b[i]] < c[i]) {
            an++; continue;
        }
        if (dis[b[i]] == c[i]) {
            if (sum[b[i]] > 1) {
                an++;
                sum[b[i]]--;
            }
        }
    }
    cout << an << en;

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
// https://codeforces.com/contest/450/problem/D
