#pragma once
#include "Worm.h"
#include "Graph.h"


class Simulation
{
public:
	Simulation();
	~Simulation();

	bool initSim(int width, int height);

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

