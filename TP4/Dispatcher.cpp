#include "Dispatcher.h"



Dispatcher::Dispatcher()
{
}


Dispatcher::~Dispatcher()
{
}


/*


void Dispatcher::dispatchEvent(Evento evento, Simulation *simPtr)
{
	event_type = evento.getType();
	switch (eventType)
	{
	case KEYDOWN:KEYUP:
	for (int i = 0; i < wormNum; i++)
	{
		wormPtr[i]->updateWorm(event_type);
	}
	break;

	case TIMER:
		for (int i = 0; i < wormNum; i++)
		{
			wormPtr[i]->updateWorm(event_type);
			grapher->updateGrapher(wormPtr, wormNum);
		}

	default:
		break;
	}
}


void dispatch(Event ev, int wormCount, Worm * wArray[], Grapher * grapher)
{
	switch (ev.get_event_type())
	{
	case POSSIBLE_WORM_MOVE:
	case POSSIBLE_WORM_STOP:
		for (int i = 0; i < wormCount; i++)		//Itera todos los worms
		{
			wormPtr[i]->update(ev);				//Actualiza propiedades de cada Worm
		}
		break;

	case REFRESH:
		for (int i = 0; i < wormCount; i++)		//Itera todos los worms
		{
			wormPtr[i]->update(ev);				//increment frameCount of worm.
			grapher->update(wArray, wormCount);	//Actualiza el display con la informacion de cada Worm
		}
		break;

	default:
		break;
	}
}

*/