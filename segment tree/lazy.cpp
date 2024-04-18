
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

#define MAXN 200010
#define inf 1e6+5
const int mod = 1e9 + 7;

ll n;
ll a[MAXN];

void convert(vector<ll>&ty, string &s)
{
    ll n = s.size();
    ll x = 0; ll sgn = 1;

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == ' ' || i == n - 1) {
            if (i == n - 1) x = x * 10 + s[i] - '0';
            ty.pb(x * sgn);
            sgn = 1;
            x = 0;
            continue;
        }
        if (s[i] == '-') sgn = -1;
        else {
            x = x * 10 + s[i] - '0';
        }
    }
}

struct segment_tree
{
    struct node {
        ll suru , ses, mn, lazy;

        void init(ll l, ll r) {
            lazy = 0;
            suru = l, ses = r;
            if (l == r) mn = a[l];
        }
    } g[4 * MAXN];

    void fill_cn(node &cn, node &ln, node &rn) // fill_current_node
    {
        cn.mn = min(ln.mn, rn.mn);
    }

    void build(ll cn, ll l, ll r)
    {
        g[cn].init(l, r);

        if (l == r ) return;
        ll md = l + (r - l) / 2;

        build(cn * 2, l, md);
        build(cn * 2 + 1, md + 1, r);

        fill_cn (g[cn], g[cn * 2] , g[cn * 2 + 1]);
    }

    void distribute(node &cn, node &ln, node &rn)
    {
        ln.lazy += cn.lazy;
        ln.mn += cn.lazy;
        rn.mn += cn.lazy;
        rn.lazy += cn.lazy;

        cn.lazy = 0;
    }

    void update(ll cn, ll l, ll r, ll val)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;

        if (y < l || x > r) return;
        if (l <= x && r >= y ) {
            g[cn].mn += val;
            g[cn].lazy += val;
            return;
        }

        distribute(g[cn], g[cn * 2], g[cn * 2 + 1]);

        update(cn * 2, l, r, val);
        update(cn * 2 + 1, l, r, val);

        fill_cn(g[cn], g[cn * 2], g[cn * 2 + 1]);
    }

    ll query(ll cn, ll l, ll r)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;
        if (y < l || x > r) return 1e14;

        if (l <= x && r >= y ) return g[cn].mn;

        distribute(g[cn], g[cn * 2], g[cn * 2 + 1]);

        ll ans = query(cn * 2, l, r);
        ans = min(ans, query(cn * 2 + 1, l, r));
        return ans;
    }

} stre;
void solve()
{
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    stre.build(1, 0, n - 1);


    ll q ;
    cin >> q;

    getline(cin, s);

    while (q--)
    {
        ll x;

        getline(cin, s);
        vector<ll>ty;

        convert(ty, s);

        if ((ll) ty.size() == 2)
        {
            ll an = INT_MAX;
            if (ty[0] <= ty[1]) an = stre.query(1, ty[0], ty[1]);
            else {
                an = min(an, stre.query(1, ty[0], n - 1));
                an = min(an, stre.query(1, 0, ty[1]));
            }
            cout << an << en;
        }
        else {
            if (ty[0] <= ty[1]) stre.update(1, ty[0], ty[1], ty[2]);
            else {
                stre.update(1, ty[0], n - 1, ty[2]);
                stre.update(1, 0, ty[1], ty[2]);
            }
        }
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

//https://codeforces.com/contest/52/problem/C
