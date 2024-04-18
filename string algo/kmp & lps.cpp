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
#define pb push_back

#define totalone(mask) __builtin_popcount(mask)
#define chkbit(mask,bit) (mask&(1LL << bit))
#define setbit(mask,bit) (mask|(1LL << bit))
#define cngbit(mask,bit) (mask^(1LL << bit))

#define en "\n"
#define dbg(x) cerr<<#x<<" is : "<<x<<en;
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define report cout<<-1<<en
#define sum(n) ((1LL*(n)*(n+1))/ 2LL)
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)
#define coutv(v) for(auto i: v) cout<<i<<" ";cout<<en;
#define cinv(v) for(auto &i: v) cin >> i;

#define MAXN 200010
#define inf 1e6+5
const int mod = 1e9 + 7;


// Print how many times a pattern occurs in the string "s"
// and print their starting index as well

vector<int> lps_maker(string pat)
{
    // abacaba
    int n = pat.size();
    vector<int> lps(n, 0);

    for (int i = 1; i < n; i++)
    {
        int len = lps[i - 1];
        while (len > 0 && pat[i] != pat[len]) {
            len = lps[len - 1];
        }
        if (pat[i] == pat[len]) {
            len++;
        }
        lps[i] = len;
    }

    return lps;

}

void kmp(string s, string pat)
{
    vector<int>lps = lps_maker(pat);
    int i = 0, j = 0;

    vector<int>v;

    while (i < (int)s.size())
    {
        if (s[i] == pat[j]) {
            j++; i++;
        }
        else {
            if (j > 0)
                j = lps[j - 1];
            else i++;
        }

        if (j == (int)pat.size())
        {
            v.pb(i - (int)pat.size());
            j = lps[j - 1];
        }
    }

    if ((int)v.size() == 0 ) cout << "No match found\n";
    else coutv(v);

}
void solve()
{
    string s, pat;
    cin >> s >> pat;
    kmp(s, pat);
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
