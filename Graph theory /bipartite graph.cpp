#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb push_back

#define en "\n"
#define dbg cout<<"rony\n";

#define MAXN 2010

vector<int>g[MAXN];
int vis[MAXN];
int col[MAXN];

bool dfs(int nd,int c)
{
    vis[nd] = 1;
    col[nd] = c;

    bool ok = true;
    for(auto i:g[nd])
    {
        if(vis[i] == 1){
            if(col[nd] == col[i]) return false;
            continue;
        }
        ok &= dfs(i, c^1);
    }
    return ok;
}

void solve()
{
  int n,m;
   cin >> n >> m;

   for(int i = 0;i < m;i++){
    int x,y;
    cin >> x >> y;
    g[x].pb(y);
    g[y].pb(x);
   }

   bool ok = dfs(1,0);

   if(!ok) cout<<"Cycle Found!\n";
   else cout<<"No Cycle found!\n";
}
int main()
{
    IOS;
   int t;
   t = 1;

    while ( t-- )
    {
        solve();
    }
    return 0;
}
