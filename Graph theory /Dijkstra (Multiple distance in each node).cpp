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
ll n, m, k;
vector<edge>g[MAXN];

void dijkstra()
{
    vector<ll>dis(n + 1, inf), vis(n + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    pq.push({0, 1});

    vector<priority_queue<ll>>an(n + 1);
    an[1].push(0);

    while (!pq.empty())
    {
        auto t = pq.top(); pq.pop();
        ll nd = t.sn;
        ll dist = t.ft;

        if (an[nd].top() < dist) continue;

        for (auto i : g[nd])
        {
            if (an[i.to].size() < k) {
                an[i.to].push(i.cs + dist);
                pq.push({i.cs + dist, i.to});
            }
            else if (an[i.to].top() > i.cs + dist)
            {
                an[i.to].pop();
                an[i.to].push(i.cs + dist);
                pq.push({i.cs + dist, i.to});
            }
        }
    }
    vector<ll>v;
    while (k--)
    {
        v.pb(an[n].top());
        an[n].pop();
    }
    reverse(all(v));
    for (auto i : v) cout << i << " ";
    cout << en;
}
void solve()
{
    cin >> n >> m >> k;
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
// https://cses.fi/problemset/task/1196/
