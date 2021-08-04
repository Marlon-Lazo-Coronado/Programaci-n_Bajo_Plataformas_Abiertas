#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct posiciones{
    int d;
    struct posiciones *siguiente;
 }posicion;


 //  Declaracion de funciones posiciones 

 posicion* crearposicion(int p);
 void eliminarposicion(posicion* p);
 posicion* siguiente(posicion* p);


posicion* crearposicion(int d){

	posicion* nuevaposicion = NULL;  
	nuevaposicion  = (posicion*)malloc(sizeof(posicion)); 

	nuevaposicion->siguiente = NULL;
	nuevaposicion->d = d;

    return nuevaposicion;
}


void eliminarposicion(posicion* p){
	free(p);
}


posicion* siguiente(posicion* p){
	posicion* siguiente = p->siguiente;
	return siguiente;
}

