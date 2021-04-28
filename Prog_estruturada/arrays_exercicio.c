/*Programa para checar se 2 palavras digitadas s�o ou n�o anagramas.*/

#include <stdio.h>
#include <locale.h>

int main (void){
    setlocale(LC_ALL, "Portuguese");

    char ch1;
    int flag = 1;
    int p1_cont[26] = {0};     /*Criamos 2 arrays do tamanho das letras do alfabeto para contar as apari��es das letras e depois comparar.*/
    int p2_cont[26] = {0};

    printf("\nDigite uma palavra: ");

    ch1 = getchar();
    while(ch1 != '\n'){
        p1_cont[ch1-97]++;
        ch1 = getchar();
    }

    printf("Digite outra palavra: ");

    ch1 = getchar();
    while(ch1 != '\n'){
        p2_cont[ch1-97]++;
        ch1 = getchar();
    }

    for(int i=0; i<26; i++){
        if(p1_cont[i] != p2_cont[i]){
            flag = 0;                    /*Flag para ajudar a sinalizar se � anagrama ou n�o*/
            break;
        }
    }
    if (flag == 0)
        printf("\nN�o � um anagrama.\n");
    else
        printf("\n� um anagrama.\n");

    return 0;
}
