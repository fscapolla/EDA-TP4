#pragma once
#include "Evento.h"
#include "Simulation.h"
#include <allegro5/allegro.h>

class Dispatcher
{
public:
	Dispatcher();
	~Dispatcher();

	void dispatchEvent(Evento * evento, Simulation *simPtr);
};

