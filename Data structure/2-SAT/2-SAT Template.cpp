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
