/*********************************************************
*Programa checa qual o maior número digitado pelo usuário.
**********************************************************/

#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    int maior,n;

    maior = 0;

    printf("Digite vários números e para parar digite 0: ");
    scanf("%d", &n);

    while (n != 0){
        if (n > maior){

            maior = n;
        }
        printf("Digite vários números e para parar digite 0: ");
        scanf("%d", &n);
    }
    printf("\nO maior número digitado foi: %d\n", maior);

    return 0;

}
