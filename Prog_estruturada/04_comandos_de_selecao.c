/****************************************************
*Transformando o formato da hora de 24 para 12 horas.
*****************************************************/

#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");

    int hora, min;

    printf("Digite um horário no formato de 24 horas separando com : as horas dos minutos - " );
    scanf("%d:%d", &hora, &min);

    if (hora > 12) {
        hora -= 12;
    }
    else if (hora == 00) {
        hora += 12;
    }
    printf("\nA hora em formato de 12 horas é %.2d:%.2d\n", hora, min);

    return 0;
}
