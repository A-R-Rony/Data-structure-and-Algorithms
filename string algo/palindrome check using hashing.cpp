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

#define MAXN 1000005
#define inf 1e6+5
const int mod = 1e9 + 7;

const ll mod1 = 127657753, mod2 = 987654319, b1 = 141, b2 = 277;
pair<ll, ll>p[MAXN];
void power(int n)
{
    p[0] = {1, 1};
    for (ll i = 1; i <= n; i++) {
        p[i].first = 1LL * p[i - 1].first * b1 % mod1;
        p[i].second = 1LL * p[i - 1].second * b2 % mod2;
    }
}
struct Hash
{
    ll n;
    vector<pair<ll, ll>>hs;

    Hash(string s)
    {
        n = s.size();
        hs.resize(n + 5);
        // ap^k + bp^(k-1) + c
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
bool ispal(string s)
{
    string t = s;
    reverse(all(t));
    if (t == s) return true;
    return false;
}
void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    power(n);
    if (!ispal(s)) {
        cout << "YES\n";
        cout << 1 << en;
        cout << s << en;
        return;
    }
    string t = s;
    reverse(all(t));
    Hash h1(s);
    Hash h2(t);

    for (ll i = 1; i < n; i++) {
        pair<ll, ll>an = h1.get_hash(1, i + 1);
        ll x = n - i;
        pair<ll, ll>an2 = h2.get_hash(n - i, n);
        debug(i, an, an2);
        if (an.ft != an2.ft && an.sn != an2.sn) {
            if (i + 2 <= n) {
                an = h1.get_hash(i + 2, n);
                ll x = n - i - 1;
                an2 = h2.get_hash(1, x);
                if (an.ft != an2.ft && an.sn != an2.sn) {
                    cout << "YES\n";
                    cout << 2 << en;
                    string s1 = s.substr(0, i + 1);
                    string s2 = s.substr(i + 1);
                    cout << s1 << " " << s2 << en;
                    return;
                }
            }

        }
    }

    cout << "NO\n";

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
// https://codeforces.com/contest/1951/problem/E
