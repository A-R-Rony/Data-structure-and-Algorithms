struct segment_tree
{
    struct node {
        int suru , ses, zero = 0, one = 0;
        bool ok = false;
 
        void init(int l, int r) {
            suru = l, ses = r;
            ok = false;
            zero = 0, one = 0;
            if (l == r) {
                if (s[l] == '0') zero = a[l];
                else one = a[l];
            }
        }
    } g[4 * MAXN];
 
 
 
    void build(int cn, int l, int r)
    {
        g[cn].init(l, r);
 
        if (l == r ) return;
        int md = l + (r - l) / 2;
 
        build(cn * 2, l, md);
        build(cn * 2 + 1, md + 1, r);
 
        g[cn].zero = (g[cn * 2].zero ^ g[cn * 2 + 1].zero);
        g[cn].one = (g[cn * 2].one ^ g[cn * 2 + 1].one);
    }
 
    void distribute(node &A, node &B)
    {
        A.ok = (A.ok ^ 1);
        B.ok = (B.ok ^ 1);
    }
 
    void update(int cn, int l, int r)
    {
        int x = g[cn].suru;
        int y = g[cn].ses;
 
        if (y < l || x > r) return;
        if (l <= x && r >= y ) {
            g[cn].ok = (g[cn].ok ^ 1);
            return;
        }
 
        if (g[cn].ok == true)
            distribute(g[cn * 2], g[cn * 2 + 1]);
 
        g[cn].ok = false;
 
        update(cn * 2, l, r);
        update(cn * 2 + 1, l, r);
        int ek = 0, dui = 0;
 
        if (g[cn * 2].ok == true) g[cn].zero = g[cn * 2].one, g[cn].one = g[cn * 2].zero;
        else g[cn].zero = g[cn * 2].zero , g[cn].one = g[cn * 2].one;
 
        if (g[cn * 2 + 1].ok == true) g[cn].zero ^= g[cn * 2 + 1].one, g[cn].one ^= g[cn * 2 + 1].zero;
        else g[cn].zero ^= g[cn * 2 + 1].zero, g[cn].one ^= g[cn * 2 + 1].one;
    }
 
    int query(int cn, int l, int r, int st)
    {
        int x = g[cn].suru;
        int y = g[cn].ses;
        if (y < l || x > r) return 0;
 
        if (l <= x && r >= y ) {
            if (g[cn].ok == false) {
 
                if (st == 0) return g[cn].zero;
                return g[cn].one;
            }
            if (st == 0) return g[cn].one;
            return g[cn].zero;
        }
 
        if (g[cn].ok == true) {
            g[cn].ok = false;
            distribute(g[cn * 2], g[cn * 2 + 1]);
        }
 
        int ans = query(cn * 2, l, r, st);
        ans = (ans ^ query(cn * 2 + 1, l, r, st));
        return ans;
    }
 
} stre;
