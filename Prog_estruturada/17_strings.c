/**********************************************************************************
*Programa que printa de forma reversa os argumentos passados no prompt de comando.
***********************************************************************************/

#include <stdio.h>

int main (int argc, char *argv[]){

    printf("\n");
    for (int i=argc; i>0; i--){

    printf("%s ", argv[i]);
    }

    return 0;
}
