/*******************************************************
*Função maior e menor valor de um array usando ponteiros.
********************************************************/

#include <stdio.h>

void max_min();

int main (void){

    int maior, menor;
    int a[5] = {2,4,6,8,10};

    max_min(a, 5, &maior, &menor);

    return 0;
}

void max_min (int a[], int a_v, int *maior, int *menor){

    *maior = 0;

    for (int i=0; i<a_v; i++){

        if (a[i] > *maior){
            *maior = a[i];
        }
    }
    *menor = *maior;

    for (int i=0; i<a_v; i++){

        if (a[i] < *menor){
            *menor = a[i];
        }
    }
    printf("\nMaior valor do array: %d\nMenor valor do array: %d\n", *maior, *menor);
}
