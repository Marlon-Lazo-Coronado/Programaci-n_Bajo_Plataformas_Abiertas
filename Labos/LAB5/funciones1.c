{\rtf1\ansi\ansicpg1252\deff0\deflang1033{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\sa200\sl276\slmult1\lang9\f0\fs22 #include "./funciones.h"\par
\par
int sumaAB(int n, int m)\{\par
\par
   int **A;\par
   int **B;\par
   int **C;\par
//Asignamos la memoria a las filas y columnas\par
\par
A = (int**)malloc(sizeof(int*)*n);//Asinamos taman_o al vector con malloc\par
B = (int**)malloc(sizeof(int*)*n);\par
C = (int**)malloc(sizeof(int*)*n);\par
    \par
//Creamos las columnas \par
\par
for (int i=0; i<n; i++)\{\par
    \par
    A[i] = (int*)malloc(sizeof(int)*m);\par
\}\par
\par
for (int i=0; i<n; i++)\{\par
    \par
    B[i] = (int*)malloc(sizeof(int)*m);\par
\}\par
for (int i=0; i<n; i++)\{\par
    \par
    C[i] = (int*)malloc(sizeof(int)*m);\par
\}\par
    \par
printf("Ingrese los elementos de A\\n");\par
//Ingrezamos valores a las Matriz\par
\par
for (int i=0; i<n; i++)\{\par
    \par
    for (int j=0; j<m; j++)\{\par
        \par
        scanf("%d", &A[i][j]);\par
    \}\par
    \par
\}\par
\par
for (int i=0; i<n; i++)\{\par
    \par
    for (int j=0; j<m; j++)\{\par
        \par
        printf("%i ", A[i][j]);\par
    \}\par
    \par
    printf("\\n");\par
\}    \par
\par
printf("La dimencion de la matriz B es igual a la de A\\n");  \par
printf("Ingrese los elementos de B\\n");\par
//Ingrezamos valores a las Matriz\par
\par
for (int i=0; i<n; i++)\{\par
    \par
    for (int j=0; j<m; j++)\{\par
        \par
        scanf("%d", &B[i][j]);\par
    \}\par
\}\par
\par
for (int i=0; i<n; i++)\{\par
    \par
    for (int j=0; j<m; j++)\{\par
        \par
        printf("%i ", B[i][j]);\par
    \}\par
    \par
    printf("\\n");\par
\}    \par
   \par
\par
int suma;\par
printf("La matriz C es:\\n");\par
//Ingrezamos valores a las Matriz\par
\par
for (int i=0; i<n; i++)\{\par
    \par
    for (int j=0; j<m; j++)\{\par
        \par
    C[i][j]= A[i][j]+B[i][j];\par
        printf("%i ", C[i][j]);\par
    \}\par
    printf("\\n");\par
\}\par
    \par
\}\par
\par
int mulAxb(int row, int col)\{\par
\par
   int *arr = (int *)malloc(row * col * sizeof(int)); \par
   \par
   int i, j, k;\par
   \par
   printf("Ingresar los elementos de la matriz A:\\n");\par
   for (i = 0; i < row; i++)\par
      for (j = 0; j < col; j++)\par
         scanf("%i", &*(arr + i*col + j));\par
         \par
   printf("Los elementos de la matriz A son:\\n");\par
   for (i = 0; i < row; i++) \{\par
      for (j = 0; j < col; j++) \{\par
         printf("%d ", *(arr + i*col + j)); \par
      \}\par
      printf("\\n");\par
   \}\par
\tab  \par
    int p;\par
  printf("Ingrese el escalar\\n");\par
  scanf("%i",&p);\par
\tab  \par
   printf("La multiplicacion del escalar y la matriz es:\\n");\par
   for (i = 0; i < row; i++) \{\par
      for (j = 0; j < col; j++) \{\par
         printf("%d ", *(arr + i*col + j)*p); \par
      \}\par
      printf("\\n");\par
   \}\tab\par
\tab\par
\tab free(arr);\par
   \par
\}\par
\par
\par
int transpuesta(int n, int m)\{\par
\par
int **A;\par
\par
//Asignamos la memoria a las filas y columnas\par
\par
A = (int**)malloc(sizeof(int*)*n);//Asinamos taman_o al vector con malloc\par
\par
   \par
    \par
//Creamos las columnas \par
\par
for (int i=0; i<n; i++)\{\par
    \par
    A[i] = (int*)malloc(sizeof(int)*m);\par
\}\par
    \par
printf("Ingrese los elementos\\n");\par
//Ingrezamos valores a las Matriz\par
\par
for (int i=0; i<n; i++)\{\par
    \par
    for (int j=0; j<m; j++)\{\par
        \par
        scanf("%d", &A[i][j]);\par
    \}\par
    \par
\}\par
\par
for (int i=0; i<n; i++)\{\par
    \par
    for (int j=0; j<m; j++)\{\par
        \par
        printf("%i\\t", A[i][j]);\par
    \}\par
    \par
    printf("\\n");\par
\}    \par
    \par
  for (int i=0; i<m; i++)\{\par
    \par
    for (int j=0; j<n; j++)\{\par
        \par
        printf("%i\\t", A[j][i]);\par
    \}\par
    \par
    printf("\\n");\par
\}    \par
\tab\par
\}\par
}
 