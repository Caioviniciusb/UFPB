#include<stdio.h>
#include<locale.h>
int main(void) {

    setlocale(LC_ALL, "Portuguese");
    float a, b, res1;
    int c, d, res2;

    printf("Digite um número de dois dígitos: ");
    scanf("%f", &res1); //Ex: res1 = 35

    res2 = res1;      //35.0 --> 35
    a = res1 / 10;   //3.5
    b = res2 % 10;  //5.0

    c = a;  //3.5 --> 3
    d = b;  //5.0 --> 5
    printf("\n%d%d\n",  d,c);


    return 0;

}
