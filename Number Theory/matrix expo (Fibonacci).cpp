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

#define MAXN 200010
#define inf 1e6+5
const int mod = 1e9 + 7;

struct Matrix
{
    ll n, m;
    vector<vector<ll>>v;
    Matrix() {}
    Matrix(ll _n, ll _m) {n = _n; m = _m; v.assign(n, vector<ll>(m, 0));}
    Matrix(vector<vector<ll>>a) {n = a.size(); m = n ? a[0].size() : 0; v = a;}

    inline void make_unit() {
        assert(n == m);
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                v[i][j] = (i == j);
            }
        }
    }
    inline Matrix operator + (const Matrix &b) {
        assert(n == b.n && m == b.m);
        Matrix ans(n, m);
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                ans.v[i][j] = (v[i][j] + b.v[i][j]) % mod;
            }
        }
        return ans;
    }
    inline Matrix operator - (const Matrix &b) {
        assert(n == b.n && m == b.m);
        Matrix ans(n, m);
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < m; j++)
                ans.v[i][j] = (v[i][j] - b.v[i][j] + mod) % mod;
        return ans;
    }
    inline Matrix operator * (const Matrix &b)
    {
        assert(m == b.n);// column of first matrix = row of second matrix
        Matrix ans(n, b.m); // size of square matrix
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < b.m; j++)
                for (ll k = 0; k < m; k++)
                    ans.v[i][j] = (ans.v[i][j] + (v[i][k] * b.v[k][j]) % mod) % mod;
        return ans;
    }
    inline Matrix expo (ll k)
    {
        assert(n == m);
        Matrix tmp = v, ans(n, n);
        ans.make_unit();
        while (k)
        {
            if (k % 2) {
                ans = ans * tmp;
            }
            tmp = tmp * tmp;
            k /= 2;
        }
        return ans;
    }
    inline bool operator == (const Matrix &b) {return v == b.v;}
    inline bool operator != (const Matrix &b) {return v != b.v;}
};

void solve()
{
    ll n;
    cin >> n;
    if (n == 0) {
        cout << 0 << en; return;
    }
    Matrix a(2, 2);
    a.v[0][0] = 1;
    a.v[0][1] = 1;
    a.v[1][0] = 1;
    a.v[1][1] = 0;
    /*
    |f(2)| = | 1 1 |    | f(1) |
    |f(1)|   | 1 0 | .  | f(0) |
    so, f(2) = 1*f(1) + 1*f(0)
        f(1) = 1*f(1) + 0*f(0)
     |f(3)| = | 1 1 |    | f(2) |
     |f(2)|   | 1 0 | .  | f(1) |

     |f(3)| = | 1 1 |   | 1 1 |   | f(1) |
     |f(2)|   | 1 0 | . | 1 0 | . | f(0) |
    */

    Matrix ans = a.expo(n - 1);
    cout << ans.v[0][0] << en;
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
// https://codeforces.com/gym/102644/problem/C
