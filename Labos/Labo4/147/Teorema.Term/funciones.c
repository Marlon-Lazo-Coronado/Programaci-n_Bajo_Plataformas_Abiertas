#include "./funciones.h"



int Teorema(int x){

int y;
int z;
//printf("Ingrese un numero\n");
	//scanf("%d", &x);
    while(x > 1){
	if(x%2 == 0){
	printf("par\n");
	z = x/2;
	x = z;
	printf("%d", x);
	}
	else{
	printf("impar\n");
	z = ((3*x)+1);
	x = z;
	printf("%d", x);
	}
}

}
