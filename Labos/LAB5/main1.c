{\rtf1\ansi\ansicpg1252\deff0\deflang1033{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\sa200\sl276\slmult1\lang9\f0\fs22 #include <stdio.h>\par
#include <stdlib.h>\par
#include <float.h>\par
#include <math.h>\par
#include "./funciones.h"\par
\par
int main(int argc, char** argv)\{\par
\par
\par
printf("Seleccione la opreracion a realizar:\\n(4)Sumar matriz A y B\\n(7)Multiplicar matriz por escalar\\n(8)Matriz Transpuesta\\n");\par
\par
int op4=4, op7=7, op8=8, res;\par
\par
scanf("%i", &res);\par
\par
if(res == op4)\{ \par
\par
\par
int n;\par
int m;\par
\par
printf("digiteel numero de filas de A\\n ");\par
scanf("%d", &n);\par
\par
printf("digiteel numero de columnas de A\\n");\par
scanf("%d", &m);\par
\par
sumaAB(n , m);\par
\}\par
\par
\par
if(res==op7)\{\par
int row;\par
int col;\par
\par
printf("Construya la matriz A\\n");\par
printf("Filas:\\n");\par
scanf("%i", &row);\par
   \par
printf("Columnas:\\n");\par
scanf("%i", &col);\par
mulAxb(row, col);\par
\}\par
\par
\par
if(res==op8)\{\par
\par
int n, m, col;\par
\par
printf("digiteel numero de filas de A\\n ");\par
scanf("%d", &n);\par
\par
printf("digiteel numero de columnas de A\\n");\par
scanf("%d", &m);\par
\par
transpuesta(n, m);\par
\}\par
\par
return 0;\par
\}\par
}
 