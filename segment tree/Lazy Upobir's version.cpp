struct segment_tree
{
    struct node {
        ll suru , ses;
        pair<ll, ll>an;

        ll lazy = 0;

        void init(ll l, ll r) {
            suru = l, ses = r;
            if (l == r) {
                lazy = 0;
                an.first = a[l];
                an.second = l;
            }
            lazy = 0;
        }
    } g[4 * MAXN];

    pair<ll, ll>calc(pair<ll, ll>x, pair<ll, ll>y)
    {
        if (x.first < y.first) return x;
        if (y.first < x.first) return y;
        return make_pair(x.first, max(x.second, y.second));
    }

    void build(ll cn, ll l, ll r)
    {
        g[cn].init(l, r);

        if (l == r ) return;
        ll md = l + (r - l) / 2;

        build(cn * 2, l, md);
        build(cn * 2 + 1, md + 1, r);
        g[cn].an = calc(g[cn * 2].an, g[cn * 2 + 1].an);
    }

    void distribute(ll cn, ll x, ll y)
    {
        if (x != y)
        {
            g[cn * 2].lazy += g[cn].lazy;
            g[cn * 2 + 1].lazy += g[cn].lazy;
        }
        g[cn].an.first += g[cn].lazy;
        g[cn].lazy = 0;
        return ;
    }

    void update(ll cn, ll l, ll r, ll val)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;

        distribute(cn, x, y);

        if (y < l || x > r) return;
        if (l <= x && r >= y ) {
            g[cn].lazy += val;
            distribute(cn, x, y);
            return;
        }

        update(cn * 2, l, r, val);
        update(cn * 2 + 1, l, r, val);

        g[cn].an = calc(g[cn * 2].an, g[cn * 2 + 1].an);
    }

    pair<ll, ll> query(ll cn, ll l, ll r)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;

        distribute(cn, x, y);
        if (y < l || x > r) return make_pair(inf, l);

        if (l <= x && r >= y )
            return g[cn].an;

        auto p = query(cn * 2, l, r);
        auto q = query(cn * 2 + 1, l, r);
        return calc(p, q);
    }

} stre;
