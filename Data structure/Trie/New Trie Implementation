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

#define MAXN 100010
#define inf 1e6+5
const int mod = 1e9 + 7;

struct Trie
{
    struct node {
        bool last;
        int destination[26];
        node()
        {
            last = false;
            memset(destination, -1, sizeof(destination));
        }
    };

    vector<node>trie;
    Trie() {
        trie.emplace_back();
    }

    void Insert(string s)
    {
        int current = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '.') {
                trie[current].last = 1;
                continue;
            }
            int id = s[i] - 'a';
            if (trie[current].destination[id] == -1) {
                trie[current].destination[id] = trie.size();
                trie.push_back(node());
            }
            current = trie[current].destination[id];
        }
        trie[current].last = 1;
    }

    bool query(string s)
    {
        int current = 0;
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] == '.') {
                if (trie[current].last == false) return false;
                continue;
            }
            int id = s[i] - 'a';
            if (trie[current].destination[id] == -1) return false;
            current = trie[current].destination[id];
        }
        return trie[current].last;

    }
    void Erase(string s)
    {
        int current = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '.') {
                trie[current].last = false;
                continue;
            }
            int id = s[i] - 'a';
            if (trie[current].destination[id] == -1) continue;
            current = trie[current].destination[id];
        }
        trie[current].last = false;
    }

};
void solve()
{
    int n;
    cin >> n;
    map<int, Trie>ma;
    while (n--)
    {
        char ty; int x; string s;
        cin >> ty >> x >> s;
        if (ty == '?') {
            if (ma[x].query(s)) cout << "Yes\n";
            else cout << "No\n"; continue;
        }
        if (ty == '+') {
            ma[x].Insert(s);
            continue;
        }
        ma[x].Erase(s);
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
        // cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}
 //https://toph.co/p/spam-me-not
