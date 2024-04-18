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
#define pb push_back

#define totalone(mask) __builtin_popcount(mask)
#define chkbit(mask,bit) (mask&(1LL << bit))
#define setbit(mask,bit) (mask|(1LL << bit)
#define cngbit(mask,bit) (mask^(1LL << bit))

#define en "\n"
#define dbg(x) cerr<<#x<<" is : "<<x<<en;
#define here cout<<"rony\n"
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define report cout<<-1<<en;
#define sum(n) ((1LL*(n)*(n+1))/ 2LL)
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)
#define coutv(v) for(auto i: v) cout<<i<<" ";cout<<en;
#define cinv(v) for(auto &i: v) cin >> i;

#define MAXN 1510
#define inf 1e6+5
const int mod = 1e9 + 7;

vector<int>g[MAXN];
int vis[MAXN];

const int mod1 = 127657753, mod2 = 987654319, b1 = 141, b2 = 277;
pair<int, int>p[MAXN];
void power()
{
    p[0] = {1, 1};
    for (int i = 1; i < MAXN; i++) {
        p[i].first = 1LL * p[i - 1].first * b1 % mod1;
        p[i].second = 1LL * p[i - 1].second * b2 % mod2;
    }
}

struct Hash
{
    int n;
    vector<pair<int, int>>hs;

    Hash(string s)
    {
        n = s.size();
        hs.resize(n + 5);
        // ap^k + bp^(k-1) + c
        for (int i = 1; i <= n; i++) {
            hs[i].first = (1LL * hs[i - 1].first * b1 + (s[i - 1] - 'a' + 1)) % mod1;
            hs[i].second = (1LL * hs[i - 1].second * b2 + (s[i - 1] - 'a' + 1)) % mod2;
        }
    }

    pair<int, int> get_hash(int l, int r)
    {
        int an1 = (hs[r].first - (1LL * hs[l - 1].first * p[r - l + 1].first) % mod1 + mod1) % mod1;
        int an2 = (hs[r].second - (1LL * hs[l - 1].second * p[r - l + 1].second) % mod2 + mod2) % mod2;
        return {an1, an2};
    }

};
void solve()
{
    string s, t;
    int k;
    cin >> s >> t >> k;
    map<int, int> bad;
    int n = s.size();

    set<pr>st;
    Hash H(s);

    for (int i = 0; i < n; i++) {
        int cn = 0;

        for (int j = i; j < n; j++) {
            if (t[s[j] - 'a'] == '0') cn++;
            if (cn > k) break;
            auto rs = H.get_hash(i + 1, j + 1);
            st.insert(rs);
        }
    }

    cout << (int)st.size() << en;
}
int main()
{
    IOS;
    ll t;
    t = 1;
    // cin >> t;
    power();
    int c = 0;
    while ( t-- )
    {
        // cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/271/problem/D
