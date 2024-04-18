
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
#define here cout<<"rony\n"
#define dbg(x) cerr<<#x<<" is : "<<x<<en;
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define report cout<<-1<<en
#define sum(n) ((1LL*(n)*(n+1))/ 2LL)
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)
#define coutv(v) for(auto i: v) cout<<i<<" ";cout<<en;
#define cinv(v) for(auto &i: v) cin >> i;

#define MAXN 100005
#define inf 1e6+5
const int mod = 998244353;

int n;
int a[MAXN];
int b[MAXN];

struct segment_tree
{
    struct node {
        int suru , ses, one;
        bool flag = 0;

        void init(int l, int r) {
            suru = l, ses = r;
            if (l == r) one = b[l];
        }
    } g[4 * MAXN];

    void build(int cn, int l, int r)
    {
        g[cn].init(l, r);

        if (l == r ) return;
        int md = l + (r - l) / 2;

        build(cn * 2, l, md);
        build(cn * 2 + 1, md + 1, r);

        g[cn].one = g[cn * 2].one + g[cn * 2 + 1].one;
    }

    void distribute(node &A, node &B, node &C)
    {
        if (A.flag == false) return ;
        B.flag ^= 1;
        C.flag ^= 1;
        A.flag = 0;
    }

    int get(node &A)
    {
        if (A.flag == false) return A.one;
        return (A.ses - A.suru + 1) - A.one;
    }

    void fill_cn(node &cn, node &ln, node &rn) // fill_current_node
    {
        cn.one = get(ln) + get(rn);
    }

    void update(int cn, int l, int r)
    {
        int x = g[cn].suru;
        int y = g[cn].ses;

        if (y < l || x > r) return;
        if (l <= x && r >= y ) {
            g[cn].flag ^= 1;
            return;
        }

        distribute(g[cn], g[cn * 2 ], g[cn * 2 + 1]);
        update(cn * 2, l, r);
        update(cn * 2 + 1, l, r);

        fill_cn(g[cn], g[cn * 2], g[cn * 2 + 1]);
    }

    int query(int cn, int l, int r)
    {
        int x = g[cn].suru;
        int y = g[cn].ses;
        if (y < l || x > r) return 0;

        if (l <= x && r >= y ) {
            return get(g[cn]);
        }

        distribute(g[cn], g[cn * 2], g[cn * 2 + 1]);

        int ans = query(cn * 2, l, r);
        ans += query(cn * 2 + 1, l, r);
        fill_cn(g[cn], g[cn * 2], g[cn * 2 + 1]);
        return ans;
    }

} stre[22];



ll SUM(int l, int r)
{
    ll an = 0;
    for (int bit = 0; bit < 20; bit++)
    {
        an += (1LL << bit) * stre[bit].query(1, l, r);
    }
    return an;
}

void push(int l, int r, int x)
{
    for (int bit = 0; bit < 20; bit++)
    {
        if (chkbit(x, bit)) {
            stre[bit].update(1, l, r);
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int bit = 0; bit < 20; bit++)
    {
        for (int i = 1; i <= n; i++)
        {
            b[i] = (chkbit(a[i], bit) ? 1 : 0);
        }
        stre[bit].build(1, 1, n);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int t, l, r, x;
        cin >> t >> l >> r;
        if (t == 1) {
            cout << SUM(l, r) << en;
            continue;
        }
        cin >> x;
        push(l, r, x);
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
// https://codeforces.com/contest/242/problem/E
