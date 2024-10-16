#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb     push_back
#define chkbit(mask,bit)  (mask&(1LL << bit))

#define en "\n"
#define MAXN 200010
#define inf 1e6+5
const int mod = 1e9 + 7;

/*
all the edges should be in the same connected component
#directed graph: euler path: for all -> indeg = outdeg or nodes having indeg > outdeg = outdeg > indeg = 1 and for others in = out
#directed graph: euler circuit: for all -> indeg = outdeg
*/

//euler path in a directed graph
//it also finds circuit if it exists
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
    for (int i = 1; i <= n; i++)
    {
        for (auto j : g[i])
        {
            out[i]++; in[j]++; edges++;
        }
    }
}
int FirstNode(int n)
{
    int cn1 = 0, cn2 = 0;
    int nd = 0;
    for (int i = 1; i <= n; i++)
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
    path.pb(nd);
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
    cin >> n;
    map<string, int>ma;
    map<int, string>id;
    int cn = 0;

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        string a = s.substr(0, 2);
        string b = s.substr(1);
        if (ma.find(a) == ma.end()) ma[a] = ++cn, id[ma[a]] = a;
        if (ma.find(b) == ma.end()) ma[b] = ++cn, id[ma[b]] = b;
        g[ma[a]].pb(ma[b]);
    }

    bool ok = EulerPath(cn);
    if (!ok) {
        cout << "NO\n"; return;
    }
    cout << "YES\n";

    string an = id[path[0]];
    for (int i = 1; i < path.size(); i++)
    {
        an.pb(id[path[i]][1]);
    }
    cout << an << en;

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
// https://codeforces.com/contest/508/problem/D
