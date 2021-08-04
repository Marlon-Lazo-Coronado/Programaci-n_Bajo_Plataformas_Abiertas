#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <stdbool.h>

char * itoa(int i) ;
sfSprite* patoAleatorio(sfTexture* tP1,sfTexture* tP2, sfTexture* tP3);
int score(sfSprite* pato, sfTexture* tPM1,sfTexture* tPM2, sfTexture* tPM3, bool p1, int nivel);
int aciertosN(int nivel);
 int bonus(nivel);
sfSprite* patomuerto(sfSprite* pato, sfTexture* tPM1,sfTexture* tPM2,sfTexture* tPM3, sfTexture* tP1,sfTexture* tP2,sfTexture* tP3);
void GameA(sfRenderWindow * window , sfSprite* bg , sfSprite* Mira , sfMusic* tiro );
void GameB(sfRenderWindow * window , sfSprite* bg , sfSprite* Mira , sfMusic* tiro );

#endif
