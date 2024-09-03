#include<bits/stdc++.h>
using namespace std;

#define N 100
vector<int>g[N], rev_g[N];
int vis[N];
int n,m;

vector<int>order,component;

void dfs(int nd)
{
    vis[nd] = 1;
    for(auto i:g[nd]){
        if(vis[i] == 1) continue;
        dfs(i);
    }
    order.push_back(nd);
}

void dfs2(int nd)
{
    vis[nd] = 1;
    component.push_back(nd);

    for(auto i:rev_g[nd]){
        if(vis[i] == 1) continue;
        dfs2(i);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        rev_g[y].push_back(x);
    }

    for(int i = 1;i <= n;i++)
    {
        if(vis[i] == 1) continue;
        dfs(i);
    }

   // for(auto i:order) cout<<i<<" ";cout<<endl;
   reverse(order.begin(),order.end());

   for(int i = 1;i <= n;i++) vis[i] = 0;

   for(auto i:order)
   {
       if(vis[i] == 1) continue;
       component.clear();
       dfs2(i);
       for(auto j:component) cout<<j<<" ";cout<<endl;
   }
}
