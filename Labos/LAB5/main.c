#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#include "./matriz.h"

int main(int argc, char** argv){

    int filas = 3;
    int columnas = 5;
    float** A = Crea_matriz(filas,columnas);

    A[0][0] = 1.0;
    A[0][2] = 1.0;
    A[0][4] = 1.0;

    A[1][1] = 1.0;
    A[1][3] = 1.0;

    A[2][0] = 1.0;
    A[2][2] = 1.0;
    A[2][4] = 1.0;

   printf("\n\nCrear una matriz\n");
   Imprimir_Matriz(filas,columnas,A);


   Sum_EscalarMatriz(filas,columnas,A,4);
   printf("Sumar una matriz y un escalar\n");
   Imprimir_Matriz(filas,columnas,A);


   Mult_EscalarMatriz(filas,columnas,A,2); 
   printf("Multiplicar una matriz y un escalar\n");
   Imprimir_Matriz(filas,columnas,A);


   float** B = Trasponer_Matriz(filas,columnas,A); 

   printf("Trasponer una matriz\n");
   Imprimir_Matriz(columnas,filas,B);



    float** C = Crea_matriz(filas,columnas);
    C[0][0] = 2.0;
    C[0][2] = 2.0;
    C[0][4] = 2.0;

    C[1][1] = 2.0;
    C[1][3] = 2.0;

    C[2][0] = 2.0;
    C[2][2] = 2.0;
    C[2][4] = 2.0;

    
    printf("Suma de matrices\n");
    printf("Matriz C:\n");
    Imprimir_Matriz(filas,columnas,C);
    printf("Matriz A:\n");
    Imprimir_Matriz(filas,columnas,A);
    printf("Matriz A+C:\n");
    float** D = Sum_Matrices(filas,columnas,A,C); 
    Imprimir_Matriz(filas,columnas,D);

    A = Limpiar_Matriz(filas,columnas,A); 
    printf("Limpiar una matriz\n");
    Imprimir_Matriz(filas,columnas,A);


    printf("Multiplicación de matrices\n");
    float** E = Crea_matriz(2,2); 
    float** F = Crea_matriz(2,2);    

    E[0][0] = 1.0;
    E[0][1] = 2.0;
    E[1][0] = 3.0;
    E[1][1] = 4.0;

    F[0][0] = 3.0;
    F[0][1] = 1.0;
    F[1][0] = 4.0;
    F[1][1] = 2.0;

    printf("Matriz D:\n");
    Imprimir_Matriz(2,2,E);
    printf("Matriz E:\n");
    Imprimir_Matriz(2,2,F);
    printf("Matriz D*E:\n");
    float** G = Mult_Matrices(2,2,2,E,F); 
    Imprimir_Matriz(2,2,G);

   Borra_matriz(filas,columnas,A);
   Borra_matriz(columnas,filas,B);
   Borra_matriz(filas,columnas,C);
   Borra_matriz(filas,columnas,D);
   Borra_matriz(2,2,E);
   Borra_matriz(2,2,F);
   Borra_matriz(2,2,G);
}
