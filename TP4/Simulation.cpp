#include "Simulation.h"
#include <iostream>
#define P1_KEY_UP ALLEGRO_KEY_UP
#define P1_KEY_RIGHT ALLEGRO_KEY_RIGHT
#define P1_KEY_LEFT ALLEGRO_KEY_LEFT
#define P2_KEY_UP ALLEGRO_KEY_W
#define P2_KEY_RIGHT ALLEGRO_KEY_D
#define P2_KEY_LEFT ALLEGRO_KEY_A


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
	delete this->grapher;
}

bool Simulation::initSim(int width, int height)	//Inicializa a los worms y al objeto gr�fico.
{
	int res = true;
	for (int i = 0; i < /*wormNum*/ 2; i++)
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

void Simulation::assignKeys(void)
{
	int walkKeys[] = { P1_KEY_RIGHT,P1_KEY_LEFT,P2_KEY_RIGHT,P2_KEY_LEFT };
	int jumpKeys[] = { P1_KEY_UP, NULL, P2_KEY_UP };

	for (int i = 0; i <= (wormNum+1); i=i+2)
	{
		wormPtr[i]->setWormKeys(jumpKeys[i], walkKeys[i], walkKeys[i + 1]);
	}
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
