/*****************************************************
*Projeto Final - Introdução a Ciência de Dados (UFPB)
*Aluno - Caio Vinícius Barros de Araújo (20200024082)
*Professor: Yuri Malheiros
******************************************************/

//Corpo das funções

#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/********************************
*Função para printar as matrizes.
*********************************/
void print_matrix(struct matrix a_matrix){

    int p_linha = (a_matrix.offset / a_matrix.stride_rows);
    int p_coluna = (a_matrix.offset - p_linha * a_matrix.stride_rows) / a_matrix.stride_cols;

    printf("\n");
    for (int i=p_linha; i<a_matrix.n_rows + p_linha; i++){
        for (int j=p_coluna; j<a_matrix.n_cols + p_coluna; j++){
            printf("%2d ", a_matrix.data[(i*a_matrix.stride_rows) + (j*a_matrix.stride_cols)]);
        }
        printf("\n");
    }
}

/*****************************************
*Função para criar uma variável da struct.
******************************************/
struct matrix create_matrix(int *data, int n_rows, int n_cols){

    struct matrix a;  //Criando um struct

    int total = n_rows*n_cols;
    a.data = malloc(total * sizeof(int));

    for (int i=0; i<total; i++){
        a.data[i]= data[i];
    }
    a.n_rows = n_rows;
    a.n_cols = n_cols;
    a.stride_rows = n_cols;
    a.stride_cols = 1;
    a.offset = 0;

    return a;
}

/**************************************
*Função para criar uma matriz de zeros.
***************************************/
struct matrix zeros_matrix(int n_rows, int n_cols){

    int total = n_rows * n_cols;
    int *zero_array;
    zero_array = malloc(total * sizeof(int)); //Alocando espaço dinamicamente

    for (int i=0;i<total;i++){
        zero_array[i] = 0;
    }
    struct matrix b = create_matrix(zero_array, n_rows, n_cols);  //Chamando novamente a função create para não repetir código.

    return b;
}

/***************************************************
*Função pra gerar uma matriz com valores aleatórios.
****************************************************/
struct matrix random_matrix (int n_rows, int n_cols, int b, int e){

    int total = n_rows * n_cols;
    int *random_array;
    random_array = malloc(total * sizeof(int));

    srand((unsigned)time(NULL));  //Seed para modificar os números quando rodado o código.

    for (int i=0;i<total;i++){
        random_array[i] = b + (rand() % e);
    }
    struct matrix c = create_matrix(random_array, n_rows, n_cols);

    return c;
}

/****************************************
*Função para criar uma matriz identidade.
*****************************************/
struct matrix i_matrix(int n){

    int div = n+1;   //A posição do 1 sempre pula o número de colunas + 1.
    int total = n*n;
    int *identity_array;
    identity_array = malloc(total * sizeof(int));

    for (int i=0; i<total; i++){

        if((i % div) == 0){
            identity_array[i] = 1;}
        else{
            identity_array[i] = 0;}
    }
    struct matrix d = create_matrix(identity_array, n, n);

    return d;
}

/****************************************
*Função para pegar um elemento escolhido.
*****************************************/
int get_element(struct matrix a_matrix, int ri, int ci){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int inicio = a_matrix.stride_rows * ri;   //Definindo a posição do elemento inicial.

    for (int i=inicio; i<total; i++){
        if (i == (inicio + ci)){
            return a_matrix.data[i];
        }
    }
}

/*************************************************************
*Função para colocar um elemento na matriz na posição desejada.
**************************************************************/
void put_element(struct matrix a_matrix, int ri, int ci, int elem){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int inicio = a_matrix.stride_rows * ri;

    for (int i=inicio; i<total; i++){
        if (i == (inicio + ci)){
            a_matrix.data[i] = elem;
        }
    }
    print_matrix(a_matrix);
}

/***************************************
*Função para criar a matriz transposta.
****************************************/
struct matrix transpose(struct matrix a_matrix){

    struct matrix e;

    e.data = a_matrix.data;
    e.n_rows = a_matrix.n_cols;
    e.n_cols = a_matrix.n_rows;
    e.stride_cols = a_matrix.stride_rows;
    e.stride_rows = a_matrix.stride_cols;
    e.offset = 0;

    return e;
}

/*****************************************
*Função para mudar as dimensões da matriz.
******************************************/
struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int new_shape = new_n_rows * new_n_cols;

    if (total == new_shape){

        a_matrix.n_cols = new_n_cols;
        a_matrix.n_rows = new_n_rows;
        a_matrix.stride_rows = new_n_cols;
    }
    return a_matrix;
}

/***********************************************
*Função para deixar a matriz com apenas 1 linha.
************************************************/
struct matrix flatten(struct matrix a_matrix){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    a_matrix.n_rows = 1;
    a_matrix.n_cols = total;
    a_matrix.stride_rows = total;

    return a_matrix;
}

/***************************************
*Função para realizar o slice da matriz.
****************************************/
struct matrix slice(struct matrix a_matrix, int rs, int re, int cs, int ce){

    struct matrix f;

    f.data = a_matrix.data;
    f.n_rows = re-rs;
    f.n_cols = ce-cs;
    f.stride_cols = a_matrix.stride_cols;
    f.stride_rows = a_matrix.stride_rows;
    f.offset = (rs * f.stride_rows) + (cs * f.stride_cols);

    return f;
}

/***********************************************
*Função para somar todos os elementos da matriz.
************************************************/
int sum(struct matrix a_matrix){

    int sum = 0;
    int total = a_matrix.n_rows * a_matrix.n_cols;

    for (int i=0; i<total; i++){
        sum += a_matrix.data[i];}

    return sum;
}

/*****************************************************
*Função para retornar a média dos elementos da matriz.
******************************************************/
float mean(struct matrix a_matrix){

    int soma = sum(a_matrix);
    int total = a_matrix.n_rows * a_matrix.n_cols;

    float media = soma/total;

    return media;
}

/***********************************************
*Função para retornar o menor elemento da matriz.
************************************************/
int min(struct matrix a_matrix){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int min = a_matrix.data[0];

    for (int i=0; i<total; i++){
        if (a_matrix.data[i] < min){
            min = a_matrix.data[i];
        }
    }
    return min;
}

/************************************************
*Função para retornar o maior elemento da matriz.
*************************************************/
int max(struct matrix a_matrix){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int max = 0;

    for (int i=0; i<total; i++){
        if (a_matrix.data[i] > max){
            max = a_matrix.data[i];
        }
    }
    return max;
}

/******************************************
*Função para somar elementos de 2 matrizes.
*******************************************/
struct matrix add(struct matrix a_matrix, struct matrix b_matrix){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int *new_array;
    new_array = malloc(total * sizeof(int));

    for (int i=0; i<total; i++){
        new_array[i] = a_matrix.data[i] + b_matrix.data[i];
    }
    struct matrix g = create_matrix(new_array, a_matrix.n_rows, a_matrix.n_cols);
    return g;
}

/*********************************************
*Função para subtrair elementos de 2 matrizes.
**********************************************/
struct matrix sub(struct matrix a_matrix, struct matrix b_matrix){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int *new_array;
    new_array = malloc(total * sizeof(int));

    for (int i=0; i<total; i++){
        new_array[i] = a_matrix.data[i] - b_matrix.data[i];
    }
    struct matrix h = create_matrix(new_array, a_matrix.n_rows, a_matrix.n_cols);
    return h;
}

/********************************************
*Função para dividir elementos de 2 matrizes.
*********************************************/
struct matrix division(struct matrix a_matrix, struct matrix b_matrix){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int *new_array;
    new_array = malloc(total * sizeof(int));

    for (int i=0; i<total; i++){
        new_array[i] = a_matrix.data[i] / b_matrix.data[i];
    }
    struct matrix i = create_matrix(new_array, a_matrix.n_rows, a_matrix.n_cols);
    return i;
}

/************************************************
*Função para multiplicar elementos de 2 matrizes.
*************************************************/
struct matrix mul(struct matrix a_matrix, struct matrix b_matrix){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int *new_array;
    new_array = malloc(total * sizeof(int));

    for (int i=0; i<total; i++){
        new_array[i] = a_matrix.data[i] * b_matrix.data[i];
    }
    struct matrix j = create_matrix(new_array, a_matrix.n_rows, a_matrix.n_cols);
    return j;
}

/*************************************************
*Função para realizar a multiplicação de matrizes.
**************************************************/
struct matrix matmul(struct matrix a_matrix, struct matrix b_matrix){

    int cont = 0;
    int total = a_matrix.n_rows * b_matrix.n_cols;
    int *new_array;

    new_array = malloc(total * sizeof(int));

    if (a_matrix.n_cols == b_matrix.n_rows){

        for (int i=0; i < a_matrix.n_rows; i++){
            for (int j=0; j < b_matrix.n_cols; j++){

                for (int k = 0; k < a_matrix.n_cols; k++){
                    new_array[cont] += a_matrix.data[(i*a_matrix.stride_rows) + (k*a_matrix.stride_cols)] * b_matrix.data[(k*b_matrix.stride_rows) + (j*b_matrix.stride_cols)];
                }
                cont++;
            }
        }
    }
    struct matrix k = create_matrix(new_array, a_matrix.n_rows, b_matrix.n_cols);
    return k;
}
