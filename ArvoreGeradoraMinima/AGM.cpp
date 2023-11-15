#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Aresta {
    int origem, destino, peso;
};

struct Grafo {
    int V, E; // Vértices e arestas
    vector<Aresta> arestas; // Lista de arestas

    Grafo(int v, int e) : V(v), E(e) {}

    // Adiciona uma aresta ao grafo
    void adicionarAresta(int origem, int destino, int peso) {
        Aresta aresta = {origem, destino, peso};
        arestas.push_back(aresta);
    }

    // Função para encontrar o conjunto de um elemento i
    int encontrar(int conjuntos[], int i) {
        if (conjuntos[i] == -1)
            return i;
        return encontrar(conjuntos, conjuntos[i]);
    }

    // Função para unir dois conjuntos em um único conjunto
    void unir(int conjuntos[], int x, int y) {
        int raizX = encontrar(conjuntos, x);
        int raizY = encontrar(conjuntos, y);
        conjuntos[raizX] = raizY;
    }

    // Função principal para encontrar a Árvore Geradora Mínima usando Kruskal
    void kruskal() {
        vector<Aresta> resultado; // Vetor para armazenar as arestas da AGM

        // Ordena as arestas por peso
        sort(arestas.begin(), arestas.end(), [](const Aresta &a, const Aresta &b) {
            return a.peso < b.peso;
        });

        int conjuntos[V]; // Vetor para armazenar os conjuntos
        fill(conjuntos, conjuntos + V, -1);

        for (const auto &aresta : arestas) {
            int raizOrigem = encontrar(conjuntos, aresta.origem);
            int raizDestino = encontrar(conjuntos, aresta.destino);

            // Adiciona a aresta à AGM se não criar um ciclo
            if (raizOrigem != raizDestino) {
                resultado.push_back(aresta);
                unir(conjuntos, raizOrigem, raizDestino);
            }
        }

        // Imprime a Árvore Geradora Mínima
        cout << "Arestas da Árvore Geradora Mínima:\n";
        for (const auto &aresta : resultado) {
            cout << aresta.origem << " -- " << aresta.destino << "  Peso: " << aresta.peso << "\n";
        }
    }
};

int main() {
    // Exemplo de uso
    Grafo grafo(4, 5); // Grafo com 4 vértices e 5 arestas
    grafo.adicionarAresta(0, 1, 10);
    grafo.adicionarAresta(0, 2, 6);
    grafo.adicionarAresta(0, 3, 5);
    grafo.adicionarAresta(1, 3, 15);
    grafo.adicionarAresta(2, 3, 4);

    grafo.kruskal(); // Encontra e imprime a Árvore Geradora Mínima

    return 0;
}
