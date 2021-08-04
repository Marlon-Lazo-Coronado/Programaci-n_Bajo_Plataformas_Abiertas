#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <stdbool.h>

#include "./funciones.h"

void main()
{
	// Se crea la ventana 
    sfVideoMode mode = {1000, 600, 32};
    sfRenderWindow * window = sfRenderWindow_create(mode, "Duck Hunt", sfResize | sfClose, NULL);

	//Se crea el texto "Duck Hunt"
    sfFont *style = sfFont_createFromFile("res/pd.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, style);
    sfText_setString(text, "Duck Hunt");
	sfText_setColor(text, sfWhite );
    sfText_setCharacterSize(text, 200);
	sfVector2f  v;
	v = sfText_getPosition(text);
	v.x=v.x+70;
	v.y=v.y+10;
	sfText_setPosition(text, v);

	//
	sfText *text6 = sfText_create();
    sfText_setFont(text6, style);
    sfText_setString(text6, "___________" );
	sfText_setColor(text6, sfBlue);
    sfText_setCharacterSize(text6, 142);
	sfVector2f  v6;
	v6.x=75; v6.y=70;
	sfText_setPosition(text6, v6);

	//Se crea el texto "Game A"	
	sfText *text2 = sfText_create();
    sfText_setFont(text2, style);
    sfText_setString(text2, "Game A" );
	sfText_setColor(text2, sfWhite);
    sfText_setCharacterSize(text2, 60);
	sfVector2f  v2;
	v2.x=200; v2.y=300;
	sfText_setPosition(text2, v2);
	
	sfText *text02 = sfText_create();
    sfText_setFont(text02, style);
    sfText_setString(text02, "(press key A)");
	sfText_setColor(text02, sfCyan);
    sfText_setCharacterSize(text02, 25);
	sfVector2f  v02;
	v02.x=400; v02.y=325;
	sfText_setPosition(text02, v02);
	
	//Se crea el texto "Game B"		
	sfText *text3 = sfText_create();
    sfText_setFont(text3, style);
    sfText_setString(text3, "Game B ");
	sfText_setColor(text3, sfWhite);
    sfText_setCharacterSize(text3, 60);
	sfVector2f  v3;
	v3.x=200; v3.y=400;
	sfText_setPosition(text3, v3);
	
	sfText *text03 = sfText_create();
    sfText_setFont(text03, style);
    sfText_setString(text03, "(press key B)");
	sfText_setColor(text03, sfCyan);
    sfText_setCharacterSize(text03, 25);
	sfVector2f  v03;
	v03.x=400; v03.y=425;
	sfText_setPosition(text03, v03);
	
	// Se carga la imagen de fondo
	sfVector2f V;
    sfSprite* bg = sfSprite_create();
    sfTexture* _t = sfTexture_createFromFile("res/background.jpg", NULL);
    sfSprite_setTexture(bg, _t, sfTrue);
    float _x  = (float)sfTexture_getSize(_t).x;
    float _y  = (float)sfTexture_getSize(_t).y;
    V = (sfVector2f){sfRenderWindow_getSize(window).x/_x, sfRenderWindow_getSize(window).y/_y};
    sfSprite_setScale(bg, V);
	
	// Se carga la imagen de la mira
	sfSprite* Mira = sfSprite_create();
    sfSprite_setTexture(Mira, sfTexture_createFromFile("res/mira.png", NULL), sfTrue);
    V = (sfVector2f){0.8, 0.8};
    sfSprite_scale(Mira, V);

	// Se carga la música
	sfMusic* tiro = sfMusic_createFromFile("res/tiro.ogg");
	sfMusic* title = sfMusic_createFromFile("res/title.ogg");
	
	// Se empieza el evento
    sfEvent event;
	sfMusic_play(title);	

    while (sfRenderWindow_isOpen(window))
    {
			// Se esconde el cursor
			sfRenderWindow_setMouseCursorVisible(window, sfFalse);
			
        while (sfRenderWindow_pollEvent(window, &event))
        {	
			// Se sale si se presiona la X
            if (event.type == sfEvtClosed)
            {
                printf("cerrando ventana\n");
                sfRenderWindow_close(window);
            }
			
			//  Se crea la opción Game A (solo un pato)
            if (event.key.code == sfKeyA)
            {
          	sfMusic_pause(title);
			 printf("Game A\n");

			//Suena la musica
			GameA( window ,  bg , Mira ,  tiro );
			}
	
			//  Se crea la opción Game B (dos patos)
            if (event.key.code == sfKeyB)
            {
                printf("Game B\n");
			//Suena la musica
			sfMusic_pause(title);
			GameB( window ,  bg , Mira ,  tiro );
            }
			
		}
   
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, text, NULL);
		sfRenderWindow_drawText(window, text2, NULL);
		sfRenderWindow_drawText(window, text3, NULL);
		sfRenderWindow_drawText(window, text02, NULL);
		sfRenderWindow_drawText(window, text03, NULL);
		sfRenderWindow_drawText(window, text6, NULL);
        sfRenderWindow_display(window);
		
    }
    return ;
}