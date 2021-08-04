#include "./funciones.h"

double Promocion(double Peli1, double Peli2, double Peli3){
	double total;
	if (Peli3 <= Peli1 &&  Peli3 <= Peli2){
	total = Peli1 + Peli2; 
	} 
	if (Peli2 <= Peli1 &&  Peli2 <= Peli3){
	total = Peli1 + Peli3;
	} 
	if (Peli1 <= Peli3 &&  Peli1 <= Peli2){
	total = Peli2 + Peli3;
    } 
	return total;
}
