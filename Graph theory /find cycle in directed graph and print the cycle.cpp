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
#define inf 1e6+5
const int mod = 1e9 + 7;
int n, m, vis[MAXN], pre[MAXN];
vector<int>g[MAXN];
 
int st;
bool ok = false;
void dfs(int nd)
{
    vis[nd] = 1;
    for (auto i : g[nd]) {
        if (vis[i] == 2) continue;
        if (vis[i] == 1) {
            st = i;
            pre[i] = nd;
            ok = true;
            break;
        }
        else {
            pre[i] = nd;
            dfs(i);
            if (ok) break;
        }
    }
    vis[nd] = 2;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
    }
 
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 2) continue;
        dfs(i);
        if (ok) break;
    }
    if (!ok) {
        cout << "IMPOSSIBLE\n"; return;
    }
    int cn = 0;
    vector<int>v;
    while (1)
    {
        v.pb(st);
        st = pre[st];
        if (v[0] == v.back() && v.size() > 1) break;
    }
    reverse(all(v));
    debug(v);
    cout << v.size() << en;
    for (auto i : v) cout << i << " "; cout << en;
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
