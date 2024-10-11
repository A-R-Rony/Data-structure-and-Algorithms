#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb     push_back
#define totalone(mask)  __builtin_popcount(mask)
#define chkbit(mask,bit)  (mask&(1LL << bit))

#define en "\n"
#define MAXN 200010
#define inf 1e6+5
const int mod = 1e9 + 7;

struct two_sat {
    int n;
    vector<vector<int>>g, rg;
    vector<int>comp, topological_order, answer;
    vector<bool>vis;

    two_sat() {}
    two_sat(int _n) {init(_n);}
    // 0-indexed node
    void init(int _n)
    {
        n = _n;
        g.assign(2 * n, vector<int>());
        rg.assign(2 * n, vector<int>());
        comp.resize(2 * n); vis.resize(2 * n);
        answer.resize(2 * n);
    }
    void add_edge(int u, int v)
    {
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    //At least one of them is true: (x U y) <=> (~x -> y) & (~y -> x)
    void add_clause_or(int i, bool f, int j, bool g)
    {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }
    // Only one of them is true: (x U y) & (~x U ~y)
    void add_clause_xor(int i, bool f, int j, bool g)
    {
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }
    // Both of them have the same value: (~x U y) & (x U ~y)
    void add_clause_and(int i, bool f, int j, bool g)
    {
        add_clause_xor(i, !f, j, g);
    }
    //SCC (Kosaraju): Finding topological sort
    void dfs(int nd)
    {
        vis[nd] = 1;
        for (const auto &i : g[nd])
        {
            if (vis[i]) continue;
            dfs(i);
        }
        topological_order.push_back(nd);
    }
    void scc(int nd, int id)
    {
        vis[nd] = 1;
        comp[nd] = id;
        for (const auto &i : rg[nd])
        {
            if (vis[i]) continue;
            scc(i, id);
        }
    }
    // assignment valid or report
    bool satisfiable() {
        fill(vis.begin(), vis.end(), false);
        for (int i = 0; i < 2 * n; i++)
        {
            if (!vis[i]) dfs(i);
        }
        reverse(topological_order.begin(), topological_order.end());
        fill(vis.begin(), vis.end(), false);

        int id = 0;
        for (const auto &i : topological_order)
            if (!vis[i]) scc(i, id++);

        for (int i = 0; i < n; i++)
        {
            if (comp[i] == comp[n + i]) return false;
            answer[i] = (comp[i] > comp[n + i] ? 1 : 0);
        }
        return true;
    }
};
void solve()
{
    int n;
    cin >> n;
    int b[3][n];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    two_sat ts(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int nxt = (j + 1) % 3;
            ts.add_clause_or(abs(b[j][i]) - 1, b[j][i] > 0, abs(b[nxt][i]) - 1, b[nxt][i] > 0);
        }
    }
    cout << (ts.satisfiable() ? "YES\n" : "NO\n");
}
int main()
{
    IOS;
    ll t;
    t = 1;
    cin >> t;
    while ( t-- )
    {
        // cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/1971/problem/H
