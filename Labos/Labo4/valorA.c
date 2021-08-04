#include <stdio.h>

float x;
float y;

int main(){
	
	printf("Ingrese un numero\n");
	scanf("%f", &x);
	if(x > 0){
	printf("%f", x);
	}
	
	if(x < 0){
	y = ((-1)*x);
	printf("%f", y);
	}
	
//Termina el programa 1	

int x;
int y;
int z;
int main(){
	printf("Ingrese un numero\n");
	scanf("%d", &x);
	if(x%2 == 0){
	printf("par\n");
	z = x/2;
	printf("%d", z);
	}
	else{
	printf("impar\n");
	y = ((3*x)+1);
	printf("%d", y);
	}





	return 0;
}
