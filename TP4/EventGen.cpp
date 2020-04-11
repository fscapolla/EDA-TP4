#include "EventGen.h"

using namespace std;


EventGen::EventGen(ALLEGRO_EVENT_QUEUE* Queue_, ALLEGRO_TIMER* timer_) {
	this->eventQueue = Queue_;
	this->timer = timer_;
}


bool EventGen::Init(double FPS)
{
	bool res = true;
	// Create event queue
	if (!(eventQueue = al_create_event_queue()))
	{
		cout << "Error al inicializar la cola de eventos de Alegro" << endl;
		res = false;
	}

	// Create timer and register it in queue
	this->timer = al_create_timer(1 / FPS);
	if (this->timer)
	{
		al_start_timer(timer);
		// Registro el timer en la queue
		al_register_event_source(this->eventQueue, al_get_timer_event_source(this->timer));
	}
	else {
		cout << "Error al crear el Timer" << endl;
		res = false;
	}
	return res;
}


EventGen::~EventGen()
{
	if (eventQueue)
		al_destroy_event_queue(eventQueue);
	if (timer)
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
	return evento;
}

bool EventGen::quitEvent(void)
{
	return false;
}

ALLEGRO_EVENT_QUEUE * EventGen::getQueue(void)
{
	return eventQueue;
}

ALLEGRO_EVENT_TYPE EventGen::getEvent(void)
{
	if (al_get_next_event(eventQueue, &alEvent))
		return alEvent.type;
	else
		return NULL;
}