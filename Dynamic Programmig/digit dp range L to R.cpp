#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>order_set;
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

#define MAXN 1e12
#define inf 1e18
const int mod = 1e9 + 7;

string a, b;
ll mem[20][10][10][2][2][2];

ll f(ll i, ll mn, ll mx, bool lrg, bool sml, bool st)
{
    // debug(i, mn, mx);
    if (i == (ll)a.size()) {
        return mx - mn;
    }
    ll &ret = mem[i][mn][mx][lrg][sml][st];
    if (ret != -1) return ret;

    ll l = a[i] - '0';
    if (sml) l = 0;
    ll r = b[i] - '0';
    if (lrg) r = 9;
    ret = 1e9;
    for (ll j = l; j <= r; j++)
    {
        if (j || st) {
            ret = min(ret, f(i + 1, min(mn, j), max(mx, j), (lrg | (j < b[i] - '0')), (sml | (j > a[i] - '0')), 1));
        }
        else ret = min(ret, f(i + 1, mn, mx, (lrg | (j < b[i] - '0')), (sml | (j > a[i] - '0')), 0 ));
    }
    return ret ;
}
ll res(ll l, ll r)
{
    a.clear(); b.clear();
    a = to_string(l);
    b = to_string(r);
    while (a.size() < b.size()) a = "0" + a;

    memset(mem, -1, sizeof(mem));
    ll an = f(0, 9, 0, 0, 0, 0);
    return an;
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    ll rs = res(l, r);
    debug(rs);

    ll L = l , R = r, an;
    while (L <= R)
    {
        ll md = L + (R - L) / 2;
        if (res(L, md) == rs) {
            an = md;
            R = md - 1;
        }
        else L = md + 1;
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
        // cout << "Case " << ++c << ": ";
        solve();
    }
    return 0;
}
//https://codeforces.com/contest/1808/problem/C
