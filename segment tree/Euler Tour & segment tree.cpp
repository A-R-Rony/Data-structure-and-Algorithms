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

#define MAXN 500010
#define inf 1e6+5
const int mod = 1e9 + 7;

int n, q;
int bg[MAXN], sml[MAXN], a[MAXN], vis[MAXN], in[MAXN], out[MAXN];
vector<int>g[MAXN];
int timer = 0;
multiset<int>ms[MAXN];

void dfs(int nd, int p)
{
    in[nd] = ++timer;
    for (auto i : g[nd])
    {
        if (i == p) continue;
        dfs(i, nd);
    }
    out[nd] = timer;
}

struct segment_tree
{
    struct node {
        int suru , ses, mx;

        void init(int l, int r) {
            suru = l, ses = r;
            if (l == r) mx = a[l];
        }
    } g[4 * MAXN];
    void build(int cn, int l, int r)
    {
        g[cn].init(l, r);

        if (l == r ) return;
        int md = l + (r - l) / 2;

        build(cn * 2, l, md);
        build(cn * 2 + 1, md + 1, r);

        g[cn].mx = max(g[cn * 2].mx , g[cn * 2 + 1].mx);
    }

    int query(int cn, int l, int r)
    {
        int x = g[cn].suru;
        int y = g[cn].ses;
        if (y < l || x > r) return 0;

        if (l <= x && r >= y ) return g[cn].mx;

        int ans = query(cn * 2, l, r);
        ans = max(ans, query(cn * 2 + 1, l, r));
        return ans;
    }

} stre;
bool valid(int l, int r)
{
    if (l <= r) return true;
    return false;
}
void solve()
{
    cin >> n >> q;
    map<pair<int, int>, int>ma;
    int b[n + 1];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);

        ma[ {x, y}]++;
        ma[ {y, x}]++;
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        a[in[i]] = b[i];
    }

    // for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << en;
    stre.build(1, 1, n);
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        // debug(x, in[x], out[x]);
        // debug(y, in[y], out[y]);

        int l1 = in[x];
        int r1 = out[x];
        int l2 = in[y];
        int r2 = out[y];

        if (l1 <= l2 && r1 >= r2) {

            int an = 0;
            if (valid(l1, l2 - 1))
                an = stre.query(1, l1, l2 - 1);
            if (valid(r2 + 1, r1))
                an = max(an, stre.query(1, r2 + 1, r1));

            cout << an << " " << stre.query(1, l2, r2) << en;
        }
        else if (l2 <= l1 && r2 >= r1) {
            int an = 0;
            if (valid(l2, l1 - 1))
                an = stre.query(1, l2, l1 - 1);
            if (valid(r1 + 1, r2))
                an = max(an, stre.query(1, r1 + 1, r2));

            cout << stre.query(1, l1, r1) << " " << an << en;
        }
        else {
            cout << stre.query(1, l1, r1) << " " << stre.query(1, l2, r2) << en;
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
// https://codeforces.com/gym/527993/problem/I
