/****************************************************************
*Programa que mostra a maior palavra digitada comparando strings.
*****************************************************************/

#include <stdio.h>
#include <string.h>

int main(void){

    char palavra[40];
    char maior_palavra[40] = {0};

    printf("\n-->Para finalizar digite 'fim'<--\n");

    while (strcmp(palavra, "fim") != 0) {

        printf("\nDigite uma palavra: ");
        scanf("%s", palavra);

        if (strlen(palavra) > strlen(maior_palavra)){
            strcpy(maior_palavra, palavra);
        }
    }

    printf("\nA maior palavra digitada foi: %s\n", maior_palavra);

    return 0;
}
