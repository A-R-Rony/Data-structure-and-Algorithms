#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define en "\n"
#define pb push_back

#define MAXN 200010
#define inf 1e9+5
const int mod = 1e9 + 7;
ll n, m;
vector<ll>g[MAXN];
ll vis[MAXN], dp[MAXN];

ll f(ll i)
{
    if (i == n) {
        vis[n] = 1;
        return 0;
    }
    if (g[i].size() == 0) {
        return INT_MIN;
    }

    if (vis[i]) return dp[i];
    vis[i] = 1;

    ll an = INT_MIN;
    for (auto ch : g[i])
    {
        an = max(an, 1 + f(ch));
    }
    return dp[i] = an;
}
vector<ll>an;
void path(ll nd)
{
    ll ans = 0;
    ll id = -1;
    for (auto i : g[nd])
    {
        if (ans < f(i)) {
            id = i;
            ans = f(i);
        }
    }
    if (id != -1) {
        an.pb(id);
        path(id);
    }
}
void solve()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
    }
    ll rs = f(1);
    if (vis[n] == 0) cout << "IMPOSSIBLE\n";
    else {
        cout << rs + 1 << en;
        an.pb(1);
        path(1);
        an.pb(n);
        for (auto i : an) cout << i << " "; cout << en;
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
// https://cses.fi/problemset/task/1680/
