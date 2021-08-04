#include "./funciones.h"
char pocicionf(int x, int y, int n, int m, char** A) {
//(AQUI TAMBIEN SE LE PUEDE ASIGNAR LA POCICION AL QUESO AGREGANDO DOS VARIABLE DE ENTRADA MAS)

////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//AQUI SE DEFINE UNA SEGUNDA FUNCION YA QUE SI NO SE HACE, SE TIENE UN PROBLEMA EN LA LLAMADA RECURSIVA
char pocicion(int x, int y, int n, int m, char** A) {
    int espaciosLibres = 0;
//PRIMERO DEBEMOS ANALIZAR EL VECINDARIO

//PRIMERO ESCRIBIMOS LOS CASOS PARA CUANDO EL RATON ENCUENTRA EL QUESO
    if(x != 0){
if(A[x-1][y]=='Q'){
    
    A[x][y] = 'o';//Dejamos una marca
	A[x-1][y] = 'r';//Nos desplazamos
     Imprimir_Matriz(n,m, A);
	exit(-1);
} 
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(x != n - 1){
if(A[x+1][y]=='Q'){
    
    A[x][y] = 'o';//Dejamos una marca
	A[x+1][y] = 'r';//Nos desplazamos
    Imprimir_Matriz(n,m, A);
	exit(-1);
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(y != 0){
if(A[x][y-1]=='Q'){
    
    A[x][y] = 'o';//Dejamos una marca
	A[x][y-1] = 'r';//Nos desplazamos
     Imprimir_Matriz(n,m, A);
    exit(-1);
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(y != m - 1){
if(A[x][y+1]=='Q'){
    
    A[x][y] = 'o';//Dejamos una marca
	A[x][y+1] = 'r';//nos desplazamos
    Imprimir_Matriz(n,m, A);
	exit(-1);
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//AHORA LOS CASOS EN LOS QUE NO ENCUENTRA EL QUESO
if(x != 0){
if(A[x-1][y]==' '){
    espaciosLibres = 1;
    A[x][y] = 'o';//Dejamos marca
    A[x-1][y] = 'r';//Nos desplazamos
     Imprimir_Matriz(n,m, A);

    pocicion(x-1, y, n,m, A);//Cambiamos de coordenadas
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(x != n -1){
if(A[x+1][y]==' '){
    espaciosLibres = 1;
    A[x][y] = 'o';//Dejamos marca
    A[x+1][y] = 'r';//Nos desplazamos
    
    Imprimir_Matriz(n, m, A);
				
    pocicion(x+1, y, n,m, A);//Cambiamos de coordenadas
                

}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(y != 0){
if(A[x][y-1]==' '){
    espaciosLibres = 1;
    A[x][y] = 'o';//Dejamos una marca
    A[x][y-1] = 'r';//Nos desplazamos
    Imprimir_Matriz(n,m, A);
    pocicion(x, y-1, n, m, A);//Cambiamos de coordenadas
   
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

if(A[x][y+1]==' '){
    
    espaciosLibres = 1;
    A[x][y] = 'o';//Dejamos una marca
    A[x][y+1] = 'r';//Nos desplazamos
    
           Imprimir_Matriz(n, m, A);
    pocicion(x, y+1, n,m, A);//Cambiamos de coordenadas
                
}
if(espaciosLibres == 0){
A[x][y] = 'o';
}
}
return pocicion(x,y, n, m,A);
}
void buscarQueso(int x, int y){

    int N = 8;
    int M = 12;

    char** A = Crea_matriz(N,M);
    
    A = Laberinto(N,M,A);
    Imprimir_Matriz(N,M,A);
    pocicionf(x,y, N, M, A);

    Borra_matriz(N,M,A);
    
}



char** Crea_matriz(int N,int M){
    
    char** Matriz = (char**) malloc(sizeof(char*) * N);

    
    for(int i=0; i < N; i++){
        Matriz[i] = (char*) malloc(sizeof(char) * M);
	}
    
    return Matriz;
}


char** Laberinto(int N,int M,char** A){

    FILE* archivo = fopen ( "laberinto.txt", "r" );
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char a = fgetc(archivo);
            if(a != '\n'){
            A[i][j] = a; 
            } 
            else {
            A[i][j] = fgetc(archivo);
            }
        }
    }
    fclose ( archivo );
    return A;
}


void Imprimir_Matriz(int N, int M, char** A){
    for(int i=0; i < N; i++){
        for(int j=0; j< M; j++){
        printf("%c ", A[i][j]);        
        }
    printf("\n");
	}
    printf("\n\n");
}


void Borra_matriz(int N,int M,char** A){

    for(int i=0; i < N; i++){
        free(A[i]);
	}
    
    free(A);
}
