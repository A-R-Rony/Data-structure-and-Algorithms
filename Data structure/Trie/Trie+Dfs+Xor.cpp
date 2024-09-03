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

#define MAXN 500005
#define inf 1e6+5
const int mod = 1e9 + 7;

ll n;
ll a[MAXN], vis[MAXN];
vector<ll>g[MAXN];

struct trie
{
    ll g[MAXN * 31][2];
    ll cn[MAXN * 31][2];

    ll cur;
    void init()
    {
        memset(g, -1, sizeof(g));
        memset(cn, 0, sizeof(cn));
        cur = 0;
    }
    void Insert(ll d)
    {
        ll nd = 0;
        ll xr = 0;
        for (ll i = 30; i >= 0; i--)
        {
            bool x = chkbit(d, i);
            cn[nd][x]++;
            if (g[nd][x] == -1) g[nd][x] = ++cur;
            nd = g[nd][x];
        }
    }

    ll query(ll d)
    {
        ll nd = 0;
        ll xr = 0;
        for (ll i = 30; i >= 0; i--)
        {
            bool x = chkbit(d, i);
            bool y = (1 ^ x);

            if (g[nd][y] != -1)
            {
                xr |= (1LL << i);
                nd = g[nd][y];
            }
            else if (g[nd][x] != -1)
            {
                nd = g[nd][x];
            }
            else break;
        }
        return xr;
    }
    void Erase(ll d)
    {
        ll nd = 0;
        for (ll i = 30; i >= 0; i--)
        {
            bool x = chkbit(d, i);
            cn[nd][x]--;
            if (cn[nd][x] == 0)
            {
                g[nd][x] = -1;
                break;
            }
            nd = g[nd][x];
        }
    }

} tri;
ll an;

void dfs(ll nd)
{
    vis[nd] = 1;

    ll xr = tri.query(a[nd]);
    an = max(an, xr);

    tri.Insert(a[nd]);

    for (auto i : g[nd])
    {
        if (vis[i]) continue;
        dfs(i);
    }
    tri.Erase(a[nd]);
}
void solve()
{
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (ll i = 1; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    tri.init();
    dfs(1);

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
// https://toph.co/p/yet-another-xor-problem
