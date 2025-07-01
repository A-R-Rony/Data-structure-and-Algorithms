struct segment_tree
{
    struct node {
        ll suru , ses, sm, lazy;

        void init(ll l, ll r) {
            suru = l, ses = r; lazy = 0;
            if (l == r) {
                sm = 0;
            }
        }
    } g[4 * MAXN];

    void build(ll cn, ll l, ll r)
    {
        g[cn].init(l, r);

        if (l == r ) return;
        ll md = l + (r - l) / 2;

        build(cn * 2, l, md);
        build(cn * 2 + 1, md + 1, r);
        g[cn].sm = g[cn * 2].sm + g[cn * 2 + 1].sm;
    }

    ll Range(ll x, ll y)
    {
        return y - x + 1;
    }

    void distribute(ll cn, ll ln, ll rn)
    {
        g[ln].lazy += g[cn].lazy;
        g[rn].lazy += g[cn].lazy;
        g[ln].sm += Range(g[ln].suru, g[ln].ses) * g[cn].lazy;
        g[rn].sm += Range(g[rn].suru, g[rn].ses) * g[cn].lazy;

        g[cn].lazy = 0;
    }
    void update(ll cn, ll l, ll r, ll val)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;

        if (y < l || x > r) return;
        if (l <= x && r >= y ) {
            g[cn].lazy += val;
            g[cn].sm += val * ( y - x + 1);
            return;
        }

        distribute(cn, cn * 2, cn * 2 + 1);

        update(cn * 2, l, r, val);
        update(cn * 2 + 1, l, r, val);

        g[cn].sm = g[cn * 2].sm + g[cn * 2 + 1].sm;
    }

    ll query(ll cn, ll l, ll r)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;
        if (y < l || x > r) return 0;

        if (l <= x && r >= y ) {
            return g[cn].sm;
        }

        distribute(cn, cn * 2, cn * 2 + 1);

        ll ans = query(cn * 2, l, r);
        ans += query(cn * 2 + 1, l, r);
        return ans;
    }

} stre;
