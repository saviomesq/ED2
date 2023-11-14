#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define primo 359
#define quantidade 10

typedef struct no{
    char cidade[64];
    char total[192];
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

void enlDeslocado(Lista tabela[], FILE *arquivo){
    char cidade[64], total[192], ctemp[5];

    int valor=0;
    int temp=0;

    while(fgets(cidade, 64, arquivo) != NULL){
        valor=0;
        for(int i=0; i<strlen(cidade); i++){
            valor+=cidade[i];
        }
        
        while(valor>=primo){
            if(valor>10000)valor-=10000;
            else if(valor>1000)valor-=1000;
            else if(valor>100)valor-=100;
            else if(valor>10)valor-=10;
            else if(valor>1)valor-=1;
        }
        inserirLista(&tabela[valor], cidade);
    }

    mostrar(tabela);
}

void mostrar(Lista tabela[]){
    int valor, cont=0;
    for(int i=0; i<primo; i++){
        no *p;
        p = tabela[i].inicio;
        valor=0;
        while(p != NULL){
            valor++;
            p=p->proximo;
        }
        if(valor>1)cont+=valor-1;
        if(valor>10){
            printf("Posicao %d: 10+ cidades\n", i);
        }else{
            printf("Posicao %d: %d cidades\n", i, valor);
        }
        printf("\n");   
    }
    printf("Houveram %d colisões.", cont);
    system("pause");
}

void metDivisao(Lista tabela[], FILE *arquivo){
    char cidade[64];
    int valor=0;

    while(fgets(cidade, 64, arquivo) != NULL){
        valor=0;
        for(int i=0; i<quantidade; i++){
            valor+=cidade[i];
        }
        inserirLista(&tabela[valor % primo], cidade);
    }

    mostrar(tabela);
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo;
    arquivo = fopen("cidades.txt", "r");
    if(arquivo == NULL){
        printf("Arquivo não encontrado!\n");
        return 1;
    }

    Lista tabelaDiv[primo], tabelaDes[primo];
    for(int i=0; i<primo; i++){
        tabelaDiv[i].inicio = NULL;
        tabelaDes[i].inicio = NULL;
    }

    int opc=0;
    while(opc!=3){
        system("cls");
        printf("================= MENU =================\n");
        printf("1: Metodo da divisao\n");
        printf("2: Enlaçamento deslocado\n");
        printf("3: Sair\n");
        printf("================= MENU =================\n");
        printf("Opcao: ");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                metDivisao(tabelaDiv, arquivo);
                break;
            case 2:
                enlDeslocado(tabelaDes, arquivo);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Digite uma opcao valida!\n");
        }
        
    }

    return 0;
}
  
