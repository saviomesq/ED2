#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

const int N=8;
vector<int> adj[N];
vector<bool>visited;


void dfs(int u){
visited[u]= true;
cout<<u<<' ';
for(auto v: adj[u]){
    if(!visited[v]){
        dfs(v);
    }
}   
}

int main(){

    visited.assign(N,false);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(6);
    adj[2].push_back(5);
    adj[5].push_back(7);
    cout<<"\n";

    dfs(0);
    return 0;
}
