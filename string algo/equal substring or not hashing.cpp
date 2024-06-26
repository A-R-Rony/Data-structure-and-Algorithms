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

#define MAXN 300010
#define inf 1e6+5
const ll mod = 1e9 + 7;

const ll mod1 = 127657753, mod2 = 987654319, b1 = 141, b2 = 277;
pair<ll, ll>p[MAXN];

void power()
{
    p[0] = {1, 1};
    for (ll i = 1; i < MAXN; i++) {
        p[i].first = 1LL * p[i - 1].first * b1 % mod1;
        p[i].second = 1LL * p[i - 1].second * b2 % mod2;
    }
}
struct Hash///vai age power function call deeeee
{
    ll n;
    vector<pair<ll, ll>>hs;

    Hash(string s)// string input a jemn chilo temn e ache
    {
        n = s.size();
        hs.resize(n + 5);
        // ap^k + bp^(k-1) + c
        // 1 indexed
        for (ll i = 1; i <= n; i++) {
            hs[i].first = (1LL * hs[i - 1].first * b1 + (s[i - 1] - 'a' + 1)) % mod1;
            hs[i].second = (1LL * hs[i - 1].second * b2 + (s[i - 1] - 'a' + 1)) % mod2;
        }
    }

    pair<ll, ll> get_hash(ll l, ll r)
    {
        ll an1 = (hs[r].first - (1LL * hs[l - 1].first * p[r - l + 1].first) % mod1 + mod1) % mod1;
        ll an2 = (hs[r].second - (1LL * hs[l - 1].second * p[r - l + 1].second) % mod2 + mod2) % mod2;
        return {an1, an2};
    }

};

void solve()
{
    ll n;
    string s;
    cin >> s;
    n = s.size();

    Hash hs(s);

    ll an = 0;

    auto equal = [&] (int l1, int r1, int l2, int r2)
    {
        if (l1 > r1 || l2 > r2 || r2 > n || r1 > l2) return false;
        return hs.get_hash(l1, r1) == hs.get_hash(l2, r2);
    };

    if (n % 2 == 0) {
        ll md = n / 2;
        if (equal(1, md, md + 1, n)) an += 2;
    }

    for (ll len = 1; len < n; len++) {
        ll md;

        ll l1 = 1, r1 = len;
        ll l2 = r1 + 1, r2 = len + len;

        if (equal(l1, r1, l2, r2)) {
            md = n - (len + len);
            if (md % 2 == 1) continue;
            md /= 2;

            l1 = r2 + 1;
            r1 = l1 + md - 1;
            l2 = r1 + 1;
            r2 = n;

            if (equal(l1, r1, l2, r2)) {
                an++;
            }

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

    power();

    int c = 0;
    while ( t-- )
    {
        // cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}

// https://www.codechef.com/problems/BREAKSTRING
