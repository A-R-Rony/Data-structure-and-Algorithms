#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define inf 1e9

int n,m;
vector<pair<int,int>>grp[MAXN];
int vis[MAXN];
int dist[MAXN];

void dijkstra(int node)
{
    set<pair<int,int>>sp;

    for(int i = 1; i <= n;i++) dist[i] = inf;


    sp.insert({0,1});
    dist[1] = 0;
    vis[1] = 1;

    while(!sp.empty())
    {
        int u = sp.begin()->second;
        sp.erase(sp.begin());

        for(auto i: grp[u])
        {


           int cur_dist = dist[i.first];

           int compare_dist = dist[u] + i.second;

           if(cur_dist > compare_dist)
           {

            sp.erase({dist[i.first],i.first});
             dist[i.first] = compare_dist;
             
             sp.insert({dist[i.first],i.first});
           }
        }
    }
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i<= m;i++){
        int u,v,cost;

        cin >> u >> v >> cost;

        grp[u].push_back({v,cost});
    }

    dijkstra(1);

    if(dist[n] == inf) cout<<-1<<endl;
    else cout<<dist[n]<<endl;

}
