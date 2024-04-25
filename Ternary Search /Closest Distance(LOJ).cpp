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
const double eps = 0.000000001;
struct point {
    double x, y;
};

double point1(double l, double r)
{
    double an = l + (r - l) / 3.0;
    return an;
}
double point2(double l, double r)
{
    double an = r - (r - l) / 3.0;
    return an;
}
double distance(point a, point b)
{
    double an = (a.x - b.x) * (a.x - b.x);
    an += ((a.y - b.y) * (a.y - b.y));
    an = sqrtl(an);
    return an;
}
double ternary_search(point a, point b, point c, point d)
{
    while (distance(a, b) > eps) {
        point am1, am2, cm1, cm2;
        am1.x = point1(a.x, b.x);
        am1.y = point1(a.y, b.y);
        am2.x = point2(a.x, b.x);
        am2.y = point2(a.y, b.y);

        cm1.x = point1(c.x, d.x);
        cm1.y = point1(c.y, d.y);
        cm2.x = point2(c.x, d.x);
        cm2.y = point2(c.y, d.y);

        if (distance(am1, cm1) > distance(am2, cm2)) {
            a = am1;
            c = cm1;
        }
        else if (distance(am1, cm1) < distance(am2, cm2)) {
            b = am2;
            d = cm2;
        }
        else {
            a = am1;
            b = am2;
            c = cm1;
            d = cm2;
        }

    }

    return distance(a, c);
}
void solve()
{
    point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    double an = ternary_search(a, b, c, d);
    cout << fixed << setprecision(10) << an << en;
}
int main()
{
    IOS;
    ll t;
    t = 1;
    cin >> t;

    int c = 0;
    while ( t-- )
    {
        cout << "Case " << ++c << ": ";
        solve();
    }
    return 0;
}
// https://lightoj.com/problem/closest-distance
