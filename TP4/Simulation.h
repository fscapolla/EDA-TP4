#pragma once
#include "Worm.h"
#include "Graph.h"
#include "EventGen.h"
#include "Worm.h"
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>


class Simulation
{
public:
	Simulation();
	~Simulation();

	bool initSim(int width, int height);
	void assignKeys(void);

	//Setters
	void setWormNum(int wormNum_);
	void setWidth(int width_);
	void setHeigth(int heigth_);

	//Getters
	int getWormNum(void);
	int getWidth(void);
	int getHeight(void);

	//datos miembros.
	Worm *wormPtr[MAXWORMS];
	Graph *grapher;

private:
	int wormNum;
	int heigth;
	int width;

};
