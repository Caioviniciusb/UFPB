/*********************************************************
*Programa checa qual o maior n�mero digitado pelo usu�rio.
**********************************************************/

#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    int maior,n;

    maior = 0;

    printf("Digite v�rios n�meros e para parar digite 0: ");
    scanf("%d", &n);

    while (n != 0){
        if (n > maior){

            maior = n;
        }
        printf("Digite v�rios n�meros e para parar digite 0: ");
        scanf("%d", &n);
    }
    printf("\nO maior n�mero digitado foi: %d\n", maior);

    return 0;

}
