#include "./matriz.h"


float** Crea_matriz(int N,int M){
    
    float** Matriz = (float**) malloc(sizeof(float*) * N);

    for(int i=0; i < N; i++){
        Matriz[i] = (float*) malloc(sizeof(float) * M);
	}
    
    return Matriz;
}


float** Limpiar_Matriz(int N,int M, float** A){
    
    for(int i=0; i < N; i++){
        for(int j=0; j< M; j++){
        A[i][j] = 0 ;        
        }
	}

    return A;
}


void Borra_matriz(int N,int M,float** Matriz){

    for(int i=0; i < N; i++){
        free(Matriz[i]);
	}
    
    free(Matriz);

}


float** Sum_Matrices(int N,int M, float** A,float** B){

    float** C = Crea_matriz(N,M);
    
    for(int i=0; i < N; i++){
        for(int j=0; j< M; j++){
        C[i][j] = A[i][j] + B[i][j] ;        
        }
	}

    return C;
}


float** Mult_Matrices(int N1,int M1,int M2, float** A,float** B){

    float** C = Crea_matriz(N1,M2);
    
    for(int i=0; i < N1; i++){
        for(int j=0; j< M2; j++){
		for(int k=0; k< M1; k++){
        	C[i][j] += A[i][k] * B[k][j] ;   
		}     
        }
    }

    return C;
}


float** Sum_EscalarMatriz(int N,int M, float** A,float x){
    
    for(int i=0; i < N; i++){
        for(int j=0; j< M; j++){
        A[i][j] = A[i][j] + x ;        
        }
	}

    return A;
}


float** Mult_EscalarMatriz(int N,int M, float** A,float x){
    
    for(int i=0; i < N; i++){
        for(int j=0; j< M; j++){
        A[i][j] = A[i][j] * x ;        
        }
	}

    return A;
}


float** Trasponer_Matriz(int N,int M, float** A){
    
    float** B = Crea_matriz(M,N);

    for(int i=0; i < M; i++){
        for(int j=0; j< N; j++){
        B[i][j] = A[j][i];  
        }
	}

    return B;
}


void Imprimir_Matriz(int N, int M, float** A){
    for(int i=0; i < N; i++){
        for(int j=0; j< M; j++){
        printf("%lf ", A[i][j]);        
        }
    printf("\n");
	}
    printf("\n\n");
}
