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
#define setbit(mask,bit) (mask|(1LL << bit))
#define cngbit(mask,bit) (mask^(1LL << bit))

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
#define dbg(x) cerr<<#x<<" is : "<<x<<en;
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define report cout<<-1<<en
#define sum(n) ((1LL*(n)*(n+1))/ 2LL)
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)
#define coutv(v) for(auto i: v) cout<<i<<" ";cout<<en;
#define cinv(v) for(auto &i: v) cin >> i;

#define MAXN 1000000
#define inf 1e6+5
const int mod = 1e9 + 7;

struct TRIE
{
    int g[MAXN][10];
    int cnt[MAXN];
    int idx[MAXN];
    int cur;

    void init()
    {
        cur = 0;
        memset(g, -1, sizeof(g));
        memset(cnt, 0, sizeof(cnt));
        memset(idx, -1, sizeof(idx));
    }
    void Insert(string &s, int id)
    {
        int nd = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int d = s[i] - '0';
            if (g[nd][d] == -1) g[nd][d] = ++cur;
            nd = g[nd][d];
        }
        // debug(s, id, nd);

        if (idx[nd] != id) {
            idx[nd] = id;
            cnt[nd]++;
        }
    }

    bool query(string &s)
    {
        int nd = 0;
        if (s == "1") {
            debug(s);
        }
        for (int i = 0; i < s.size(); i++)
        {
            int d = s[i] - '0';
            if (g[nd][d] == -1) return false;
            nd = g[nd][d];
        }
        if (cnt[nd] == 1) return true;
        return false;
    }


} tri;
void solve()
{
    int n;
    cin >> n;

    tri.init();

    vector<string>v;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.pb(s);
        for (int j = 0; j < 9; j++) {
            string tm = "";
            for (int k = j; k < 9; k++) {
                tm += s[k];
                tri.Insert(tm, i);
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        string s = v[i];
        string t = "8888888888";

        for (int j = 0; j < 9; j++) {
            string tm = "";
            bool com = false;
            for (int k = j; k < 9; k++) {
                tm += s[k];
                bool ok = tri.query(tm);
                if (ok && (int)t.size() > (int)tm.size()) {
                    t = tm;
                }
            }

        }

        cout << t << en;
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
