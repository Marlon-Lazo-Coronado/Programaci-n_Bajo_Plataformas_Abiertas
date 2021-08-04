#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#include "./funciones.h"

int main(int argc, char** argv){
    double total = Promocion(
        atof(argv[1]),
        atof(argv[2]),
        atof(argv[3]));
    printf( "El precio a pagar es: %lf \n", total );
}
