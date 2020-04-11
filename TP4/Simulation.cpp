#include "Simulation.h"
#include <iostream>
#include "Graph.h"
#include "EventGen.h"
#include "Worm.h"

using namespace std;


Simulation::Simulation()		//Constructor de Simulation.
{
	Graph * grapher = nullptr;
	int wormNum = PLAYERWORMS;
	for (int i = 0; i < wormNum; i++)
	{
		wormPtr[i] = nullptr;
	}
}

Simulation::~Simulation()	//Destructor
{
}

bool Simulation::initSim(int width, int height)	//Inicializa a los worms y al objeto gráfico.
{
	int res = true;
	for (int i = 0; i < wormNum; i++)
	{
		wormPtr[i] = new (nothrow) Worm();
		if (wormPtr[i] == nullptr)
			res = false;
	}

	grapher = new(nothrow) Graph(width, height);
	grapher->init();
	if (grapher == nullptr)
		res = false;
	if (grapher->getError())
		res = false;

	return res;
}


//Setters
void Simulation::setWormNum(int wormNum_)
{
	wormNum = wormNum_;
}

void Simulation::setWidth(int width_)
{
	width = width_;
}

void Simulation::setHeigth(int heigth_)
{
	heigth = heigth_;
}


//Getters
int Simulation::getWormNum(void)
{
	return wormNum;
}

int Simulation::getWidth(void)
{
	return width;
}

int Simulation::getHeight(void)
{
	return heigth;
}
