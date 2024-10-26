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

#define MAXN 400010
#define inf 1e16+5
const int mod = 1e9 + 7;

ll n;
ll a[MAXN], b[MAXN];

struct segment_tree
{
    struct node {
        ll suru , ses, mn, lazy;

        void init(ll l, ll r) {
            suru = l, ses = r; lazy = inf;
            if (l == r) {
                mn = inf;
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
        g[cn].mn = min(g[cn * 2].mn,  g[cn * 2 + 1].mn);
    }

    void distribute(ll cn, ll ln, ll rn)
    {
        g[ln].lazy = min(g[ln].lazy, g[cn].lazy);
        g[rn].lazy = min(g[rn].lazy, g[cn].lazy);
        g[ln].mn = min(g[ln].mn, g[ln].lazy);
        g[rn].mn = min(g[rn].mn, g[rn].lazy);
        g[cn].lazy = inf;
    }
    void update(ll cn, ll l, ll r, ll val)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;

        if (y < l || x > r) return;
        if (l <= x && r >= y ) {
            debug(cn, l, r, val);
            g[cn].lazy = min(g[cn].lazy, val);
            g[cn].mn = g[cn].lazy;
            return;
        }

        distribute(cn, cn * 2, cn * 2 + 1);

        update(cn * 2, l, r, val);
        update(cn * 2 + 1, l, r, val);
        g[cn].mn = min(g[cn * 2].mn,  g[cn * 2 + 1].mn);
        if (cn == 1) {
            debug("ok", g[cn * 2].mn, g[cn].mn);
        }
    }

    ll query(ll cn, ll l, ll r)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;
        if (y < l || x > r) return inf;

        if (l <= x && r >= y ) {
            return g[cn].mn;
        }

        distribute(cn, cn * 2, cn * 2 + 1);

        ll ans = query(cn * 2, l, r);
        ans = min(ans, query(cn * 2 + 1, l, r));
        return ans;
    }

} stre;
void solve()
{
    cin >> n;
    ll pre[n + 1] = {0};
    ll dp[n + 1];

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (ll i = 1; i <= n; i++) cin >> b[i];

    ll an = 0;

    stre.build(1, 1, n);
    dp[1] = 0;
    stre.update(1, 1, 1, 0);
    ll sm = 0;
    an = a[1];
    debug(stre.query(1, 1, 1));

    for (ll i = 1 ; i <= n; i++)
    {
        sm += a[i];
        ll x = stre.query(1, i, i);
        an = max(an, sm - x);
        if (b[i] >= i) {
            stre.update(1, i, b[i], x + a[i]);
        }
    }
    cout << an << en;
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
// https://codeforces.com/contest/2024/problem/D
