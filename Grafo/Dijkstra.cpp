#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    
    vector<vector<pair<int,int>>> G(n);

    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>v>>u>>w;
        v--; u--;
        G[v].push_back({u,w});
    }

    priority_queue<pair<int,int>> dj;
    vector<int> dist(n, INT_MAX);

    dist[0]=0;
    dj.push({0,0});

    while((int)dj.size()>0){
        int v = dj.top().second;
        int w = -dj.top().first;

        dj.pop();

        if(w!=dist[v]) continue;

        for(auto edge:G[v]){
            int u=edge.first;
            int cost=edge.second;
            if(dist[u]>dist[v]+cost){
                dist[u]=dist[v]+cost;
                dj.push({-dist[u],u});
            }
        }
    }

    for(int d:dist){
        cout<<d<<" ";
    }
    cout<<"\n";

    return 0;
}
