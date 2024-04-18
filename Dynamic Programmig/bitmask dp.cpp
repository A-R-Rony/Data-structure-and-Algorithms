#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>order_set;
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

int n, a[101], prime[20], sz, bt[60], at[100], mem[100][(1 << 17)];
vector<int>g[31];
vector<int>v;
int tot = (1 << 16) - 1;

int f(int i, int mask)
{
    if (i == n) return 0;
    if (mem[i][mask] != -1) return mem[i][mask];

    int an = f(i + 1, mask) + abs(a[i] - 1);
    if (mask != tot)
        for (int j = 2; j < 60; j++) {
            int nxt = mask & bt[j];
            if (nxt) continue;
            an = min(an, f(i + 1, mask | bt[j]) + abs(a[i] - j));
        }
    return mem[i][mask] = an;
}

vector<int>rs;
void print(int i, int mask)
{
    if (i == n) return;
    int an = f(i, mask);
    if (mask == tot || an == f(i + 1, mask) + abs(a[i] - 1) ) {
        rs.pb(1);
        print(i + 1, mask);
        return;
    }

    for (int j = 2; j < 60; j++) {
        int nxt = mask & bt[j];
        if (nxt) continue;
        if (an == f(i + 1, mask | bt[j]) + abs(a[i] - j)) {
            rs.pb(j);
            print(i + 1, mask | bt[j]);
            return;
        }
    }
}
void solve()
{

    for (int i = 2 ; i < 100; i++)
    {
        int x = i, cn = 0;
        for (int j = 2; j < i; j++) {
            if (x % j == 0) {
                cn = 1; break;
            }
        }
        if (!cn) {
            prime[sz++] = i;
        }
    }

    for (int i = 2; i < 60; i++) {
        for (int j = 0; j < sz && prime[j] > 0; j++) {
            if (i % prime[j] == 0) {
                bt[i] |= (1 << j);
            }

        }

    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(mem, -1, sizeof(mem));
    int an = f(0, 0);

    print(0, 0);
    for (auto i : rs) cout << i << " "; cout << en;
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
// https://codeforces.com/contest/454/problem/D
