#include "Graph.h"
#include <iostream>
#include <string>
#include <allegro5/allegro_image.h>


using namespace std;

Graph::Graph()
{
}

Graph::Graph(int width, int height)
{
	display = NULL;
	background = NULL;
	error=!(setAllegro(width, height));
}


Graph::~Graph()
{
}

void Graph::update(Worm ** wormPtr, int wormNum)
{
}

bool Graph::getError(void)
{
	return error;
}



//Inicializa Allegro, el display, y el complemento de imágenes.
bool Graph::setAllegro(int width, int height)
{
	if (!al_init())										//Intenta inicializar Allegro
	{
		cout << "No es posible inicializar Allegro." << endl;
			return false;
	}

	if(!(display = al_create_display(width, height)));		//Crea display.
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

	al_flip_display();

	return true;
	

}
