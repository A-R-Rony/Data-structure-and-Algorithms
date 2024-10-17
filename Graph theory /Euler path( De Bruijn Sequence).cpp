#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

typedef long long int ll;
#define all(i)     i.begin() , i.end()
#define en "\n"
#define MAXN 100010
const int mod = 1e9 + 7;

int n, edges;
vector<int>g[MAXN];
vector<int>path, in, out, done;

void SetUp(int n)
{
    path.clear();
    edges = 0;
    in.resize(n + 1, 0);
    out.resize(n + 1, 0);
    done.resize(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        for (auto j : g[i])
        {
            out[i]++; in[j]++; edges++;
            // cout << i << " " << j << en;
        }
    }
}
int FirstNode(int n)
{
    int cn1 = 0, cn2 = 0;
    int nd = 0;
    for (int i = 0; i <= n; i++)
    {
        if (in[i] - out[i] == 1) cn1++;
        if (out[i] - in[i] == 1) cn2++, nd = i;
        if (abs(in[i] - out[i]) > 1) return -1;
    }
    if (cn1 > 1 || cn2 > 1) return -1;
    if (nd != 0) return nd;
    for (int i = 1; i <= n; i++) {
        if (out[i]) nd = i;
    }
    return nd;
}
void dfs(int nd)
{
    while (done[nd] < g[nd].size()) {
        dfs(g[nd][done[nd]++]);
    }
    path.push_back(nd);
}
bool EulerPath(int n)
{
    SetUp(n);
    int nd = FirstNode(n);
    if (nd == -1) return false;
    dfs(nd);

    if (path.size() != edges + 1) return false;
    reverse(all(path));
    return true;
}
void solve()
{
    int n;
    cin >> n;
    int tot = (1 << n - 1);
    if (n == 1) {
        cout << "01" << en; return;
    }
    for (int i = 0; i < tot; i++)
    {
        int a = (2 * i) % (1 << (n - 1));
        int b = (2 * i + 1) % (1 << n - 1);
        g[i].push_back(a);
        g[i].push_back(b);
    }
    EulerPath(tot - 1);
    // for (auto i : path) cout << i << " "; cout << en;
    string an ;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((path[0] & (1 << i))) an.push_back('1');
        else {
            if (an.size())
                an.push_back('0');
        }
    }
    for (int i = 1; i < path.size(); i++)
    {
        if (path[i] & 1)
            an.push_back('1');
        else an.push_back('0');
    }
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
// https://cses.fi/problemset/task/1692/
