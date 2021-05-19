/******************************************
*Programa diz qual é o número do dia do ano
*******************************************/

#include <stdio.h>

int dia_do_ano(int dia, int mes, int ano){

    int cont = 0;

    int bissexto(int ano){   //Função para checar se o ano é bissexto.
        if (ano % 400 == 0){
            return 1;}

        else{
            if (ano % 4 == 0 && ano % 100 != 0){
                return 1;}

            else{
                return 0;}
            }}

    if (mes == 1){
        cont == dia;}

    switch (mes){                   //Somando a quantidade de dias que já se passaram em cada mês.
        case 2: cont+= 31; break;
        case 3: cont+= 59; break;
        case 4: cont+= 90; break;
        case 5: cont+= 120; break;
        case 6: cont+= 151; break;
        case 7: cont+= 181; break;
        case 8: cont+= 212; break;
        case 9: cont+= 243; break;
        case 10: cont+= 273; break;
        case 11: cont+= 304; break;
        case 12: cont+= 334; break;
        }

    cont += dia;  //Somando os dias.

    if (bissexto(ano) == 1){ //Checando se o ano é bissexto para somar + 1 dia.
        cont++;}

    return cont;
}

int main (void){

    printf("%d\n", dia_do_ano(31,12,2020));

    return 0;
}
