#include <string.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int N=8;
vector<int> adj[N];
vector<bool>visited;

void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        visited[u]=true;
        cout <<v<<" ";
        for(auto e: adj[v]){
            if(!visited[e]){
                q.push(e);
            }
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
    bfs(0);
    cout<<"\n";

    
    return 0;
}
