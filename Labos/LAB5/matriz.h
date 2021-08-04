#ifndef MATRIZ_H
#define MATRIZ_H


#include <stdio.h>
#include <stdlib.h>

float** Crea_matriz(int N,int M);
float** Limpiar_Matriz(int N,int M, float** A);
void Borra_matriz(int N,int M,float** Matriz);
float** Sum_Matrices(int N,int M, float** A,float** B);
float** Mult_Matrices(int N1,int M1,int M2, float** A,float** B);
float** Sum_EscalarMatriz(int N,int M, float** A,float x);
float** Mult_EscalarMatriz(int N,int M, float** A,float x);
float** Trasponer_Matriz(int N,int M, float** A); 
void Imprimir_Matriz(int N, int M, float** A);

#endif
