/****************
*Soma de frações.
*****************/

#include<stdio.h>
#include<locale.h>

int main (void){
    setlocale(LC_ALL, "Portuguese");
    int a,b,c,d, num,den;

    printf("Digite duas frações no formato x/y\n");
    scanf("%d/%d%d/%d", &a,&b,&c,&d);

    num = (a*d) + (b*c);
    den = b*d;

    printf("\nA soma das frações é %d/%d\n", num, den);

    return 0;

}
