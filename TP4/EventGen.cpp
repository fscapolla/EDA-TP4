#include "EventGen.h"

using namespace std;


EventGen::EventGen()
{
	eventQueue = al_create_event_queue();
	timer = al_create_timer(1/FPS);
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

ALLEGRO_EVENT* EventGen::nextEvent(void)
{
	ALLEGRO_EVENT* ev;
	al_get_next_event(eventQueue, &ev);
	return ev;
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

