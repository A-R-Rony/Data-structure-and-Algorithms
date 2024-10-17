#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

typedef long long int ll;
#define all(i)     i.begin() , i.end()
#define chkbit(mask,bit)  (mask&(1LL << bit))
#define pb     push_back
#define en "\n"
#define MAXN 100010
const int mod = 1e9 + 7;
int n, m;
vector<int>g[21];
int mem[20][(1 << 21)];

int f(int nd, int mask)
{
    mask = mask ^ (1 << nd);
    if (mask == 0 && nd == n - 1) {
        return 1;
    }
    if (nd == n - 1) {
        return 0;
    }
    if (mem[nd][mask] != -1) return mem[nd][mask];
    int an = 0;

    for (auto i : g[nd])
    {
        if (chkbit(mask, i))
        {
            an += f(i, mask);
            an %= mod;
        }
    }
    return mem[nd][mask] = an;

}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y; x--, y--;
        g[x].pb(y);
    }
    memset(mem, -1, sizeof(mem));
    int an = f(0, (1 << n) - 1);
    cout << an << en;
}
int main()
{
    IOS;
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

// https://cses.fi/problemset/task/1690/
