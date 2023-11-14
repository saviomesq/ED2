#include <stdio.h>

#include <time.h>

#include <stdlib.h>

 

void insertionSort(int arr[], int n) {

    int i, j, key;

    for (i = 1; i < n; i++) {

        key = arr[i];

        j = i - 1;

 

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];

            j = j - 1;

        }

        arr[j + 1] = key;

    }

}

 

int main() {

    srand(time(NULL));

    int vet[10], encontrar, cont = 0, apareceu = 0, posicao[10];

    for (int i = 0; i < 10; i++) {

        vet[i] = rand() % 10;

    }

    int tam = 10; // Tamanho real do array

 

    printf("Array original:\n");

    for (int i = 0; i < 10; i++) {

        printf("%d ", vet[i]);

    }

    printf("\n");

 

    insertionSort(vet, tam);

 

    printf("Array ordenado:\n");

    for (int i = 0; i < 10; i++) {

        printf("%d ", vet[i]);

    }

    printf("\n");

 

    printf("Digite o numero que quer achar: ");

    scanf("%d", &encontrar);

    int min = 0;

    int max = tam - 1;

    int achei = -1;

    int verificacao=0;

 

    while (min <= max) {

        int mid = (min + max) / 2;

        verificacao++;

        if (vet[mid] > encontrar) {

            max = mid - 1;

        } else if (vet[mid] < encontrar) {

            min = mid + 1;

        } else {

            achei = mid;

            break;

        }

    }

 

    if (achei != -1) {

        printf("Achei seu numero na [%d] posicao\n", achei);

        printf("Foi feito [%d] verificacoes", verificacao);

    } else {

        printf("Numero nao encontrado.\n");

    }

 

    return 0;

}
