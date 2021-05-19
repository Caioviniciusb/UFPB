#include <stdio.h>
#include<locale.h>

int main(void){
    setlocale (LC_ALL, "Portuguese");

    char ch;
    int tamanho = 1;

    printf("Digite uma frase: ");

    ch = getchar();  //Leitura de caractere

    while (ch != '\n'){
        if (ch == ' '){
            tamanho++;
            }
        ch = getchar();
        }
        printf("\nA quantidade de palavras é: %d\n", tamanho);

    return 0;
}
