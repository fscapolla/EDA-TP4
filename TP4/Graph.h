#pragma once
#include <allegro5/allegro.h>
#include "Worm.h"
#define BACKGROUND "Scenario.png"
#define WALKINGFRAMES 15
#define JUMPINGFRAMES 10
#define DEFAULT_DISPLAY_WIDTH 700
#define DEFAULT_DISPLAY_HEIGHT 700


class Graph
{
public:
	Graph();
	Graph(
		int width = DEFAULT_DISPLAY_WIDTH,
		int height = DEFAULT_DISPLAY_HEIGHT,
		ALLEGRO_DISPLAY* display = nullptr,
		ALLEGRO_BITMAP* background = nullptr
	);
	~Graph();

	void init(void);

	void update(Worm **wormPtr, int wormNum);	//Actualiza el display.

	//Getters
	bool getError(void);

	ALLEGRO_DISPLAY* getDisplay(void);

	void test(unsigned int posX, unsigned int posY, unsigned int frame, char what);

private:
	ALLEGRO_DISPLAY * display;							//Display.
	ALLEGRO_BITMAP  * background;						//Imagen de fondo.
	ALLEGRO_BITMAP * walkingFrames[WALKINGFRAMES];		//Imágenes de 'worm walk'.
	ALLEGRO_BITMAP * jumpingFrames[JUMPINGFRAMES];		//Imágenes de 'worm jump'.

	bool setAllegro(int width, int height, ALLEGRO_DISPLAY*& display);
	bool setImages();

	unsigned int width;
	unsigned int height;

	bool error;		//vale 1 si hubo error de Allegro, en caso contrario cero.

};

