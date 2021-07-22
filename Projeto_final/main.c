/*****************************************************
*Projeto Final - Introdução a Ciência de Dados (UFPB)
*Aluno - Caio Vinícius Barros de Araújo (20200024082)
*Professor: Yuri Malheiros
******************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "matrix.h"

int main (void){

    struct matrix matrix1, matrix_zero, matrix_random, matrix_identity, matrix_transpose,
    matrix_add, matrix_sub, matrix_div, matrix_mul, my_matrix, matrix_matmul, matrix2, matrix3;

    int array[6] = {1,2,3,4,5,6};
    int array_2[9] = {1,2,3,4,5,6,7,8,9};
    int array_3[6] = {2,0,1,5,3,2};
    int array_4[6] = {4,3,1,2,0,6};

    matrix1 = create_matrix(array, 3, 2);
    my_matrix = create_matrix(array_2, 3, 3);
    matrix2 = create_matrix(array_3, 2, 3);
    matrix3 = create_matrix(array_4, 3, 2);
    matrix_zero = zeros_matrix(5,5);
    matrix_random = random_matrix(3,2,0,10);
    matrix_identity = i_matrix(5);
    matrix_transpose = transpose(matrix1);
    my_matrix = slice(my_matrix, 0, 2, 1, 3);
    matrix_add = add(matrix1, matrix1);
    matrix_sub = sub(matrix1,matrix1);
    matrix_div = division(matrix1,matrix1);
    matrix_mul = mul(matrix1,matrix1);
    matrix_matmul = matmul(matrix2,matrix3);

    printf("\n***Funções para criação de matrizes***\n");
    printf("\n...Matriz Inicial...");
    print_matrix(matrix1);

    printf("\n...Matriz Zeros...");
    print_matrix(matrix_zero);

    printf("\n...Matriz Aleatória...");
    print_matrix(matrix_random);

    printf("\n...Matriz Identidade...");
    print_matrix(matrix_identity);

    printf("\n\n***Funções para acessar elementos***\n");

    printf("\n...Elemento Escolhido...");
    printf("\n %d\n", get_element(matrix1, 1, 0));

    printf("\n...Mudando Elemento...");
    put_element(matrix1, 0, 0, 0);

    printf("\n\n***Funções para manipulação de dimensões***\n");

    printf("\n...Matriz Transposta...");
    print_matrix(matrix_transpose);

    printf("\n...Mudando Dimensões...");
    matrix1 = reshape(matrix1, 2, 3);
    print_matrix(matrix1);

    printf("\n...Matriz em 1 linha...");
    matrix1 = flatten(matrix1);
    print_matrix(matrix1);

    printf("\n...Slice Matriz...");
    print_matrix(my_matrix);

    printf("\n\n***Funções de agregação***\n");

    printf("\n...Soma dos elementos da matriz...");
    printf("\n %d\n", sum(matrix1));

    printf("\n...Média dos elementos da matriz...");
    printf("\n %f\n", mean(matrix1));

    printf("\n...Menor elemento da matriz...");
    printf("\n %d\n", min(matrix1));

    printf("\n...Maior elemento da matriz...");
    printf("\n %d\n", max(matrix1));

    printf("\n\n***Funções de operações aritméticas***\n");

    printf("\n...Soma de matrizes...");
    print_matrix(matrix_add);

    printf("\n...Subtração de matrizes...");
    print_matrix(matrix_sub);

    printf("\n...Divisão de matrizes...");
    print_matrix(matrix_div);

    printf("\n...Multiplicação de elementos das matrizes...");
    print_matrix(matrix_mul);

    printf("\n...Multiplicação de matrizes...");
    print_matrix(matrix_matmul);

    return 0;
}
