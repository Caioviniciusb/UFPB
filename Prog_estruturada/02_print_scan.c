/****************
*Soma de fra��es.
*****************/

#include<stdio.h>
#include<locale.h>

int main (void){
    setlocale(LC_ALL, "Portuguese");
    int a,b,c,d, num,den;

    printf("Digite duas fra��es no formato x/y\n");
    scanf("%d/%d%d/%d", &a,&b,&c,&d);

    num = (a*d) + (b*c);
    den = b*d;

    printf("\nA soma das fra��es � %d/%d\n", num, den);

    return 0;

}
