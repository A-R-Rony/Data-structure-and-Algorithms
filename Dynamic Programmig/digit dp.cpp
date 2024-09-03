#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

#define all(i)     i.begin() , i.end()
#define pb     push_back
#define en "\n"

#define MAXN 200010
const int mod = 1e9 + 7;
string l, r, s;
ll m, n;

ll mem[55][55][55][2][55];
ll done[55][55][55][2][55]; int timer = 1;

ll f(ll i, ll rm, ll rs, bool x, int m)
{
    if (i < 0)
    {
        if (rm == 0 && rs == 0) {
            return 1;
        }

        return 0;
    }
    ll &an = mem[i][rm][rs][x][m];
    if (~an && (x == 0 || done[i][rm][rs][x][m] == timer)) return an;
    done[i][rm][rs][x][m] = timer;

    ll last;
    last = (x ? s[i] - '0' : 9);
    an = 0;
    for (ll d = 0; d <= last; d++) {
        an += f(i - 1, (rm * 10 + d) % m, (rs + d) % m, (x && (last == d)), m);
        an %= mod;
    }
    return an;
}


ll get(string &t, ll m)
{
    s = t;
    reverse(all(s));
    n = s.size();
    ll an = f(n - 1, 0, 0, 1, m) % mod;
    timer++;
    return an;
}
int bad(string s, int m)
{
    ll rm = 0 , rs = 0;
    for (auto i : s) {
        rm = rm * 10 + (i - '0');
        rm %= m;
        rs += ( i - '0');
        rs %= m;
    }
    if (!rm && !rs) return 1;
    return 0;
}
void solve()
{
    cin >> l >> r >> m;
    s = r; reverse(all(s));
    n = s.size();

    ll an = get(r, m) - get(l, m) + bad(l, m);
    an += mod; an %= mod;

    cout << an << en;

}
int main()
{
    IOS;
    ll t;
    t = 1;
    cin >> t;

    memset(mem, -1, sizeof(mem));

    int c = 0;
    while ( t-- )
    {
        // cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}
// https://toph.co/p/m-beautiful-numbers
