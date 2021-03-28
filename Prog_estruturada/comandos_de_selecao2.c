#include<stdio.h>
#include<locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");

    int n, uni, dez;

    printf("Digite um número de 2 dígitos: ");
    scanf("%d", &n);

    dez = (n / 10) * 10;
    uni = n % 10;

    printf("\nNúmero digitado por extenso: ");


    if (dez >= 20){
        switch (dez){
            case 20: printf("Vinte ");
                break;
            case 30: printf("Trinta ");
                break;
            case 40: printf("Quarenta ");
                break;
            case 50: printf("Cinquenta ");
                break;
            case 60: printf("Sessenta ");
                break;
            case 70: printf("Setenta ");
                break;
            case 80: printf("Oitenta ");
                break;
            case 90: printf("Noventa ");
                break;}

        if (uni != 0){
            switch (uni){
                case 1: printf("e um.\n");
                    break;
                case 2: printf("e dois.\n");
                    break;
                case 3: printf("e três.\n");
                    break;
                case 4: printf("e quatro.\n");
                    break;
                case 5: printf("e cinco.\n");
                    break;
                case 6: printf("e seis.\n");
                    break;
                case 7: printf("e sete.\n");
                    break;
                case 8: printf("e oito.\n");
                    break;
                case 9: printf("e nove.\n");
                    break;
                        }
                    }
                }

    if (0 <= n && n < 20 ) {
        switch (n) {
            case 0: printf("Zero\n");
                break;
            case 1: printf("Um\n");
                break;
            case 2: printf("Dois\n");
                break;
            case 3: printf("Três\n");
                break;
            case 4: printf("Quatro\n");
                break;
            case 5: printf("Cinco\n");
                break;
            case 6: printf("Seis\n");
                break;
            case 7: printf("Sete\n");
                break;
            case 8: printf("Oito\n");
                break;
            case 9: printf("Nove\n");
                break;
            case 10: printf("Dez\n");
                break;
            case 11: printf("Onze\n");
                break;
            case 12: printf("Doze\n");
                break;
            case 13: printf("Treze\n");
                break;
            case 14: printf("Quatorze\n");
                break;
            case 15: printf("Quinze\n");
                break;
            case 16: printf("Dezesseis\n");
                break;
            case 17: printf("Dezessete\n");
                break;
            case 18: printf("Dezoito\n");
                break;
            case 19: printf("Dezenove\n");
                break;
        }
    }
    printf("\n-->Fim do Programa<--\n");
    return 0;

}
