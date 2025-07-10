auto dfs = [&](int u, int p, auto&& dfs) -> void {
	for (int v : adj[u])
		if (v != p) {
			col[v] = col[u] ^ 1;
			dfs(v, u, dfs);
		}
};
