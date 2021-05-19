//Função para calcular fatorial usando recursão.

#include<stdio.h>

void fat(int n){

    int n_inicial = n;

    for(int i=n-1; i>=1; i--){

        n *= i;
    }
    printf("\nFatorial de %d é: %d\n",n_inicial, n);
}

int main(void){

    fat(5);

    return 0;
}
