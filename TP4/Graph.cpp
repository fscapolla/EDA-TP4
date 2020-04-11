#include "Graph.h"
#include <iostream>
#include <string>
#include <allegro5/allegro_image.h>


using namespace std;

Graph::Graph()
{
}

Graph::Graph(int width, int height, ALLEGRO_DISPLAY* display, ALLEGRO_BITMAP* background)
{
	this->display = display;
	this->background = background;
	this->width = width;
	this->height = height;
}

void Graph::init(void) {
	this->error = !setAllegro(this->width, this->height, display);
	this->error = !setImages();
	al_flip_display();
}


Graph::~Graph()
{
	if (display)
		al_destroy_display(display);
	/*if (background)
		al_destroy_bitmap(background);
	for(int i=0; i < WALKINGFRAMES; i++) {
		if (walkingFrames[i]) {
			al_destroy_bitmap(walkingFrames[i]);
		}
	}
	for (int i = 0; i < JUMPINGFRAMES; i++) {
		if (jumpingFrames[i]) {
			al_destroy_bitmap(jumpingFrames[i]);
		}
	}
	*/
}

void Graph::update(Worm ** wormPtr, int wormNum)
{
}

bool Graph::getError(void)
{
	return error;
}



//Inicializa Allegro, el display, y el complemento de imágenes.
bool Graph::setAllegro(int width, int height, ALLEGRO_DISPLAY*& display)
{
	if (!al_init())										//Intenta inicializar Allegro
	{
		cout << "No es posible inicializar Allegro." << endl;
		return false;
	}
	display = al_create_display(width, height);
	if (!display)		//Crea display.
	{
		cout << "No es posible inicializar el display." << endl;
		return false;
	}

	if (!(al_init_image_addon()))			//Inicializa image addon.
	{
		cout << "No es posible inicializar el complemento de imágenes" << endl;
		return false;
	}
	return true;
}



bool Graph::setImages()
{
	bool res = true;
	string walkingFile = "wwalk-F";
	string jumpingFile = "wjump-F";
	string png = ".png";
	string image;

	for (int i = 1; i <= WALKINGFRAMES; i++)
	{
		image = walkingFile + to_string(i) + png;				//Se forma el path correspondiente a cada imagen.
		walkingFrames[i - 1] = al_load_bitmap(image.c_str());		//Se carga cada imagen
		if (!walkingFrames[i - 1])										//Chequea error
			return false;
	}

	for (int j = 1; j <= JUMPINGFRAMES; j++)
	{
		image = jumpingFile + to_string(j) + png;					//Se forma el path correspondiente a cada imagen.
		jumpingFrames[j - 1] = al_load_bitmap(image.c_str());	//Se carga cada imagen
		if (!jumpingFrames[j - 1])										//Chequea error
			return false;
	}


	background = al_load_bitmap("Scenario.png");	//Se carga el fondo
	if (!background)								//Chequea error
		return false;

	al_draw_bitmap(background, 0, 0, 0);			//Se dibuja el fondo.

	return true;
}

ALLEGRO_DISPLAY* Graph::getDisplay(void) {
	return this->display;
}

void Graph::test(unsigned int posX, unsigned int posY, unsigned int frame, char what) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_set_target_backbuffer(getDisplay());
	al_draw_bitmap(background, 0, 0, 0);
	if(what=='W')
		al_draw_bitmap(walkingFrames[frame], posX, posY, 0);
	else
		al_draw_bitmap(jumpingFrames[frame], posX, posY, 0);

}
