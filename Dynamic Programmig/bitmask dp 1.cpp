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
const ll mod = 993344777;

vector<ll>prime;
ll cn[62];
ll mem[62][(1 << 17)][2];

ll f(ll i, ll mask, ll st)
{
    if (i == 61)
    {
        if (!mask) {
            if (st) return 0;
            return 1;
        }
        if (st) return 1;
        return 0;
    }
    if (mem[i][mask][st] != -1) return mem[i][mask][st];
    ll an = 0;
    if (cn[i])
    {
        ll x = mask, y = i;
        for (ll j = 0; y > 1 && j < prime.size(); j++) {
            if (y % prime[j] == 0) {
                while (y % prime[j] == 0) {
                    y /= prime[j];
                    x ^= (1 << j);
                }
            }
        }

        an += cn[i] * f(i + 1, x, st ^ 1);
    }
    an +=  f(i + 1, mask, st);

    return mem[i][mask][st] = an % mod;

}
void solve()
{
    ll n;
    cin >> n;
    ll a[n + 1];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        cn[a[i]]++;
    }

    for (ll i = 2; i <= 60; i++) {
        bool ok = true;
        for (ll j = 2; j * j <= i; j++) {
            if (i % j == 0) ok = false;
        }
        if (ok) prime.pb(i);
    }

    memset(mem, -1, sizeof(mem));
    ll an = (f(1, 0, 0) - 1 + mod) % mod;
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
// https://toph.co/p/is-it-perfect
