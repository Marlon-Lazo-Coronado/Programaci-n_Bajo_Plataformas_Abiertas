#include "./funciones.h"



int Permu(int n){


int k;
int j = 0;
int i;
int p;
int s;
int w=0;





//scanf("%d\n", &n);
int Permu[n];


for (i = 0; i<= (n-1); i++){
Permu[i] = (i+1); 
//printf("%d", Permu[i]);
  
}


for (k = 0; k < n; k++){
for (i = 0; i < n; i++){

printf("%d", Permu[i]);


    for (j = 0; j< n; j++){

    printf("%d", Permu[j]);
   
 
}


 printf("\n"); 




}


 printf("\n"); 

}



return 0;


}
