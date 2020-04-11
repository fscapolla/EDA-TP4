#pragma once
#include <allegro5/allegro.h>
#include "Worm.h"
#define BACKGROUND "Scenario.png"
#define WALKINGFRAMES 15
#define JUMPINGFRAMES 10



class Graph
{
public:
	Graph();
	Graph(int width, int height);
	~Graph();

	void updateGrapher(Worm **wormPtr, int wormNum);	//Actualiza el display.


	//Getters
	bool getError(void);

private:
	ALLEGRO_DISPLAY * display;							//Display.
	ALLEGRO_BITMAP  * background;						//Imagen de fondo.
	ALLEGRO_BITMAP * walkingFrames[WALKINGFRAMES];		//Imágenes de 'worm walk'.
	ALLEGRO_BITMAP * jumpingFrames[JUMPINGFRAMES];		//Imágenes de 'worm jump'.

	bool setAllegro(int width, int height);
	bool setImages();

	bool error;		//vale 1 si hubo error de Allegro, en caso contrario cero.

};

