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

#define en "\n"
#define sum(n) ((1LL*(n)*(n+1))/ 2LL)
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)

#define MAXN 200010
#define inf 1e6+5
const int mod = 1e9 + 7;

vector<int> phi_maker(string s)
{
    int n = s.size();
    vector<int>phi(n);
    for (int i = 1; i < n; i++) {
        int len = phi[ i - 1];
        while (s[i] != s[len] && len > 0) {
            len = phi[len - 1];
        }

        if (s[len] == s[i]) {
            len++;
        }
        phi[i] = len;
    }
    return phi;
}
void solve()
{
    int n;
    cin >> n;
    string an;

    for (int i = 0 ; i < n; i++)
    {
        string s;
        cin >> s;
        auto phi = phi_maker(s);
        int MatchLen = 0;
        int start = max(0, (int)an.size() - (int)s.size());

        for (int j = start; j < an.size(); j++)
        {
            while (MatchLen > 0 && an[j] != s[MatchLen]) MatchLen = phi[MatchLen - 1];
            if (an[j] == s[MatchLen]) MatchLen++;
        }
        an += s.substr(MatchLen);
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
// https://codeforces.com/contest/1200/problem/E
