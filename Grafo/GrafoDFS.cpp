#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

const int N=8;
vector<int> adj[N];
vector<bool>visited;
vector<vector<int>> vetorDeVetor;


void dfs(int u){
visited[u]= true;
cout<<u<<' ';
for(auto v: vetorDeVetor[u]){
    if(!visited[v]){
        dfs(v);
    }
}   
}

int main(){

    visited.assign(N,false);
    int vertices, arestas, x, y;
    cout<<"Digite o numero de vertices que tem: "<<endl;
    cin>>vertices;
    for(int i=0;i<vertices;i++){
        vector<int> salve;
        vetorDeVetor.push_back(salve);
    }

    cout<<"Digite o tanto de arestas que tem: "<<endl;
    cin>>arestas;
    cout<<"Digite as ligacoes: "<<endl;
    for(int i=0; i<arestas;i++){
        cin>>x>>y;
        vetorDeVetor[x].push_back(y);
        vetorDeVetor[y].push_back(x);
    }

    cout<<"Busca em profundidade: "<<endl;
    dfs(0);

    cout<<"Quantidade de caminho: "<<arestas<<endl;
    cout<<"Quantidade de vertices "<<vertices<<endl;
    
    for (int i = 0; i < vertices; i++) {
        cout << "Vertices ligados a " << i << ": ";
        for (int j = 0; j < vetorDeVetor[i].size(); j++) {
            cout << vetorDeVetor[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
