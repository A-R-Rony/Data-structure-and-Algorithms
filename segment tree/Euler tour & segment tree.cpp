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
#define MAXN 200010
#define inf 1e6+5
const int mod = 1e9 + 7;
int n, m, a[MAXN], vis[MAXN], col[MAXN], in[MAXN], out[MAXN], timer;
vector<int>g[MAXN];

void dfs(int nd, int st)
{
    vis[nd] = 1;
    col[nd] = st;
    in[nd] = ++timer;
    for (auto i : g[nd])
    {
        if (vis[i]) continue;
        dfs(i, !st);
    }
    out[nd] = timer;
}

struct segment_tree
{
    struct node {
        ll suru , ses, sm, lazy;

        void init(ll l, ll r) {
            suru = l, ses = r; lazy = 0;
            if (l == r) {
                sm = 0;
            }
        }
    } g[4 * MAXN];

    void build(ll cn, ll l, ll r)
    {
        g[cn].init(l, r);

        if (l == r ) return;
        ll md = l + (r - l) / 2;

        build(cn * 2, l, md);
        build(cn * 2 + 1, md + 1, r);
        g[cn].sm = g[cn * 2].sm + g[cn * 2 + 1].sm;
    }

    ll Range(ll x, ll y)
    {
        return y - x + 1;
    }

    void distribute(ll cn, ll ln, ll rn)
    {
        g[ln].lazy += g[cn].lazy;
        g[rn].lazy += g[cn].lazy;
        g[ln].sm += Range(g[ln].suru, g[ln].ses) * g[cn].lazy;
        g[rn].sm += Range(g[rn].suru, g[rn].ses) * g[cn].lazy;

        g[cn].lazy = 0;
    }
    void update(ll cn, ll l, ll r, ll val)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;

        if (y < l || x > r) return;
        if (l <= x && r >= y ) {
            g[cn].lazy += val;
            g[cn].sm += val * ( y - x + 1);
            return;
        }

        distribute(cn, cn * 2, cn * 2 + 1);

        update(cn * 2, l, r, val);
        update(cn * 2 + 1, l, r, val);

        g[cn].sm = g[cn * 2].sm + g[cn * 2 + 1].sm;
    }

    ll query(ll cn, ll l, ll r)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;
        if (y < l || x > r) return 0;

        if (l <= x && r >= y ) {
            return g[cn].sm;
        }

        distribute(cn, cn * 2, cn * 2 + 1);

        ll ans = query(cn * 2, l, r);
        ans += query(cn * 2 + 1, l, r);
        return ans;
    }

} stre[2];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);

    stre[0].build(1, 1, n);
    stre[1].build(1, 1, n);

    // for (int i = 1; i <= n; i++) cout << in[i] << " " << out[i] << en;

    // for (int i = 1; i <= n; i++) cout << col[i] << " "; cout << en;

    while (m--)
    {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int nd, x;
            cin >> nd >> x;
            int l = in[nd], r = out[nd];
            int st = col[nd];
            // cout << "upd : " << nd << " " << st << " " << l << " " << r << " " << x << en;
            stre[st].update(1, l, r, x);
            // cout << "after upd : " << stre[st].query(1, l, r);
            stre[!st].update(1, l, r, -x);
        }
        else {
            int nd;
            cin >> nd;
            int st = col[nd];
            int l = in[nd], r = out[nd];
            cout << a[nd] + stre[st].query(1, l, l) << en;
        }
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
