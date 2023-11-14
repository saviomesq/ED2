#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define primo 5050

typedef struct no{
    char cidade[64];
    struct no *proximo;
}no;

typedef struct{
    no *inicio;
    int tam;
}Lista;

void inserirLista(Lista *lista, char cidade[]){
    no *novo = (no*)malloc(sizeof(no));
    strcpy(novo->cidade, cidade);

    if(lista->inicio == NULL){
        novo->proximo = NULL;
        lista->inicio = novo;
    }else{
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
}

void main(){

    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo;
    arquivo = fopen("cidades.txt", "r");

    char cidade[64], letra;
    int valor=0;
    int cont=0;
    int flag=0;

    Lista tabela[primo];

    for(int i=0; i<primo; i++){
        tabela[i].inicio = NULL;
    }

    while(fgets(cidade, 64, arquivo) != NULL){
        valor=0;
        for(int i=0; i<3; i++){
            valor+=cidade[i];
        }
        inserirLista(&tabela[valor % primo], cidade);
    }

    for(int i=0; i<primo; i++){
        no *p;
        p = tabela[i].inicio;
        while(p != NULL){
            printf("Posicao %d:\nCidade: %s\n", i, p->cidade);
            p=p->proximo;
        }
        printf("\n\n");
    }
}
