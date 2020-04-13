#include "EventGen.h"

using namespace std;


EventGen::EventGen() {

	// CREO E INICIALIZO TIMER
	if (!(timer = al_create_timer(1.0 / FPS)))
		cout << "Error al inicializar timer de allegro" << endl;
	else
		al_start_timer(timer);

	// CREO E INICIALIZO COLA
	if (!(eventQueue = al_create_event_queue()))
		cout << "Error al inicializar la cola de eventos de Alegro" << endl;

	// Registro el timer en la queue
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	// FALTA REGISTRAR DISPLAY
	if (!al_install_keyboard())
		cout << "Error al inicializar el teclado" << endl;

	al_register_event_source(eventQueue, al_get_keyboard_event_source());

}

EventGen::~EventGen()
{
	if (eventQueue)
		al_destroy_event_queue(eventQueue);
	if (timer)
		al_destroy_timer(timer);
	// HACE FALTA DESTRUIR KEYBOARD ?
	
}

ALLEGRO_EVENT EventGen::getAllegroEvent(void) {
	return alEvent;
}

int EventGen::nextEvent(void) {
	int res = 1;
	if (!al_get_next_event(eventQueue, &alEvent))
		res = 0; // si no hay eventos no hace nada
	return res;
}
/*
eventos EventGen::getKey(ALLEGRO_EVENT* eventNow) {
	eventos eventType = NOTHING;
	if (eventNow->type == ALLEGRO_EVENT_KEY_UP) {
		switch (eventNow->keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			eventType = UP_ON;
			break;
		case ALLEGRO_KEY_LEFT:
			eventType = LEFT_ON;
			break;
		case ALLEGRO_KEY_RIGHT:
			eventType = RIGHT_ON;
			break;
		case ALLEGRO_KEY_W:
			eventType = W_ON;
			break;
		case ALLEGRO_KEY_A:
			eventType = A_ON;
			break;
		case ALLEGRO_KEY_D:
			eventType = D_ON;
			break;
		default:
			eventType = NOTHING;
			break;
		}
	}
	else if (eventNow->type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (eventNow->keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			eventType = UP_OFF;
			break;
		case ALLEGRO_KEY_LEFT:
			eventType = LEFT_OFF;
			break;
		case ALLEGRO_KEY_RIGHT:
			eventType = RIGHT_OFF;
			break;
		case ALLEGRO_KEY_W:
			eventType = W_OFF;
			break;
		case ALLEGRO_KEY_A:
			eventType = A_OFF;
			break;
		case ALLEGRO_KEY_D:
			eventType = D_OFF;
			break;
		default:
			eventType = NOTHING;
			break;
		}
	}
	return eventType;
}
*/


ALLEGRO_EVENT_QUEUE* EventGen::getQueue(void)
{
	return eventQueue;
}

void EventGen::dispatch(Simulation* simPtr) {
	switch (alEvent.type) {
	case ALLEGRO_KEY_UP:
		for (int i = 0; i < simPtr->getWormNum(); i++) {
			simPtr->wormPtr[i]->stopWorm(alEvent.keyboard.keycode);
		}
		break;
	case ALLEGRO_KEY_DOWN:
		for (int i = 0; i < simPtr->getWormNum(); i++) {
			simPtr->wormPtr[i]->moveWorm(alEvent.keyboard.keycode);
		}
		break;
	case ALLEGRO_EVENT_TIMER:
		for (int i = 0; i < simPtr->getWormNum(); i++) {
			simPtr->wormPtr[i]->updateWorm();
			simPtr->wormPtr[i]->refresh_worm();
		}
		break;
	}
}
