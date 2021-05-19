//Printando elementos de um array por recursão.

#include <stdio.h>

void print_array(int a[], int quant, int i){

    if (i >= quant){
             return;
    }
    else{
        printf("%d ", a[i]);
        print_array(a,quant,i+1);
    }
}

int main(void){

    int a[5] = {1, 2, 3, 4, 5};
    printf("\nElementos do array: ");
    print_array(a, 5, 0);
    printf("\n");

    return 0;

}
