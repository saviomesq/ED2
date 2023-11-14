#include <stdio.h>
#include <stdlib.h>

int BuscaBinaria(int v[], int inicio, int fim, int valor) {
    int meio = (inicio + fim) / 2;
    if (v[meio] == valor) return meio;
    if (fim == inicio) return -1;
    if (v[meio] > valor) return BuscaBinaria(v, inicio, meio - 1, valor);
    return BuscaBinaria(v, inicio + 1, meio, valor);
}

int main() {
    int tam, valor;
    printf("Qual o tamanho do vetor: ");
    scanf("%d", &tam);
    int v[tam], i;
    printf("Informe os valores do vetor:\n");
    for (i = 0; i < tam; i++) {
        scanf("%d", &v[i]);
    }
    printf("Informe o numero a ser buscado: ");
    scanf("%d", &valor);
    int k = BuscaBinaria(v, 0, tam - 1, valor);
    printf("%d", k);
}
