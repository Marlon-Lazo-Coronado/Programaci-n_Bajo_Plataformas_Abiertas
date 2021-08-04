#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <stdio.h>
#include <stdlib.h>
char pocicionf(int x, int y,int n, int m, char** A);
void buscarQueso( );
char** Crea_matriz(int N,int M);
void Imprimir_Matriz(int N, int M, char** A);
void Borra_matriz(int N,int M,char** A);
char** Laberinto(int N,int M,char** A);
#endif
