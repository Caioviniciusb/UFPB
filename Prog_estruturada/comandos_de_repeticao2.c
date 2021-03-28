#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");

    int n;
    float e = 1.0;
    float mult = 1.0;

    printf("Digite um número: ");
    scanf("%d", &n);

    for (int i=1; i<=n; i++){

        mult *= i;
        e += 1/mult;
    }
    printf("\nO valor de e vale: %f\n", e);

    return 0;
}