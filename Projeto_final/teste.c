#include <stdio.h>
#include <stdlib.h>

struct matrix create_matrix(int *data, int n_rows, int n_cols);
void print_matrix(struct matrix matrix1);
struct matrix zeros_matrix(int n_rows, int n_cols);
struct matrix random_matrix (int n_rows, int n_cols, int b, int e);
struct matrix i_matrix(int n);
int get_element(struct matrix a_matrix, int ri, int ci);
void put_element(struct matrix a_matrix, int ri, int ci, int elem);
//struct matrix transpose(struct matrix a_matrix);
struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols);
struct matrix flatten(struct matrix a_matrix);
int sum(struct matrix a_matrix);
float mean(struct matrix a_matrix);
int min(struct matrix a_matrix);
int max(struct matrix a_matrix);
struct matrix add(struct matrix a_matrix, struct matrix b_matrix);
struct matrix sub(struct matrix a_matrix, struct matrix b_matrix);
struct matrix division(struct matrix a_matrix, struct matrix b_matrix);
struct matrix mul(struct matrix a_matrix, struct matrix b_matrix);

struct matrix{

    int *data ;
    int n_rows;
    int n_cols;
    int stride_rows;
    int stride_cols;
    int offset;
    };

int main (void){

    struct matrix matrix1, matrix_zero, matrix_random, matrix_identity, matrix_add, matrix_sub, matrix_div, matrix_mul;

    int array[6] = {1,2,3,4,5,6};

    matrix1 = create_matrix(array, 3, 2);
    matrix_zero = zeros_matrix(5,5);
    matrix_random = random_matrix(3,2,0,10);
    matrix_identity = i_matrix(5);
    matrix_add = add(matrix1, matrix1);
    matrix_sub = sub(matrix1,matrix1);
    matrix_div = division(matrix1,matrix1);
    matrix_mul = mul(matrix1,matrix1);

    printf("\n...Matriz Inicial...");
    print_matrix(matrix1);

    printf("\n...Matriz Zeros...");
    print_matrix(matrix_zero);


    printf("\n...Matriz Aleatória...");
    print_matrix(matrix_random);

    printf("\n...Matriz Identidade...");
    print_matrix(matrix_identity);

    printf("\n...Elemento Escolhido...");
    printf("\n%d\n", get_element(matrix1, 1, 0));

    printf("\n...Mudando Elemento...");
    put_element(matrix1, 0, 0, 0);

    printf("\n...Mudando Dimensões...");
    matrix1 = reshape(matrix1, 2, 3);
    print_matrix(matrix1);

   // matrix1 = transpose(matrix1);
    //printf("\n...Matriz Transposta...\n");
    //print_matrix(matrix1);
    //print_matrix(matrix1);

    printf("\n...Matriz em 1 linha...");
    matrix1 = flatten(matrix1);
    print_matrix(matrix1);

    printf("\n...Soma da matriz...");
    printf("\n%d\n", sum(matrix1));

    printf("\n...Média da  matriz...");
    printf("\n%f\n", mean(matrix1));

    printf("\n...Menor elemento da matriz...");
    printf("\n%d\n", min(matrix1));

    printf("\n...Maior elemento da matriz...");
    printf("\n%d\n", max(matrix1));

    printf("\n...Soma de matrizes...");
    print_matrix(matrix_add);

    printf("\n...Subtração de matrizes...");
    print_matrix(matrix_sub);

    printf("\n...Divisão de matrizes...");
    print_matrix(matrix_div);

    printf("\n...Multiplicação de matrizes...");
    print_matrix(matrix_mul);

    return 0;
}

/********************************
*Função para printar as matrizes.
*********************************/
void print_matrix(struct matrix a_matrix){

    int cont = 0;
    int total = a_matrix.n_rows * a_matrix.n_cols;

    for (int i=0; i<total; i++){
        if ((cont % a_matrix.stride_rows) == 0){
                printf("\n");}

        printf("%d ", a_matrix.data[i]);
        cont++;
    }
    printf("\n");
}

/****************************************
*Função para criar uma variável da struct.
*****************************************/
struct matrix create_matrix(int *data, int n_rows, int n_cols){

    struct matrix a;  //Criando um struct

    a.data = data;
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

/**************************************************
*Função pra gerar uma matriz com valores aleatórios.
***************************************************/
struct matrix random_matrix (int n_rows, int n_cols, int b, int e){

    int total = n_rows * n_cols;
    int *random_array;
    random_array = malloc(total * sizeof(int));

    for (int i=0;i<total;i++){
        random_array[i] = b + rand() % e;
    }
    struct matrix c = create_matrix(random_array, n_rows, n_cols);

    return c;
}

/***************************************
*Função para criar uma matriz identidade
****************************************/
struct matrix i_matrix(int n){

    int div = n+1;   //A posiução do 1 sempre pula o número de colunas + 1.
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
    int inicio = a_matrix.stride_rows * ri;      //Definindo a posição do elemento inicial.

    for (int i=inicio; i<total; i++){
        if (i == (inicio + ci)){
            return a_matrix.data[i];
        }
    }
}

/*************************************************************
*Função para colocar um elemento na matriz na posição desejada
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
/*
struct matrix transpose(struct matrix a_matrix){

    int aux;

 //   printf("Cols:%d, Rows:%d, Stride_rows:%d",a_matrix.n_cols, a_matrix.n_rows, a_matrix.stride_rows);

    aux = a_matrix.n_cols;
    a_matrix.n_cols = a_matrix.n_rows;
    a_matrix.n_rows = aux;
    a_matrix.stride_rows = a_matrix.n_cols;

    //printf("\n\nCols:%d, Rows:%d, Stride_rows:%d",a_matrix.n_cols, a_matrix.n_rows, a_matrix.stride_rows);
    return a_matrix;
}
*/

/****************************************
*Função para mudar as dimensões da matriz.
*****************************************/
struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols){

    int quant_elementos = a_matrix.n_rows * a_matrix.n_cols;
    int new_shape = new_n_rows * new_n_cols;

    if (quant_elementos == new_shape){

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

    int quant_elementos = a_matrix.n_rows * a_matrix.n_cols;
    a_matrix.n_rows = 1;
    a_matrix.n_cols = quant_elementos;
    a_matrix.stride_rows = quant_elementos;

    return a_matrix;
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

/***********************************************
*Função para retornar o maior elemento da matriz.
************************************************/
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

/*****************************************
*Função para somar elementos de 2 matrizes.
******************************************/
struct matrix add(struct matrix a_matrix, struct matrix b_matrix){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int *new_array;
    new_array = malloc(total * sizeof(int));

    for (int i=0; i<total; i++){
        new_array[i] = a_matrix.data[i] + b_matrix.data[i];
    }

    struct matrix e = create_matrix(new_array, a_matrix.n_rows, a_matrix.n_cols);
    return e;
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

    struct matrix f = create_matrix(new_array, a_matrix.n_rows, a_matrix.n_cols);
    return f;
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

    struct matrix g = create_matrix(new_array, a_matrix.n_rows, a_matrix.n_cols);
    return g;

}

/********************************************
*Função para multiplicar elementos de 2 matrizes.
*********************************************/
struct matrix mul(struct matrix a_matrix, struct matrix b_matrix){

    int total = a_matrix.n_rows * a_matrix.n_cols;
    int *new_array;
    new_array = malloc(total * sizeof(int));

    for (int i=0; i<total; i++){
        new_array[i] = a_matrix.data[i] * b_matrix.data[i];
    }

    struct matrix h = create_matrix(new_array, a_matrix.n_rows, a_matrix.n_cols);
    return h;

}
