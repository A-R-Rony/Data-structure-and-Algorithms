#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>order_set;
typedef pair<int, int>pr;
#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb     push_back
#define totalone(mask)  __builtin_popcount(mask)
#define chkbit(mask,bit)  (mask&(1LL << bit))

// debug section start
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// debug section closed

#define en "\n"
#define sum(n) ((1LL*(n)*(n+1))/ 2LL)
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)

#define MAXN 1005
#define inf 1e6+5
const int mod = 1e9 + 7;
int n, m;
int cc[MAXN][MAXN], col[MAXN][MAXN];
char a[MAXN][MAXN];
vector<vector<int>>vis;
int color[1000005];
int name;

void dekhao()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << en;
    }
    cout << en;
}
void line(int x1, int y1, int x2, int y2)
{
    int tx = x1;
    int ty = y1;
    while (1)
    {
        a[tx][ty] = '*';
        if (tx == x2 && ty == y2) break;
        if (x2 > x1) tx++;
        else if (x2 < x1) tx--;
        if (y2 > y1 ) ty++;
        else if (y2 < y1) ty--;
    }
    // dekhao();
}
void rectangel(int x1, int y1, int x2, int y2)
{
    line(x1, y1, x2, y1);
    line(x1, y1, x1, y2);
    line(x1, y2, x2, y2);
    line(x2, y2, x2, y1);
}


bool valid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && a[x][y] != '*')
        return true;
    return false;
}
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    vis[x][y] = 1;
    int age = cc[x][y];
    cc[x][y] = name;
    color[name] = color[age];

    for (int i = 0 ; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (valid(tx, ty)) {
            dfs(tx, ty);
        }
    }
}
void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = '.';
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        char ty, c;
        int x, y, x1, y1, x2, y2;
        cin >> ty;
        if (ty == 'F') {
            cin >> c >> y >> x;
            int tm = cc[x][y];// tm is a connected component
            color[tm] = (c - 'a' + 1);
        }
        else {
            cin >> y1 >> x1 >> y2 >> x2;
            if (ty == 'R')
                rectangel(x1, y1, x2, y2);
            else line(x1, y1, x2, y2);

            vis.assign(n, vector<int>(m));
            name = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (vis[i][j] || a[i][j] == '*') continue;
                    name++;
                    dfs(i, j);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*')continue;
            int col = color[cc[i][j]];
            if (col == 0) {
                a[i][j] = '.';
            }
            else
                a[i][j] = (col - 1 + 'a');
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++ ) {
            cout << a[i][j];
        }
        cout << en;
    }
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
        // cout << "Case " << ++c << ": ";
        solve();
    }
    return 0;
}
// https://toph.co/p/stephen-bob-and-tomato-s-canvas
