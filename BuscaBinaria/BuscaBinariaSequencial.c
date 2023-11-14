#include <stdio.h>
#include <time.h>


int main()
{
    srand(time(NULL));
    int vet[100],encontrar,cont=0,posicao=-1;
    for(int i=0;i<100;i++){

        vet[i]= rand() % 100;
    }

    printf("\nDigite o numero que quer achar: ");
    scanf("%d",&encontrar);
    for(int i=0;i<100;i++){

        if(encontrar==vet[i]){
            posicao= i;
            // se eu quiser fazer com menos alteracao que 100
            //declaro o i=100;
        }
        cont++;
    }

    if(posicao!=-1){
        printf("O valor foi encontrado na [%d] posicao!", posicao);
        printf("\nFoi feito [%d] vereficacoes", cont);
    }
    else{
        printf("O seu numero nao foi encontrado! ");
    }

 

    return 0;
}
