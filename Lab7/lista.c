#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "posicion.h"


 typedef struct listas{
 	unsigned int items;
     struct posiciones *primero;
  } lista ;



  lista* crearlista(lista* l);
  void eliminarlista(lista* l);
  void vaciar(lista* l);
  void agregarelemento(lista* listaok, int d);
  void eliminarelemento(lista* listaok, int d);
  void imprimirlista(lista* l);
  posicion* buscardato(lista* l, int d);





  int main()
  {
  	
  	 printf("\n ********************Bienvenido**********************\n");
  	 
  	 
	  	  lista* nuevalista = NULL;
	      int num;
	      int option;
	      char temp;


	  
	      while(1) {

	          printf("\n ******************************************\n");
	          printf("*  Operaciones:                          *\n");
	          printf("*    1. Crear Lista                      *\n");
	          printf("*    2. Vaciar                            *\n");
	          printf("*    3. Eliminar Lista                   *\n");
	          printf("*    4. Agregar Elemento                 *\n");
	          printf("*    5. Eliminar Elemento                *\n");
	          printf("*    6. Imprimir Lista                   *\n");
	          printf("*    7. Buscar Dato                      *\n");
	          printf("*    8. Salir                            *\n");
	          printf("******************************************\n");
	          printf("Elija una opcion [1-9] : ");

	          if (scanf("%d", &option) != 1) {
	              printf(" *Error: Entrada invalida . Precione intentar denuevo.\n");
	              scanf("%s", &temp); 
	              continue;
	          }

	          switch (option) {
	              case 1:        

	            	  printf("\nCreada la lista...");

	            	  nuevalista=crearlista(nuevalista);

	            	  printf("\nPresione cualquier tecla para continuar...");

					  getch();
					  break;




	              case 2:   

	            	  vaciar(nuevalista);

	            	  getch();
	            	  break;


	              case 3:  


	                  eliminarlista(nuevalista);


	                  getch();
	                  break;

	              case 4: 


	            	  printf(" Ingrese el numero del Elemento a Ingresar: ");

					  if (scanf("%d", &num) != 1) {
						  printf(" *Error: Entrada invalida, ingrese un numero entero\n");
						  scanf("%s", &temp);    //limpiar el buffer de entrada //
						  continue;
					  }

					  agregarelemento(nuevalista, num);

					  printf("El numero %d se ha ingresado a la lista", num);
					  printf("\nPresione cualquier tecla para continuar...");

					  getch();
					  break;

	              case 5:  

	            	  printf(" Ingrese la entrada a Eliminar : ");
					  if (scanf("%d", &num) != 1) {
						  printf(" *Error: Entrada invalida, ingrese un numero entero\n");
						  scanf("%s", &temp);    
						  continue;
					  }

					  eliminarelemento(nuevalista, num);

					  printf("Numero %d se ha removido de la lista", num);
						printf("\nPresione cualquier tecla para continuar...");
					  getch();
					  break;


	              case 6: 

	            	  imprimirlista(nuevalista);

					  getch();
					  break;

	              case 7:


	            	  printf(" Ingrese el numero del Elemento a Buscar: ");

					  if (scanf("%d", &num) != 1) {
						  printf(" *Error: Entrada invalida, ingrese un numero entero\n");
						  scanf("%s", &temp);     
						  continue;
					  }

	            	  posicion* buscado =  buscardato(nuevalista, num);
					if(buscado==NULL){
									printf("No se encontro el dato\n");
							}else{
								printf("Dato encontrado, este es: %d \n", buscado->d );
							}
					printf("\nPresione cualquier tecla para continuar...");
					  getch();
					  break;

	              case 8: 


					  return(0);
					  break;

	              default:
	                  printf("Opcion invalida. Intentelo de nuevo.");
	                  getch();

	              } 
	      } 



     return 0;
  }

  //**********************************************************************************

  lista* crearlista(lista* l){


  	l  = (lista*)malloc(sizeof(lista)); 
  	l->items = 0;//
  	l->primero = NULL;//

      return l;//
  }

  //**********************************************************************************

  void vaciar(lista* l){


  	posicion* actual = l->primero;

  	   while (actual != NULL)
  	   {
  		   actual->d=0;
  		   actual = siguiente(actual);
  	   }


  	   printf("La lista ha sido vaciada... \n");

  }

  //**********************************************************************************

  void eliminarlista(lista* l){



     posicion* actual = l->primero;
     posicion* siguienteaux;

     while (actual != NULL)
     {
  	   siguienteaux = siguiente(actual);
        eliminarposicion(actual);
         actual = siguienteaux;
     }

     l->primero = NULL;


     printf("La lista ha sido Eliminada... \n");

  }


  //**********************************************************************************

  void imprimirlista(lista* l){




  	if(l->primero==NULL){
  				printf("Lista Vacia... \n");
  		}else{

  				posicion* pos = l->primero;

  				printf("Los %d Elementos de la Lista son: \n", l->items);

  				while(pos != NULL){
  				    printf("---> %d \n", pos->d);
  				    pos = siguiente(pos);
  				}

  		}
  }

  //**********************************************************************************

  posicion* buscardato(lista* l, int d){

  	posicion *actual = l->primero;
  	posicion *retorno = NULL;


  		    while ( actual != NULL) {

  		        if (actual->d == d) {

  		           retorno = actual;
  		        }

  		        actual = siguiente(actual);
  		    }



  	return retorno;
  }

  //**********************************************************************************

  void agregarelemento(lista* l, int d){



  	posicion* nuevaposicion = NULL;
  	nuevaposicion = crearposicion(d);

  	    if(l->primero == NULL){

  	    	l->primero = nuevaposicion;
  	    }
  	    else{

  	    	posicion* proximo  = l->primero;

  	        while(proximo->siguiente != NULL){

  	        	proximo = siguiente(proximo);

  	        }

  	        proximo->siguiente = nuevaposicion;
  	    }



  	int cnt = 0;

  	posicion * actual = l->primero;

  	    while ( actual != NULL) {
  	        cnt++;
  	        actual = siguiente(actual);
  	    }


  	l->items=cnt;

  }

  //**********************************************************************************

  void eliminarelemento(lista* l, int d){


  	posicion* actual = l->primero;

  	    posicion *anterior;

  	    while ( actual != NULL) {

  	        if (actual->d == d) {

  	            if (actual == l->primero) { //si esta de primero en la lista

  	            	l->primero = actual->siguiente;

  	            	eliminarposicion(actual);


  	            } else { //si no esta de primero en la lista

  	                anterior->siguiente = actual->siguiente;

  	                eliminarposicion(actual);
  	            }

  	          l->items = l->items - 1;
  	        }

  	        anterior = actual;
  	        actual = siguiente(actual);
  	    }

  }

