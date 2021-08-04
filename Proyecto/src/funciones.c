#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <stdbool.h>

#include "./funciones.h"

// Convierte un número entero en texto 
char * itoa(int i) {
  char * res = malloc(8*sizeof(int));
  sprintf(res, "%d", i);
  return res;
}

// Genera un pato aleatorio 
sfSprite* patoAleatorio(sfTexture* tP1,sfTexture* tP2, sfTexture* tP3){
	
  int numero = rand() % 101;
  sfSprite* pato= sfSprite_create();
  
  // 70 % de probabilidad de que el pato sea azul
 	if ( numero < 70)
	{sfSprite_setTexture(pato, tP1, sfTrue);}

  // 20 % de probabilidad de que el pato sea negro	
	else if ( 70<numero  &&  numero< 90)
	{sfSprite_setTexture(pato, tP2, sfTrue);}

	// 10 % de probabilidad de que el pato sea rojo
	else
	{sfSprite_setTexture(pato, tP3, sfTrue);}
	return pato;
}


// Genera la puntuación 
int score(sfSprite* pato, sfTexture* tPM1,sfTexture* tPM2, sfTexture* tPM3, bool p1, int nivel){
int score;

sfTexture*  texture = sfSprite_getTexture(pato);

if(p1){
	if(texture == tPM1  && (nivel ==1 |  nivel ==2 ) ){
	score	= 500;
	}
	else if(texture == tPM2 && (nivel ==1 |  nivel ==2 ) ){
	score	= 1000;
	}
	else if(texture == tPM3 && (nivel ==1 |  nivel ==2 ) ){
	score	= 1500;
	}
	else if(texture == tPM1  && (nivel ==3 |  nivel ==4 ) ){
	score	= 800;
	}
	else if(texture == tPM2 && (nivel ==3 |  nivel ==4 ) ){
	score	= 1500;
	}
	else if(texture == tPM3 && (nivel ==3 |  nivel ==4 ) ){
	score	= 2400;
	}
	else if(texture == tPM1  && (nivel == 5) ){
	score	= 1000;
	}
	else if(texture == tPM2 && (nivel == 5) ){
	score	= 2000;
	}
	else if(texture == tPM3 && (nivel == 5) ){
	score	= 3000;
}}

else{
	score = 0;
}	
return score;
}

// Aciertos necesarios para pasar al siguiente nivel 
int aciertosN(int nivel){
int N;
if(nivel ==1){
N = 6;}	

else if(nivel ==2){
N = 7;}	

else if(nivel ==3){
N = 8;}	

else if(nivel ==4){
N = 9;}	

else{
N=10;
}
 
return N;
  }
  
 int bonus(nivel){
	 int N;
if(nivel ==1 |  nivel ==2 ){
N = 10000;}	

else if(nivel == 3 |  nivel == 4 ){
N = 15000;}	

else{
N = 20000;}	

return N;
 }

// Creacion del pato muerto
sfSprite* patomuerto(sfSprite* pato, sfTexture* tPM1,sfTexture* tPM2,sfTexture* tPM3, sfTexture* tP1,sfTexture* tP2,sfTexture* tP3){
sfTexture*  texture = sfSprite_getTexture(pato);
if(texture == tP1 ){
sfSprite_setTexture(pato, tPM1, sfTrue);
}
else if(texture == tP2){
sfSprite_setTexture(pato, tPM2, sfTrue);
}	
else if(texture == tP3) {
sfSprite_setTexture(pato, tPM3, sfTrue);
}
return pato;
}


// Opción de juego A : Un pato por turno
void GameA(sfRenderWindow * window , sfSprite* bg , sfSprite* Mira , sfMusic* tiro ){
			sfEvent event;
			// Variables importantes
			int total= 0;
			bool sigNivel=true;
			 sfMusic* hit = sfMusic_createFromFile("res/hit.ogg");
			 sfMusic* music = sfMusic_createFromFile("res/music.ogg");
			 
			 //Imagenes de los patos 
			sfTexture* tP1 = sfTexture_createFromFile("res/pato1.png", NULL);
			sfTexture* tP2 = sfTexture_createFromFile("res/pato2.png", NULL);
			sfTexture* tP3 = sfTexture_createFromFile("res/pato3.png", NULL);
			
			sfTexture* tPM1 = sfTexture_createFromFile("res/patoM1.png", NULL);
			sfTexture* tPM2 = sfTexture_createFromFile("res/patoM2.png", NULL);
			sfTexture* tPM3 = sfTexture_createFromFile("res/patoM3.png", NULL);			

		
		for( int Nivel = 1; Nivel < 6; Nivel++){
			if(sigNivel){
			int aciertos = 0;
			sfMusic_play(music);	
			// Tiempo de espera(2 segundos)
			// Se indica el nivel en el que se encuentra
			time_t  timeT = time(NULL);
			while( (time(NULL) - timeT) < 2){	
				if(sfRenderWindow_pollEvent(window, &event)){
				if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
				}
				}
				
			//Se crea el texto "Level x"
			sfFont *style = sfFont_createFromFile("res/pd.ttf");
			sfText * textLevel = sfText_create();
			sfText_setFont(textLevel, style);
			
			char *  textN = itoa ( Nivel);
	
			sfText_setString(textLevel, textN);
			
			free(textN);
			
			sfText_setCharacterSize(textLevel, 100);
			sfVector2f  vL;
			vL= sfText_getPosition(textLevel);
			vL.x=vL.x+630; vL.y=vL.y+150;
			sfText_setPosition(textLevel, vL);
			
			sfText * text0L = sfText_create();
			sfText_setFont(text0L, style);
			sfText_setString(text0L, "Level");
			sfText_setCharacterSize(text0L, 100);
			sfVector2f  v0L;
			v0L= sfText_getPosition(text0L);
			v0L.x=v0L.x+350; v0L.y=v0L.y+150;
			sfText_setPosition(text0L, v0L);
			
			//Se carga la mira 
			sfVector2f posMira;		
			posMira.x = sfMouse_getPosition(window).x;
			posMira.y = sfMouse_getPosition(window).y;
			sfSprite_setPosition(Mira, posMira);
						
			//Se imprime la imagen
			sfRenderWindow_clear(window, sfBlack);
			sfRenderWindow_drawSprite(window, bg, NULL);
			sfRenderWindow_drawText(window, textLevel, NULL);
			sfRenderWindow_drawText(window, text0L, NULL);
			sfRenderWindow_drawSprite(window, Mira, NULL);
			sfRenderWindow_display(window);
			}			
			
			//Se empiezan los Rounds
			for(int i = 0; i < 10; i++){
				
			// Se carga el color del pato aleatoriamente	
			sfSprite* pato = patoAleatorio(tP1,tP2, tP3);

			//variables para el pato muerto
			bool p1=false;
			
			// Tiempo de espera (2 segundos)
			time_t  time1 = time(NULL);
			while( (time(NULL) - time1 ) < 2){	
				if(sfRenderWindow_pollEvent(window, &event)){
				if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
				}
				}
				
			//Se crea el texto "Round x"
			sfFont *style = sfFont_createFromFile("res/pd.ttf");
			sfText * text4 = sfText_create();
			sfText_setFont(text4, style);
			
			char *  textRound = itoa ( i + 1);
	
			sfText_setString(text4, textRound);
			
			free(textRound);
			
			sfText_setCharacterSize(text4, 100);
			sfVector2f  v4;
			v4= sfText_getPosition(text4);
			v4.x=v4.x+630; v4.y=v4.y+150;
			sfText_setPosition(text4, v4);
			
			sfText * text5 = sfText_create();
			sfText_setFont(text5, style);
			sfText_setString(text5, "Round");
			sfText_setCharacterSize(text5, 100);
			sfVector2f  v5;
			v5= sfText_getPosition(text5);
			v5.x=v5.x+350; v5.y=v5.y+150;
			sfText_setPosition(text5, v5);
			
			//Se carga la mira 
			sfVector2f posMira;		
			posMira.x = sfMouse_getPosition(window).x;
			posMira.y = sfMouse_getPosition(window).y;
			sfSprite_setPosition(Mira, posMira);
						
			//Se imprime la imagen
			sfRenderWindow_clear(window, sfBlack);
			sfRenderWindow_drawSprite(window, bg, NULL);
			sfRenderWindow_drawText(window, text4, NULL);
			sfRenderWindow_drawText(window, text5, NULL);
			sfRenderWindow_drawSprite(window, Mira, NULL);
			sfRenderWindow_display(window);
			}			
			
			//Se crea el texto "Score: x"
			sfFont *style = sfFont_createFromFile("res/pd.ttf");
			sfText * text6 = sfText_create();
			sfText_setFont(text6, style);
			
			char *  textScore = itoa (total);
	
			sfText_setString(text6, textScore);
			
			free(textScore);
			
			sfText_setCharacterSize(text6, 20);
			sfVector2f  v6;
			v6= sfText_getPosition(text6);
			v6.x=v6.x+870; v6.y=v6.y +550;
			sfText_setPosition(text6, v6);
			
			sfText * text7 = sfText_create();
			sfText_setFont(text7, style);
			sfText_setString(text7, "Score: ");
			sfText_setCharacterSize(text7, 20);
			sfVector2f  v7;
			v7= sfText_getPosition(text7);
			v7.x=v7.x+800; v7.y=v7.y+550;
			sfText_setPosition(text7, v7);	
			
			//Se crea el texto "Hits: x"
			sfText * text8 = sfText_create();
			sfText_setFont(text8, style);
			
			char *  textHits = itoa (aciertos);
	
			sfText_setString(text8, textHits);
			
			free(textHits);
			
			sfText_setCharacterSize(text8, 20);
			sfVector2f  v8;
			v8= sfText_getPosition(text8);
			v8.x=v8.x+870; v8.y=v8.y +520;
			sfText_setPosition(text8, v8);
			
			sfText * text9 = sfText_create();
			sfText_setFont(text9, style);
			sfText_setString(text9, "Hits: ");
			sfText_setCharacterSize(text9, 20);
			sfVector2f  v9;
			v9= sfText_getPosition(text9);
			v9.x=v9.x+800; v9.y=v9.y+520;
			sfText_setPosition(text9, v9);		
			
			// Se mueve el pato (5 segundos)
			time1 = time(NULL);
			while( (time(NULL) - time1 ) < 5){
				
				if(sfRenderWindow_pollEvent(window, &event)){
				if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
				}
				}

			sfVector2f posPato = sfSprite_getPosition(pato);
			
			// movimiento del pato
			if(p1) {
			posPato.x = posPato.x ;
			posPato.y = posPato.y + 2;
			}
			if(!p1){	
            posPato.x = posPato.x + (drand48()* 15 +  1 - 7) ;
			posPato.y = posPato.y + (rand() % 10 +  1 - 5); 
			}

			// Para que no se salga de la pantalla
			if(posPato.x > sfRenderWindow_getSize(window).x && p1==false ) {
				posPato.x = 0;
			}
			if(posPato.y > (sfRenderWindow_getSize(window).y - 250) && p1==false) {
				posPato.y = 0;
			}

			//Se carga la mira 
			sfVector2f posMira;	
			posMira.x = sfMouse_getPosition(window).x;
			posMira.y = sfMouse_getPosition(window).y;
			sfSprite_setPosition(Mira, posMira);
			
		
			//Si se presiona el mouse
			if ((event.type == sfEvtMouseButtonPressed)) {
				 sfMusic_play(tiro);	
				
            // Se compara la posicion de la mira con la del pato
            if((posMira.x+25)>posPato.x  && (posPato.x + 76)>(posMira.x+25)){	
            if((posMira.y+25)>posPato.y  && (posPato.y + 62) >(posMira.y+25)){    
			
				sfSprite* patoX = patomuerto(pato, tPM1,tPM2,tPM3, tP1, tP2,tP3);
				sfMusic_play(hit);	
                p1=true;
                pato = patoX;
				}}
            }
			
			//Se imprime la imagen
			sfSprite_setPosition(pato, posPato);
			sfRenderWindow_drawSprite(window, bg, NULL);
			sfRenderWindow_drawSprite(window, pato, NULL);
			sfRenderWindow_drawSprite(window, Mira, NULL);
			sfRenderWindow_drawText(window, text6, NULL);
			sfRenderWindow_drawText(window, text7, NULL);
			sfRenderWindow_drawText(window, text8, NULL);
			sfRenderWindow_drawText(window, text9, NULL);
			sfRenderWindow_display(window);
        }
			if(p1){
				aciertos ++ ;
			}
			printf( "aciertos: %d  \n" ,  aciertos);
			
			int puntuacion = score( pato, tPM1, tPM2, tPM3, p1, Nivel);
			total= total + puntuacion;
			printf( "Score: %d  \n" ,  puntuacion);
			printf( "Total: %d  \n" ,  total);
	}
	
	// Si se cumplieron los aciertos, se pasa al siguiente nivel
	int Necesarios =aciertosN(Nivel);
	if(aciertos >= Necesarios){
	sigNivel = true;}
	else{
	sigNivel = false;}
	
	//Bonus de perfect
	if(aciertos == 10){
		total = total + bonus(Nivel);
	}
}	
		else{ 
					// Tiempo de espera(5 segundos)
			time_t  timeT = time(NULL);
			while( (time(NULL) - timeT) < 5){	
				if(sfRenderWindow_pollEvent(window, &event)){
				if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
				}
				}
				
			//Se crea el texto "Game Over"
			sfFont *style = sfFont_createFromFile("res/pd.ttf");
			sfText * textOver = sfText_create();
			sfText_setFont(textOver, style);
			sfText_setString(textOver, "Game Over");
			sfText_setCharacterSize(textOver, 100);
			sfVector2f  vO;
			vO= sfText_getPosition(textOver);
			vO.x=vO.x+300; vO.y=vO.y+150;
			sfText_setPosition(textOver, vO);
			
			//Se imprime la imagen
			sfRenderWindow_clear(window, sfBlack);
			sfRenderWindow_drawSprite(window, bg, NULL);
			sfRenderWindow_drawText(window, textOver, NULL);
			sfRenderWindow_display(window);
			}					
		
		return;
		}
}
	return;
}


// Opción de juego B : Dos patos por turno
void GameB(sfRenderWindow * window , sfSprite* bg , sfSprite* Mira , sfMusic* tiro ){
			sfEvent event;
			// Se inicia el juego
			int total= 0;
			bool sigNivel=true;
			sfMusic* hit = sfMusic_createFromFile("res/hit.ogg");
			sfMusic* music = sfMusic_createFromFile("res/music.ogg");

			 //Imagenes de los patos 
			sfTexture* tP1 = sfTexture_createFromFile("res/pato1.png", NULL);
			sfTexture* tP2 = sfTexture_createFromFile("res/pato2.png", NULL);
			sfTexture* tP3 = sfTexture_createFromFile("res/pato3.png", NULL);
			
			sfTexture* tPM1 = sfTexture_createFromFile("res/patoM1.png", NULL);
			sfTexture* tPM2 = sfTexture_createFromFile("res/patoM2.png", NULL);
			sfTexture* tPM3 = sfTexture_createFromFile("res/patoM3.png", NULL);		


		for( int Nivel = 1; Nivel < 6; Nivel++){
			if(sigNivel){	
			int aciertos = 0;
			sfMusic_play(music);	
			
			// Tiempo de espera(2 segundos)
			// Se indica el nivel en el que se encuentra
			time_t  timeT = time(NULL);
			while( (time(NULL) - timeT) < 2){	
				if(sfRenderWindow_pollEvent(window, &event)){
				if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
				}
				}
				
			//Se crea el texto "Level x"
			sfFont *style = sfFont_createFromFile("res/pd.ttf");
			sfText * textLevel = sfText_create();
			sfText_setFont(textLevel, style);
			
			char *  textN = itoa ( Nivel);
	
			sfText_setString(textLevel, textN);
			
			free(textN);
			
			sfText_setCharacterSize(textLevel, 100);
			sfVector2f  vL;
			vL= sfText_getPosition(textLevel);
			vL.x=vL.x+630; vL.y=vL.y+150;
			sfText_setPosition(textLevel, vL);
			
			sfText * text0L = sfText_create();
			sfText_setFont(text0L, style);
			sfText_setString(text0L, "Level");
			sfText_setCharacterSize(text0L, 100);
			sfVector2f  v0L;
			v0L= sfText_getPosition(text0L);
			v0L.x=v0L.x+350; v0L.y=v0L.y+150;
			sfText_setPosition(text0L, v0L);
			
			//Se carga la mira 
			sfVector2f posMira;		
			posMira.x = sfMouse_getPosition(window).x;
			posMira.y = sfMouse_getPosition(window).y;
			sfSprite_setPosition(Mira, posMira);
						
			//Se imprime la imagen
			sfRenderWindow_clear(window, sfBlack);
			sfRenderWindow_drawSprite(window, bg, NULL);
			sfRenderWindow_drawText(window, textLevel, NULL);
			sfRenderWindow_drawText(window, text0L, NULL);
			sfRenderWindow_drawSprite(window, Mira, NULL);
			sfRenderWindow_display(window);
			}			
			
			//Se empiezan los Rounds
			for(int i = 0; i < 5; i++){
			
			// Tiempo de espera (2 segundos)
			time_t  time1 = time(NULL);
			while( (time(NULL) - time1 ) < 2){	
				if(sfRenderWindow_pollEvent(window, &event)){
				if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
				}
				}
				
			// Se crea el texto "Round x"
			sfFont *style = sfFont_createFromFile("res/pd.ttf");
			sfText * text4 = sfText_create();
			sfText_setFont(text4, style);
			char *  textRound = itoa ( i + 1);
			sfText_setString(text4, textRound);
			free(textRound);
			
			sfText_setCharacterSize(text4, 100);
			sfVector2f  v4;
			v4= sfText_getPosition(text4);
			v4.x=v4.x+630; v4.y=v4.y+150;
			sfText_setPosition(text4, v4);
			
			sfText * text5 = sfText_create();
			sfText_setFont(text5, style);
			sfText_setString(text5, "Round");
			sfText_setCharacterSize(text5, 100);
			sfVector2f  v5;
			v5= sfText_getPosition(text5);
			v5.x=v5.x+350; v5.y=v5.y+150;
			sfText_setPosition(text5, v5);
	
			// Se carga la mira 
			sfVector2f posMira;		
			posMira.x = sfMouse_getPosition(window).x;
			posMira.y = sfMouse_getPosition(window).y;
			sfSprite_setPosition(Mira, posMira);
						
			// Se imprime la imagen
			sfRenderWindow_clear(window, sfBlack);
			sfRenderWindow_drawSprite(window, bg, NULL);
			sfRenderWindow_drawText(window, text4, NULL);
			sfRenderWindow_drawText(window, text5, NULL);
			sfRenderWindow_drawSprite(window, Mira, NULL);
			sfRenderWindow_display(window);
			}			
			
			// Se carga el color del pato aleatoriamente	
			sfSprite* pato1 = patoAleatorio(tP1,tP2, tP3);
			sfSprite* pato2 = patoAleatorio(tP1,tP2, tP3);


			sfVector2f posInicialPato1 = {0,100};
			sfVector2f posInicialPato2 = {0,300};
			sfSprite_setPosition( pato1,posInicialPato1);
			sfSprite_setPosition( pato2,posInicialPato2);
		
			// variables para el pato muerto
			bool p1=false;
			bool p2=false;

			// Se mueve el pato (5 segundos)
			time1 = time(NULL);
			while( (time(NULL) - time1 ) < 5){
				
				if(sfRenderWindow_pollEvent(window, &event)){
				if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
				}
				}
				
			sfVector2f posPato1 = sfSprite_getPosition(pato1);
			sfVector2f posPato2 = sfSprite_getPosition(pato2);

			// movimiento del pato
			if(p1==true) {
			posPato1.x = posPato1.x ;
			posPato1.y = posPato1.y + 2;
			}
			if(p1 == false){	
            posPato1.x = posPato1.x + (drand48()* 15 +  1 - 7) ;
			posPato1.y = posPato1.y + (rand() % 10 +  1 - 5) ; 
			}
			
			if(p2==true) {
			posPato2.x = posPato2.x ;
			posPato2.y = posPato2.y + 2;
			}
			if(p2 == false){		
            posPato2.x = posPato2.x + (drand48()* 15 +  1 - 7) ;
			posPato2.y = posPato2.y +  (rand() % 10 +  1 - 5) ;   
			}
						
			// Para que no se salga de la pantalla
			if(posPato1.x > sfRenderWindow_getSize(window).x && p1==false) {
				posPato1.x = 0;
			}
			if(posPato1.y > (sfRenderWindow_getSize(window).y - 250) && p1==false) {
				posPato1.y = 0;
			}

			if(posPato2.x > sfRenderWindow_getSize(window).x && p2==false) {
				posPato2.x = 0;
			}
			if(posPato2.y > (sfRenderWindow_getSize(window).y - 250) && p2==false) {
				posPato2.y = 0;
			}

			// Se carga la mira 
			sfVector2f posMira;	
			posMira.x = sfMouse_getPosition(window).x;
			posMira.y = sfMouse_getPosition(window).y;
			sfSprite_setPosition(Mira, posMira);
			
			// Si se presiona el mouse
			if (event.type == sfEvtMouseButtonPressed) {
				sfMusic_play(tiro);	
				
            // Se compara la posicion de la mira con la del pato
            if((posMira.x+25)>posPato1.x  && (posPato1.x + 76)>(posMira.x+25)){	
            if((posMira.y+25)>posPato1.y  && (posPato1.y + 62) >(posMira.y+25)){    
			
				sfSprite* patoM1 = patomuerto(pato1, tPM1,tPM2,tPM3, tP1, tP2,tP3);
				sfMusic_play(hit);	
                p1=true;
                pato1 = patoM1;
				}}
				
			if((posMira.x+25)>posPato2.x  && (posPato2.x + 76)>(posMira.x+25)){	
            if((posMira.y+25)>posPato2.y  && (posPato2.y + 62) >(posMira.y+25)){    
				sfSprite* patoM2 = patomuerto(pato2, tPM1,tPM2,tPM3, tP1, tP2,tP3);
				sfMusic_play(hit);	
                p2=true;
                pato2 = patoM2;
				}}
            }
			
			//Se crea el texto "Score: x"
			sfFont *style = sfFont_createFromFile("res/pd.ttf");
			sfText * text6 = sfText_create();
			sfText_setFont(text6, style);
			
			char *  textScore = itoa (total);
	
			sfText_setString(text6, textScore);
			
			free(textScore);
			
			sfText_setCharacterSize(text6, 20);
			sfVector2f  v6;
			v6= sfText_getPosition(text6);
			v6.x=v6.x+870; v6.y=v6.y +550;
			sfText_setPosition(text6, v6);
			
			sfText * text7 = sfText_create();
			sfText_setFont(text7, style);
			sfText_setString(text7, "Score: ");
			sfText_setCharacterSize(text7, 20);
			sfVector2f  v7;
			v7= sfText_getPosition(text7);
			v7.x=v7.x+800; v7.y=v7.y+550;
			sfText_setPosition(text7, v7);
			
			//Se crea el texto "Hits: x"
			sfText * text8 = sfText_create();
			sfText_setFont(text8, style);
			
			char *  textHits = itoa (aciertos);
	
			sfText_setString(text8, textHits);
			
			free(textHits);
			
			sfText_setCharacterSize(text8, 20);
			sfVector2f  v8;
			v8= sfText_getPosition(text8);
			v8.x=v8.x+870; v8.y=v8.y +520;
			sfText_setPosition(text8, v8);
			
			sfText * text9 = sfText_create();
			sfText_setFont(text9, style);
			sfText_setString(text9, "Hits: ");
			sfText_setCharacterSize(text9, 20);
			sfVector2f  v9;
			v9= sfText_getPosition(text9);
			v9.x=v9.x+800; v9.y=v9.y+520;
			sfText_setPosition(text9, v9);		

			// Se imprime la imagen
			sfSprite_setPosition(pato1, posPato1);
			sfSprite_setPosition(pato2, posPato2);
			sfRenderWindow_clear(window, sfBlack);
			sfRenderWindow_drawSprite(window, bg, NULL);
			sfRenderWindow_drawSprite(window, pato1, NULL);
			sfRenderWindow_drawSprite(window, pato2, NULL);
			sfRenderWindow_drawSprite(window, Mira, NULL);
			sfRenderWindow_drawText(window, text6, NULL);
			sfRenderWindow_drawText(window, text7, NULL);
			sfRenderWindow_drawText(window, text8, NULL);
			sfRenderWindow_drawText(window, text9, NULL);
			sfRenderWindow_display(window);
        }
			if(p1){
				aciertos ++ ;
			}
			
			if(p2){
				aciertos ++ ;
			}
			printf( "aciertos: %d  \n" ,  aciertos);
						
			int puntuacion1 = score( pato1, tPM1, tPM2, tPM3, p1, Nivel);
			int puntuacion2 = score( pato2, tPM1, tPM2, tPM3, p2, Nivel);
			total= total + puntuacion1 + puntuacion2;
			printf( "Score1: %d  \nScore2: %d  \n" ,  puntuacion1, puntuacion2);
			printf( "Total: %d  \n" ,  total);
			
		}
			
	// Si se cumplieron los aciertos, se pasa al siguiente nivel
	int Necesarios =aciertosN(Nivel);
	if(  Necesarios >= aciertos ){
		sigNivel = false;}
		
	//Bonus de perfect
	if(aciertos == 10){
		total = total + bonus(Nivel);}	
		
}
	else{
		
			sfMusic* GameOver = sfMusic_createFromFile("res/gameover.ogg"); 
			sfMusic_play(GameOver);
			
			// Tiempo de espera(5 segundos)
			time_t  timeT = time(NULL);
			while( (time(NULL) - timeT) < 5){	
				if(sfRenderWindow_pollEvent(window, &event)){
				if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
				}
				}
			
			//Se crea el texto "Game Over"
			sfFont *style = sfFont_createFromFile("res/pd.ttf");
			sfText * textOver = sfText_create();
			sfText_setFont(textOver, style);
			sfText_setString(textOver, "Game Over");
			sfText_setCharacterSize(textOver, 100);
			sfVector2f  vO;
			vO= sfText_getPosition(textOver);
			vO.x=vO.x+300; vO.y=vO.y+150;
			sfText_setPosition(textOver, vO);
			
			//Se imprime la imagen
			sfRenderWindow_clear(window, sfBlack);
			sfRenderWindow_drawSprite(window, bg, NULL);
			sfRenderWindow_drawText(window, textOver, NULL);
			sfRenderWindow_display(window);
			}					
		return;
	}	
}
	return;
}