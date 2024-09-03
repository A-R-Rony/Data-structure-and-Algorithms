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

#define MAXN 5000010
#define inf 1e6+5
const int mod = 1e9 + 7;

vector<string>str;
struct TRIE
{
    int cnt[MAXN];
    int idx[MAXN];
    int g[MAXN][26];
    int cur;

    pair<int, string>ans[MAXN];
    bool ok = true;

    void init()
    {
        memset(cnt, 0, sizeof(cnt));
        memset(g, -1, sizeof(g));
        memset(idx, -1, sizeof(idx));
        cur = 0;
    }
    void Insert(string &s, int id)
    {
        int nd = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            if (g[nd][c] == -1)
            {
                g[nd][c] = ++cur;
            }
            nd = g[nd][c];
        }
        cnt[nd]++;
        idx[nd] = id;

    }
    void dfs(int nd)
    {
        debug(nd);
        ans[nd] = {0, ""};
        if (idx[nd] != -1) ans[nd] = {cnt[nd], str[idx[nd]]};
        for (int c = 0; c < 26; c++)
        {
            int nxt = g[nd][c];
            if (nxt == -1) continue;
            dfs(nxt);
            if (ans[nd].ft < ans[nxt].ft) ans[nd] = ans[nxt];
        }
    }
    pair<int, string> query(string &s)
    {
        int nd = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            if (g[nd][c] == -1) {

                return { -1, ""};
            }
            nd = g[nd][c];
        }
        return ans[nd];
    }

} tri;
void solve()
{
    int n;
    cin >> n;
    tri.init();

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        str.push_back(s);
        tri.Insert(s, i);
    }
    debug(tri.cur);
    tri.dfs(0);

    int q;
    cin >> q;
    int c = 0;
    while (q--)
    {
        cout << "Case " << ++c << ": ";
        string s;
        cin >> s;
        pair<int, string>an = tri.query(s);
        if (an.ft == -1) cout << -1 << en;
        else cout << an.sn << " " << an.ft << en;

        // cout << ans.ft<<" "<<ans.sn << en;
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
        // cout << "Case " << ++c << ": ";
        solve();
    }
    return 0;
}
//https://toph.co/p/the-punishment
