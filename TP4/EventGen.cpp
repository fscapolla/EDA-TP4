#include "EventGen.h"

using namespace std;


EventGen::EventGen()
{
	eventQueue = NULL;
	timer = NULL;
	if (!(eventQueue = al_create_event_queue()))
	{
		cout << "Error al inicializar la cola de eventos de Alegro" << endl;
	}

	//Habría que crear timer más keyboard me parece
}


EventGen::~EventGen()
{
	al_destroy_event_queue(eventQueue);
	al_destroy_timer(timer);
}


bool EventGen::newEvent(void)
{
	if (!(al_event_queue_is_empty(eventQueue))){
		return true;
	}
	else {
		return false;
	}
}

Evento EventGen::nextEvent(void)
{
}

bool EventGen::quitEvent(void)
{
}

ALLEGRO_EVENT_QUEUE * EventGen::getQueue(void)
{
	return eventQueue;
}

Evento * EventGen::getEvent(void)
{
	return evento;
}

