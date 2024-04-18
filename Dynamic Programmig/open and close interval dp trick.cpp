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

#define MAXN 205
#define inf 1e6+5
const int mod = 1e9 + 7;
int n, k, a[MAXN];
int mem[202][202][1002];

ll f(ll i, ll open, ll cost)
{
    ll nw = cost + (open * a[i]);
    if (nw > k ) return 0;
    if (open < 0) return 0;
    if (i >= n) return (open == 0);

    int &an = mem[i][open][cost];
    if (an != -1) return an;
    // open and close
    an = f(i + 1, open, nw); an %= mod;
    // open
    an = (an + f(i + 1, open + 1, nw) % mod);
    an %= mod;
    //majhe
    an = (an + (1LL * open * f(i + 1, open, nw)) % mod) % mod;
    // close
    an = (an + (1LL * open * f(i + 1, open - 1, nw)) % mod) % mod;
    return an;
}
void solve()
{
    cin >> n >> k;
    vector<int>v(n);
    for (int &i : v) cin >> i;
    sort(all(v));

    for (int i = 1; i < n; i++) a[i] = v[i] - v[i - 1];

    memset(mem, -1, sizeof(mem));
    int an = f(0, 0, 0);
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
// https://codeforces.com/contest/626/problem/F

