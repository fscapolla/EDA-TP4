#pragma once
#include "Evento.h"
#include "Simulation.h"

class Dispatcher
{
public:
	Dispatcher();
	~Dispatcher();

	void dispatchEvent(Evento evento, Simulation *simPtr);
};

