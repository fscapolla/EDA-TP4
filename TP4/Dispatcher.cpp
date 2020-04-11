#include "Dispatcher.h"



Dispatcher::Dispatcher()
{
}


Dispatcher::~Dispatcher()
{
}





void Dispatcher::dispatchEvent(Evento * evento, Simulation *simPtr)
{
	int eventType = evento->getType();
	switch (eventType)
	{
	case ALLEGRO_EVENT_KEY_DOWN:
		for (int i = 0; i < simPtr->getWormNum(); i++)
		{
			simPtr->wormPtr[i]->updateWorm(evento);
		}
	break;

	case ALLEGRO_EVENT_KEY_UP:
		for (int i = 0; i < simPtr->getWormNum; i++)
		{
			simPtr->wormPtr[i]->stopWorm();
		}
		break;

	case ALLEGRO_EVENT_TIMER:
		for (int i = 0; i < simPtr->getWormNum(); i++)
		{
			simPtr->wormPtr[i]->updateWorm(evento);
			simPtr->grapher->updateGrapher(simPtr->wormPtr, simPtr->getWormNum());
		}
		break;

	default:
		break;
	}
}